#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	int n,fir, sec;
	cout << "Number of elements="; cin >> n;
	
	cout << "Choose type of entering mass elements:" << endl;
	cout << "1) by keyboard;" << endl;
	cout << "2) by random" << endl;
	int type; cout << "Type="; cin >> type;
	
	int* mass = new int[n];
	switch (type) {
	case 1:
		for (int i = 0; i < n; i++) {
			cout << "Enter mass[" << i << "]="; cin >> mass[i];
		}
		break;
	case 2:
		int min; cout << "Enter min numb="; cin >> min;
		int max; cout << "Enter max numb="; cin >> max;
		for (int i = 0; i < n; i++) {
			mass[i] = rand() % (max - min + 1) + min;
		}
		break;
	}
	//===================================================
	int null_num=0;
	for (int i = 0; i < n; i++) 
		if (mass[i] == 0) 
		{
			null_num++;
		    if (null_num == 1) fir=i;
			if (null_num == 2) sec = i;
	    }
	if (null_num == 0) cout << "no 0 " << endl;
	else if (null_num == 1) cout << "only one 0 " << endl;
	else if (sec == fir+1) cout << "no prod " << endl;
	else {
		int prod = 1;
		for (int i = fir + 1; i < sec; i++)
			prod *= mass[i];
		cout << "Product=" << prod << endl;
	}


	system("pause");
	return 0;
}