#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string const patientFileName = "patientFile.txt";
int const PATIENT_MAX = 100;
int const TEMP_READINGS = 4;
//int const patientAttribs = 6;

struct Patient {
	string lastName;
	string firstName;
	float temps[TEMP_READINGS];
};

// Converts a line of text into a Patient struct.
// - Will fail horribly if 'line' does not have exactly six space-delimited tokens (words).
Patient parsePatientText(string line) {
	printf("Parsing line: '%s'...\n", line.c_str());

	// Create a stream wrapper for our input string so that we can parse through it:
	std::istringstream iss(line);
	
	// Allocate a spot for a Patient struct, our eventual return value:
	Patient patient;

	// Take the first two tokens (words) from our input string and store them in our Patient struct:
	getline(iss, patient.firstName, ' ');
	getline(iss, patient.lastName, ' ');

	// Take the next four tokens, convert them to floats, then store in our struct:
	for (int t = 0; t < TEMP_READINGS; t++) {
		string temp_str;
		getline(iss, temp_str, ' ');
		patient.temps[t] = stof(temp_str);
	}

	// All done, return our struct:
	return patient;
}

// Reads the entire patient file and stores each in the 'patients' array.
void readPatientFile(Patient patients[], int& numPatients) {
	string line;
	ifstream patientFile;

	patientFile.open(patientFileName);

	if (patientFile.is_open()) {
		// Read each line of text:
		while (getline(patientFile, line)) {
			// Make sure we haven't exceeded the bounds of our array:
			if (numPatients >= PATIENT_MAX)
				throw new range_error("Too many patients!");

			//// [DEBUG] Print each line of our patients file:
			//cout << "Patient " << numPatients << ": " << line << endl;

			// Parse each line into our 'database' of patients:
			patients[numPatients] = parsePatientText(line);

			numPatients++;
		}

		// Close file handle:
		patientFile.close();
	} else {
		// TODO: Handle file opening error.
	}
}

// Prints the entire array of patients.
void printPatients(Patient patients[], int numPatients) {
	printf("\nPrinting patients...\n");

	for (int p = 0; p < numPatients; p++) {
		// Print first and last name:
		cout << patients[p].firstName << " " << patients[p].lastName;

		// Print temperature readings:
		for (int t = 0; t < TEMP_READINGS; t++) {
			cout << " " << patients[p].temps[t];
		}

		cout << endl;
	}
}

int checkTemps(Patient patients[], int numPatients, string n, float& average) {
	return 0;
}

int main() {
	int numPatients = 0;
	int average = 0;
	Patient* patients = new Patient[PATIENT_MAX];

	// Parse each line of our text file, 'patientFileName', into 'patients' and the number of lines
	// into 'numPatients':
	readPatientFile(patients, numPatients);
	printPatients(patients, numPatients);

	// Print number of patients:
	cout << endl << "Number of patients found in '" << patientFileName << "': " << numPatients << endl;
	
	// Wait for 'Enter' to be pressed before exiting:
	cout << "Press 'Enter' to close...";
	getchar();
	return 0;
}