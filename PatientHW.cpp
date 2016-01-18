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

	string line;

	ifstream patientFile;
	patientFile.open("patientFile.txt");
	if (patientFile.is_open()) {

		while (getline(patientFile, line)) {
			c++;
			}
			/*for (int i = 0; i < c; i++) {
				patientFile >> p[i];
			}
			patientFile.close();
		}

		cout << p[1] << endl;*/
	}
}

/*void printPatientFile(Patient p[], int c) {

	for (int i = 0;i < c; i++) {

		cout << p[i].firstName << " " << p[i].lastName << endl;

	}


}*/

/*int checkTemps(Patient p[], int c, string n, float& average) {

	return 0;
}*/

int main() {

	int numPatients = 0;
	int average;

	Patient* patientInfo = (Patient*)malloc(8);

	readPatientFile(patientInfo, numPatients);

	//printPatientFile(patientInfo, numPatients);
	return 0;
}