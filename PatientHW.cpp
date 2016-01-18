#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct Patient {
	string lastName;
	string firstName;
	float temps[4];
};

int main() {

	int numPatients = 0;
	int average;

	ifstream patientFile;
	patientFile.open("patientFile.txt");
	if (patientFile.is_open()) {

		while (!patientFile.eof()) {
			numPatients++;
			cout << numPatients << endl;
		}
		patientFile.close();
	}

	cout << numPatients << endl;

	return 0;
}