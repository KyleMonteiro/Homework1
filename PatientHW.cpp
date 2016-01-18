#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct Patient {
	string lastName;
	string firstName;
	float temps[4];
};

void readPatientFile(Patient p[], int& c) {


}

void printPatients(Patient p[], int c) {


}

int checkTemps(Patient p[], int c, string n, float& average) {

	return 0;
}

int main() {

	int numPatients = 8;
	int average;

	/*
	string line;

	ifstream patientFile;
	patientFile.open("patientFile.txt");
	if (patientFile.is_open()) {

		while (getline(patientFile,line)) {
			numPatients++;
			cout << numPatients << endl;
		}
		patientFile.close();
	}

	int arraySize = numPatients;

	//cout << numPatients << endl;

	*/

	Patient patientInfo[8];

	readPatientFile(Patient patientInfo[8], numPatients);



	return 0;
}