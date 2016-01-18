#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct Patient {
	string lastName;
	string firstName;
	float temps[4];
};

void

int main() {

	int numPatients = 0;
	int average;
	string line;

	ifstream patientFile;
	patientFile.open("patientFile.txt");
	if (patientFile.is_open()) {

		while (getline(patientFile,line)) {
			numPatients++;
			//cout << numPatients << endl;
		}
		patientFile.close();
	}

	int arraySize = numPatients;

	//cout << numPatients << endl;

	Patient p[] = { ar };



	return 0;
}