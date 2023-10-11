#include <fstream>
#include <iostream>
using namespace std;

void writeSumNNumbers(string inputFileName, string outputFileName, int quantityOfNumbers, char writeMode) {
	ifstream inputFile;
	ofstream outputFile;
	int temp = 0;

	inputFile.open(inputFileName);
	if (writeMode == 'a') {// if its append
		outputFile.open(outputFileName, ios::app);//append mode
	}
	else
		outputFile.open(outputFileName);//full write	

	for (int i = 1; i <= quantityOfNumbers; i++) {
		inputFile >> temp;
		if (inputFile.fail()) {
			cout << "File not found\n";
			inputFile.clear();
		}
		else
			temp += temp;
	}
	outputFile << temp;//write the value
	
	inputFile.close();
	outputFile.close();
}

int main() {

	/*Reads three numbers from the file
		infile.dat, sums the numbers
		//and writes the sum to the file
		outfile.dat.
	*/
	ifstream inStream;
	ofstream outStream;
	
	writeSumNNumbers("infile.dat", "outfile.dat", 3, 'a');

	return 0;
}
