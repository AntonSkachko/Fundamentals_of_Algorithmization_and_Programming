#include <iostream>
#include <cmath>
using namespace std;

int sizeArray(int number) {
	int amountOfNumber = 0;
	int newNum;
	while (number) {
		newNum = number % 10;
		if (newNum % 3 == 0) {
			amountOfNumber++;
		}
		number /= 10;
	}
	return amountOfNumber;
	
}
void seachMultiplesOfThree(int amountOfNumber, int number) {
	int* yourArray = new int[amountOfNumber];
	int newNum;
	int i = 0;
	while(number) {
		newNum = number % 10;
		if (newNum % 3 == 0) {
			yourArray[i] = number % 10;
			i++;
		}
		
		number /= 10;
	}
	for (int i = 0; i < amountOfNumber; i++) {
		cout << yourArray[i] << " ";
	}
	delete[] yourArray;

}


int main() {
	int number;
	cout << "Enter number "; cin >> number;
	
	int amountOfNumber = sizeArray(number);
	
	if (amountOfNumber == 0) {
		cout << "This number don't have number % 3!!!";
		return 0;
	}

	cout << amountOfNumber << endl;
	seachMultiplesOfThree(amountOfNumber, number);
	

	return 0; 

}