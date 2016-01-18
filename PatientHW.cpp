#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct Patient {
	string lastName;
	string firstName;
	float temps[4];
};

void readPatientFile(Patient patientInfo[], int& numPatients) {
	string line;
	ifstream patientFile;

	patientFile.open(patientFileName);

	if (patientFile.is_open()) {
		while (getline(patientFile, line)) {
			numPatients++;
		}

		for (int i = 0; i < numPatients; i++) {
			getline(patientFile, line);
			cout << line << endl;
		}

		patientFile.close();
	}
}

//void printPatientFile(Patient patientInfo[], int numPatients) {
//	for (int i = 0;i < numPatients; i++) {
//		cout << patientInfo[i].firstName << " " << patientInfo[i].lastName << endl;
//	}
//}

/*int checkTemps(Patient patientInfo[], int numPatients, string n, float& average) {
	return 0;
}*/

int main() {
	string const patientFileName = "patientFile.txt";
	int const maxPatients = 100;

	int numPatients = 0;
	int average = 0;
	Patient* patientInfo = new Patient[maxPatients];

	// Parse each line of our text file, 'patientFileName', into 'patientInfo' and the number of lines
	// into 'numPatients':
	readPatientFile(patientInfo, numPatients);
	//printPatientFile(patientInfo, numPatients);

	// Print number of patients:
	cout << "Number of patients found in '" << patientFileName << "': " << numPatients << endl;
	
	// Wait for 'Enter' to be pressed before exiting:
	//printf("Press 'Enter' to close this damn window...");
	cout << "Press 'Enter' to close this damn window...";
	getchar();
	return 0;
}
