#include <iostream>
#include <cstdlib> // for function rand() and srand()
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

int* arrayCreation(int arrayFillSelection, int amountOfElements);
void seachMaxAndMin(int yourArray, int& indexMax, int& indexMin, int amountOfElement);
bool comp(const int& a, const int& b);
int* sortBetweenMaxAndMin(int* yourArray, int amountOfElement);


int main() {
	srand((unsigned int)time(NULL));
	int arrayFillSelection; // random or via console
	cout << "If you want random enter 1\n";
	cout << "If you want via console enter 2\n";
	cout << "Your choice: "; cin >> arrayFillSelection;
	
	int amountOfElements;
	cout << "Enter amount of elements: "; cin >> amountOfElements;
	int* yourArray = arrayCreation(arrayFillSelection, amountOfElements);
	int* newArray = sortBetweenMaxAndMin(yourArray, amountOfElements);

	for (int i = 0; i < amountOfElements; i++) {
		cout << newArray;
	}
	delete[] yourArray;
	return 0;
}



int* arrayCreation(int arrayFillSelection, int amountOfElements) {

	int* yourArray = new int[amountOfElements];
	
	switch (arrayFillSelection) {
	case 1:
		for (int i = 0; i < amountOfElements; i++) {
			yourArray[i] = rand() % 6 + 1;
		}
		for (int i = 0; i < amountOfElements; i++) {
			cout << yourArray[i] << " ";
		}
		break;
	case 2:
		for (int i = 0; i < amountOfElements; i++) {
			cout << "Enter yourArray[" << i << "]"; cin >> yourArray[i];
		}
		for (int i = 0; i < amountOfElements; i++) {
			cout << yourArray[i] << " ";
		}
		break;
	default:
		cout << "wow\n Enter new number ";
		cin >> arrayFillSelection;
		arrayCreation(arrayFillSelection, amountOfElements);
	}
	return yourArray;
}

void seachMaxAndMin(int* yourArray, int& indexMax, int& indexMin, int amountOfElement) {
	int maxElement = INT_MIN, minElement = INT_MAX;
	for (int i = 0; i < amountOfElement; i++) {
		if (yourArray[i] > maxElement) {
			maxElement = yourArray[i];
			indexMax = i;
		}
		if(yourArray[i] < minElement){
			minElement = yourArray[i];
			indexMin = i;
		}
	}
}
bool comp(const int& a, const int& b) {
	return a > b;
}

int* sortBetweenMaxAndMin(int* yourArray, int amountOfElement) {
	int indexMax = 0, indexMin = 0;
	seachMaxAndMin(yourArray, indexMax, indexMin, amountOfElement);
	sort(yourArray[indexMax], yourArray[indexMin], comp);
	return yourArray;

}