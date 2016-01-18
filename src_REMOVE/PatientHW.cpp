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
	patientFile.open("patientFile.txt");

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
	int numPatients = 0;
	int average;

	Patient* patientInfo = new Patient[8];

	readPatientFile(patientInfo, numPatients);

	//printPatientFile(patientInfo, numPatients);

	cout << numPatients << endl;
	return 0;
}
