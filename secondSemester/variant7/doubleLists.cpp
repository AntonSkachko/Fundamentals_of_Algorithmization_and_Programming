#include <iostream>
#include <random>
#include <ctime>
using namespace std; 

struct DoublyList {
	int info;
	DoublyList* next;
	DoublyList* previous;
};

void addingToBeginning(DoublyList** begin, int info);
void addingToEnd(DoublyList**end, int info);
void delAll(DoublyList* begin, DoublyList* end);
void viewFromBegin(DoublyList* begin);
void viewFromEnd(DoublyList* end);
void individualTask(DoublyList* begin, int maxValue);

int main() {
	srand(time(0));
	int choice, size, info, maxValue = -299;
	DoublyList* temp = new DoublyList;
	DoublyList* begin, * end;
	temp->info = rand() % 60;
	temp->next = temp->previous = NULL;
	begin = end = temp;

	while (true) {
		cout << "\n 1 - create doubly list. \n 2 - adding to the beginning."
			<< "\n 3 - adding to the end. \n 4 - delete doubly list.\n 5 - view the doubly list from the beginning."
			<< "\n 6 - view the doubly list for the end.\n 7 - indivisual task.\n 8 - exit.\n Your number is: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "\n Enter size of doubly list: ";
				cin >> size;
				for (int i = 0; i < size - 1; i++) {
					info = rand() % 60;
					if (maxValue < info) {
						maxValue = info;
					}
					addingToBeginning(&begin, info);
				}
				break;
			
			case 2:
				cout << "\n Enter variable: "; cin >> info;
				addingToBeginning(&begin, info);
				break;
			
			case 3:
				cout << "\n Enter variable: "; cin >> info;
				addingToEnd(&end, info);
				break;

			case 4:
				delAll(begin, end);
				break;

			case 5:
				cout << "Your doubly list from the beginning: ";
				viewFromBegin(begin);
				break;

			case 6:
				cout << "Your doubly list from the end: ";
				viewFromEnd(end);
				break;

			case 7:
				individualTask(begin, maxValue);
				break;
			
			case 8:
				if (begin->next != NULL) {
					delAll(begin, end);
				}
				return 0;

		}
	}
	return 0;

}

void addingToBeginning(DoublyList** begin, int info) {
	DoublyList* temp = new DoublyList;
	
	temp->info = info;
	temp->next = *begin;
	temp->previous = NULL;
	(*begin)->previous = temp;
	*begin = temp;
}

void addingToEnd(DoublyList** end, int info) {
	DoublyList* temp = new DoublyList;
	
	temp->info = info;
	temp->previous = *end;
	temp->next = NULL;
	
	(*end)->next = temp;
	*end = temp;
}

void delAll(DoublyList* begin, DoublyList* end) {
	DoublyList* temp = new DoublyList;
	while (end->previous != NULL) {
		temp = end;
		end = end->previous;
		delete temp;
	}
}

void viewFromBegin(DoublyList* begin) {
	DoublyList* temp = begin;
	while (temp->next != NULL) {
		cout << temp->info << " ";
		temp = temp->next;
	}
}

void viewFromEnd(DoublyList* end) {
	DoublyList* temp = end;
	while (temp->previous != NULL) {
		cout << temp->info << " ";
		temp = temp->previous;
	}
}

void individualTask(DoublyList* begin, int maxValue) {
	DoublyList* temp = new DoublyList;
	temp->next = temp->previous = NULL;
	while (begin->info != maxValue) {
		addingToBeginning(&temp, begin->info);
		begin = begin->next;
	}
	cout << "Your individual task: ";
	viewFromBegin(temp);
}