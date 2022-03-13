#include <iostream>
#include <ctime>
using namespace std;

void fillingArray(int* array, int length, int choice){
    srand(time(NULL));

    if (choice == 1) {
        for (int i = 0; i < length; i++) {
            cout << "array[" << i << "]: ";
            cin >> array[i];
        }
    }

    else if (choice == 2) {
        for (int i = 0; i < length; i++) {
            array[i] = rand() % 20 - 10;
        }
        for (int i = 0; i < length; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    else{
        cout << "Error in your code";
    }
}

int countingSum(int index_one, int index_two, int* array, int length){
    int sum = 0;
    if (index_one < index_two){
        for (int i = index_one + 1; i < index_two; i++){
            sum += array[i];
        }
    }

    else{
        for (int i = index_two + 1; i < index_one; i++){
            sum += array[i];
        }
    }

    return sum;
}

int findIndexOfZero(int* array, int length){
    int index = -1;
    for (int i = 0; i < length; i++){
        if (array[i] == 0){
            index = i;
        }
    }

    return index;
}

int findMaxElemIndex(int* array, int length){
    int max_element_index = 0;

    for (int i = 0; i < length; i++){
        if (array[max_element_index] < array[i]){
            max_element_index = i;
        }
    }

    return max_element_index;
}

int main(){
    int length, check = 0, choice;

    cout << "Length of array = ";
    cin >> length;

    int* array = new int[length];

    cout << "Choose how to fill the array\n" << "1 - input\n" << "2 - Random\n";
    cin >> choice;

    fillingArray(array, length, choice);

    for (int i = 0; i < length; i++){
        if (array[findMaxElemIndex(array, length)] == array[i]){
            check++;
        }
    }

    if (check > 1){
        cout << "Several maximum elements";
        return 0;
    }

    if (findIndexOfZero(array, length) == -1){
        cout << "No zeros in the array";
        return 0;
    }

    cout << "Sum of elements is " << countingSum(findMaxElemIndex(array, length), findIndexOfZero(array, length), array, length);

    return 0;
}
