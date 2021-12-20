#include <iostream>
using namespace std;

int main()
{
    int length;
    cout << "Enter length of array: ";
    cin >> length;
    int* array = new int[length];

    for (int i = 0; i < length; i++)
    {
        cout << "Enter array[" << i << "]: ";
        cin >> array[i];
    }

    int min = array[0], minIndex = 0;
    for (int i = 1; i < length; i++)
    {
        if (min > array[i])
        {
            min = array[i];
            minIndex = i;
        }
    }

    int sum = 0;
    for (int i = minIndex + 1; i < length; i++)
    {
        sum += array[i];
    }

    cout << "Sum = " << sum << endl;
    return 0;
}