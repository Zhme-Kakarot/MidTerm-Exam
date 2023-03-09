#include <iostream>
#include <fstream>
#include <string>

#include "Shape.h"

using namespace std;

void readData();

int main() {

	readData();

	return 0;
}

void readData() {

	int fileData[3][5];

	ifstream inFile;
	ofstream outFile;

	cout << "File opening..." << endl;

	try {

		inFile.open("inputData.txt");


		while (!inFile.eof()) {
			for (int j = 0; j < 5; j++) {
				for (int i = 0; i < 3; i++) {

					inFile >> fileData[i][j];
				}
			}
		}

		cout << "File has been parsed! " << endl;
		inFile.close();

	}
	catch (Shape::ExceptionFifty e) {
		cout << e.value << ": That value is forbidden ..." << endl;
	}

	int x, y, z;
	double rPer, rArea, cPer, cArea;
	try {

		outFile.open("answers.txt");

		for (int j = 0; j < 5; j++) {
			x = fileData[0][j];
			y = fileData[1][j];
			z = fileData[2][j];

			cout << x << " " << y << " " << z << endl;

			Rectangle tempRect = Rectangle(x, y, z);
			Circle tempCircle = Circle(x, y, z);

			cout << tempCircle << endl;
			cout << tempRect << endl;

			outFile << tempRect.getPerimeter() << " " << tempRect.getArea() << endl
				<< tempCircle.getPerimeter() << " " << tempCircle.getArea() << endl << endl;

		}

		outFile.close();
	}
	catch (Shape::CalcFailure e) {
		cout << "Failed" << endl;
	}

}