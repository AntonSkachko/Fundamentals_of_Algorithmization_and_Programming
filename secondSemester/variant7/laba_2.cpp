#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <climits>
using namespace std;

struct Sportsman {
	string fullName;
	int gameNumber;
	int age;
	int height;
	int weight;
	string country;
	string teamName;
};

void functionSelection(string fileName, int& size, Sportsman* arrayOfSportsman);

// работа с файлом
Sportsman* resizeArray(int& oldSize, int newSize, Sportsman* arrayOfSportsman);
Sportsman* readFile(string fileName, int& size);
void printArray(Sportsman* arrayOfSportsman, int size);
void writeInFile(string fileName, int &size);

void createFile(string& fileName);
// линейный поиск и бинарный поиск
void linearSearchToArray(Sportsman* arrayOfSportsman, int size);
void binarySearchInSortedArray();

// сортировка методами прямого выбора и QuickSort
void SelectionSort(Sportsman* arrayOfSportsman, int size); 
void sortByQuickSort();



int main() {
	int size = 1;
	string fileName = "informationAboutSportsman.txt";
	Sportsman* arrayOfSportsman = readFile(fileName, size);
	functionSelection(fileName, size, arrayOfSportsman);
	delete[] arrayOfSportsman;
	return 0;
}

void createFile(string& fileName) {
	cout << "Enter name of file: "; cin >> fileName;
	ifstream file;
	file.open(fileName);
	if (!file.is_open()) {
		return;
	}
}


Sportsman* resizeArray(int& oldSize, int newSize, Sportsman* arrayOfSportsman) {
	if (oldSize == newSize) {
		return arrayOfSportsman;
	}
	Sportsman* newArray = new Sportsman[newSize];
	oldSize = newSize < oldSize ? newSize : oldSize;
	for (int i = 0; i < oldSize; i++) {
		newArray[i] = arrayOfSportsman[i];
	}
	oldSize = newSize;
	delete[] arrayOfSportsman;
	return newArray;
}

Sportsman* readFile(string fileName, int& size) {
	ifstream file;
	file.open(fileName);
	if (!file.is_open()) {
		return nullptr;
	}
	else {
		size <= 0 ? size = 10 : size = size;
		Sportsman* arrayOfSportsman = new Sportsman[size];
		int numberOfLines = 0;
		while (!file.eof()) {

			// если количество линий равно размеру массива => нужно увеличить масив
			if (numberOfLines == size){ 
				arrayOfSportsman = resizeArray(size, size + 1, arrayOfSportsman);
			}

			file >> arrayOfSportsman[numberOfLines].fullName;
			file >> arrayOfSportsman[numberOfLines].gameNumber;
			file >> arrayOfSportsman[numberOfLines].age;
			file >> arrayOfSportsman[numberOfLines].height;
			file >> arrayOfSportsman[numberOfLines].weight;
			file >> arrayOfSportsman[numberOfLines].country;
			file >> arrayOfSportsman[numberOfLines].teamName;
			numberOfLines++;
		}
		arrayOfSportsman = resizeArray(size, size - 1, arrayOfSportsman);
		file.close();
		return arrayOfSportsman;
	}
}

void printArray(Sportsman* arrayOfSportsman, int size) {
	cout << "+--------------------------------------------------------------------------------------------------------+\n";
	cout << "|" << setw(10) << "full name" << setw(5)
		<< "|" << setw(10) << "game number" << setw(5)
		<< "|" << setw(8) << "age" << setw(7)
		<< "|" << setw(10) << "height" << setw(5)
		<< "|" << setw(10) << "weight" << setw(5)
		<< "|" << setw(10) << "country" << setw(5)
		<< "|" << setw(10) << "team name" << setw(5) << "|\n";
	for (int numberOfLines = 0; numberOfLines < size; numberOfLines ++) {
		cout << "+--------------------------------------------------------------------------------------------------------+\n";
		cout <<"|" << setw(10) << arrayOfSportsman[numberOfLines].fullName << setw(5) << "|"
			<< setw(9) << arrayOfSportsman[numberOfLines].gameNumber << setw(7) << "|"
			<< setw(7) << arrayOfSportsman[numberOfLines].age << setw(8) << "|"
			<< setw(10) << arrayOfSportsman[numberOfLines].height << setw(5) << "|"
			<< setw(8) << arrayOfSportsman[numberOfLines].weight << setw(7) << "|"
			<< setw(10) << arrayOfSportsman[numberOfLines].country << setw(5) << "|"
			<< setw(10) << arrayOfSportsman[numberOfLines].teamName << setw(5) << "|\n";
	}
}

void writeInFile(string fileName, int& size) {
	ofstream file;
	file.open(fileName, ios::app);
	
	Sportsman buffValue;
	if (!file.is_open()) {
		return;
	}
	else {
		cout << "Enter full name: "; 
		cin >> buffValue.fullName;
		file << buffValue.fullName << " ";

		cout << "Enter game Number: ";
		cin >> buffValue.gameNumber;
		file << buffValue.gameNumber << " ";

		cout << "Enter age: ";
		cin >> buffValue.age;
		file << buffValue.age << " ";

		cout << "Enter height: ";
		cin >> buffValue.height;
		file << buffValue.height << " ";

		cout << "Enter weight: ";
		cin >> buffValue.weight;
		file << buffValue.weight << " ";

		cout << "Enter country: ";
		cin >> buffValue.country;
		file << buffValue.country << " ";

		cout << "Enter name of team: ";
		cin >> buffValue.teamName;
		file << buffValue.teamName << " ";

	}
	
	file.close();
}

void linearSearchToArray(Sportsman* arrayOfSportsman, int size) {
	int min = INT_MAX;
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (arrayOfSportsman[i].age < min) {
			min = arrayOfSportsman[i].age;
			index = i;
		}
	}
	cout << arrayOfSportsman[index].fullName << " ";
	cout << arrayOfSportsman[index].gameNumber << " ";
	cout << arrayOfSportsman[index].age << " ";
	cout << arrayOfSportsman[index].height << " ";
	cout << arrayOfSportsman[index].weight << " ";
	cout << arrayOfSportsman[index].country << " ";
	cout << arrayOfSportsman[index].teamName << endl;
}

void SelectionSort(Sportsman* arrayOfSportsman, int size) {
	
}

void functionSelection(string fileName, int& size, Sportsman* arrayOfSportsman) {
	
	cout << "What do you want?:\n 1 - read file \n 2 - write in file\n";
	cout << " 3 - Linear search in array\n 4 - create your file \n";
	cout << "Enter your number: ";
	int choice;
	cin >> choice;
	
	switch (choice) {
	case 1:
		system("cls");
		printArray(arrayOfSportsman, size);
		system("pause");
		system("cls");
		functionSelection(fileName, size, arrayOfSportsman);
		break;

	case 2:
		system("cls");
		writeInFile(fileName, size);
		arrayOfSportsman = readFile(fileName, size);
		system("pause");
		system("cls");
		functionSelection(fileName, size, arrayOfSportsman);
		break;


	case 3:
		system("cls");
		linearSearchToArray(arrayOfSportsman, size);
		system("pause");
		system("cls");
		functionSelection(fileName, size, arrayOfSportsman);
		break;
	case 4:
		system("cls");
		createFile(fileName);
		system("pause");
		system("cls");
		functionSelection(fileName, size, arrayOfSportsman);
		break;
	case 5:
		return;
	default:
		cout << "Please, enter number";

	}

}
