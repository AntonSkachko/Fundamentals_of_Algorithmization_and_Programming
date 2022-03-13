#include <iostream>
using namespace std;

int* createArray(int& s) {
	cout << "enter size of the array = ";	cin >> s;
	int* a = new int[s];
	cout << "enter array elements: " << endl;
	
	for (int i = 0; i < s; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i]; 
	}
	cout << "array: ";
	for (int i = 0; i < s; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return a;
}

void task1()
{
	cout << "Task 1:" << endl;
	int s;
	int* a = createArray(s), min = a[0], minIndex = 0, sum = 0;
	for (int i = 0; i < s; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			minIndex = i;
		}
	}
	cout << "minimal index: " << minIndex <<endl;
	if (minIndex = s)
	{
		cout << "no sum after min\n";
	}
	else
	{
        for (int i = s-1; i > minIndex ; i--)
	    {
		sum += a[i];
	    }
	    cout << "sum = " << sum << endl;
	}
	
	delete[] a;
}

void task2() 
{
	cout << "Task 2:" << endl;
	int s, h=0, c=0;
	int* a = createArray(s);
	
	for (int i = 0; i < s; i++)
	{
		if (a[i] > 0)
			h++;
	}
	for (int i = 0; i < s; i++) 
	{
		if (a[i] <= 0)
			c++;
	}
	if (h == s)
	{
		cout << "all elements are positive\n";
	}
	if (c == s)
	{
		cout << "all elements aren't positive\n";
	}
	cout << "redacted array: ";
	for (int i = 0; i < s; i++)
	{
		if (a[i] <= 0) {
			cout << a[i] << " ";
		}
	}
	cout << endl;
	delete[] a;
}

void task3()
{
	cout << "Task 3:" << endl;
	int s;
	int* a = createArray(s);
	int sum = 0;
	cout << "redacted array: ";
	for (int i = 0; i < s; i++)
	{
		if ((i+1) % 3 != 0) {
			cout << a[i] <<" ";
		}
	}
	delete[] a;
}

int main() {
	task1();
	return 0;
}