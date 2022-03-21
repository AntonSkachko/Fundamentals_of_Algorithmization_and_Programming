#include <iostream>
#include <random>
#include <ctime>
using namespace std;

struct Stack {
	int info;
	Stack* next;
};


// Перенести из созданного стека в новый стек все элементы, находящиеся между
// вершиной и элементом с минимальным значением.

Stack* inStack(Stack* begin, int info);
void view(Stack* begin);
Stack* delAll(Stack* begin);
void sortInfo(Stack* begin);
Stack* OutStack(Stack* begin, int* out);
Stack* individualTask(Stack* begin, int count, int maxValue);

int main() {
	srand(time(NULL));
	Stack* begin = NULL;
	int count, info, maxValue = -2999, choice;
	cout << "Enter count of element on the Stack: "; cin >> count;
	Stack * newStack = individualTask(begin, count, maxValue);
	
	while (true) {
		cout << "\n 1 - create stack. \n 2 - add in stack. \n 3 - view stack."
			<< "\n 4 - delete stack. \n 5 sorting stack. \n 6 - indivisual task"
			<< "\n 7 - exit.\n Your number is: ";
		cin >> choice;
		switch (choice) {
			case 1:
				for (int i = 0; i < count; i++) {
					info = rand() % 20 + 10;
					if (maxValue < info) {
						maxValue = info;
					}
					begin = inStack(begin, info);
				}
				break;
			
			case 2:
				cout << "Enter element: "; cin >> info;
				if (maxValue < info) {
					maxValue = info;
				}
				begin = inStack(begin, info);
				break;
			
			case 3:
				if (begin == NULL) {
					cout << "Stack does not exist";
				}
				else {
					cout << "Your Stack: ";
					view(begin);
				}
				break;
			
			case 4:
				begin = delAll(begin);
				break;
			
			case 5:
				cout << "\nYour sorted Stack: ";
				sortInfo(begin);
				view(begin);
				break;
			
			case 6:
				cout << "Max value is " << maxValue << endl;
				cout << "\n Your individual task: ";
				view(newStack);
				break;
			
			case 7:
				if (begin != NULL) {
					begin = delAll(begin);
				}
				return 0;

			default:
				cout << "plz enter normal number";
		}
	}
	return 0;
}


Stack* inStack(Stack* begin, int info) {
	Stack* temp = new Stack;
	temp->info = info;
	temp->next = begin;
	return temp;
}

void view(Stack* begin) {
	Stack* temp = begin;
	while (temp != NULL) {
		cout << temp->info << " ";
		temp = temp->next;
	}
}

Stack* delAll(Stack* begin) {
	Stack* temp;
	while (begin != NULL) {
		temp = begin;
		begin = begin->next;
		delete temp;
	}
	return begin;
}

void sortInfo(Stack* p) {
	Stack* t = NULL, * t1 ;
	int r;
	while (p->next != t) {
		for (t1 = p; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info) {
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		t = t1;
	}
}

Stack* OutStack(Stack* begin, int* out) {
	Stack* temp = begin;
	*out = begin->info;
	begin = begin->next;
	delete temp;
	return begin;
}

Stack* individualTask(Stack* begin, int count, int maxValue) {
	int inf;
	Stack* newStack = NULL;
	while (begin != NULL) {
		begin = OutStack(begin, &inf);
		if (inf == maxValue) {
			break;
		}
		newStack = inStack(newStack, inf);
	}
	return newStack;		
}