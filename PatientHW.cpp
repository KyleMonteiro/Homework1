#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <iomanip>
using namespace std;

int const PATIENT_MAX = 100;
int const TEMP_READINGS = 4;

struct Patient {
	string lastName;
	string firstName;
	float temps[TEMP_READINGS];
};

Patient parsePatientText(string line) {
	
	std::istringstream iss(line);

	Patient patient;

	getline(iss, patient.lastName, ' ');
	getline(iss, patient.firstName, ' ');

	for (int t = 0; t < TEMP_READINGS; t++) {
		string temp_str;
		getline(iss, temp_str, ' ');
		patient.temps[t] = stof(temp_str);
	}

	return patient;
}


void readPatientFile(Patient patientInfo[], int& numPatients) {

	string line;

	ifstream patientFile;
	patientFile.open("patientFile.txt");
	if (patientFile.is_open()) {
		while (getline(patientFile, line)) {

			patientInfo[numPatients] = parsePatientText(line);

			numPatients++;
		}
		patientFile.close();
	}
	//cout << patientInfo[7].lastName << endl;	
}

void printPatientFile(Patient patientInfo[], int numPatients) {

	for (int i = 0;i < numPatients; i++) {

		cout << patientInfo[i].firstName << " " << patientInfo[i].lastName << " " << endl;
	}
}

int checkTemps(Patient patientInfo[], int numPatients, string userSelection, float& average) {

	float sum_total = 0;

	for (int i = 0; i < numPatients; i++) {
		if (userSelection == patientInfo[i].lastName) {
			for (int il = 0; il < TEMP_READINGS;il++) {
				sum_total = sum_total + patientInfo[i].temps[il];
			}
		} //else if ((i == (numPatients - 1)) && (userSelection != patientInfo[i].lastName)) {

			//cout << "Last name didn't match any patient record, please enter a valid patient." << endl;
			//sum_total = 2; //2 Is an ErrorFlag.
			//average = sum_total;
				//return average;
		//} 
	}
	average = (sum_total / (float)(TEMP_READINGS));
	return average;
}

int main() {

	string userSelection = ("none");
	int numPatients = 0;
	float ErrorLevel = 2;
	Patient* patientInfo = new Patient[PATIENT_MAX];

	readPatientFile(patientInfo, numPatients);

	printPatientFile(patientInfo, numPatients);
	
	//cout << patientInfo[6].temps[2] << endl;

	cout << "Please enter ""stop"" whenever you wish to terminate the program" << endl;

	while (userSelection != "stop") {

		float average = 0;

		cout << "Please enter the last name of the patient you want to check (Case Sensitive): " << endl;
		cin >> userSelection;
		if (userSelection == "stop") {
			return 0;
		}

		average = checkTemps(patientInfo, numPatients, userSelection, average);

		if (average == ErrorLevel) {
			return 0;
		} else {
			cout << setprecision(2) << fixed;
			cout << "The average temperature reading for " << userSelection << " is: " << average << endl;
		}
	} 
	return 0;
}