#include <iostream>

using std::cin;
using std::cout;

int main() {
  int arr[20];
  int arr_size;
  cout << "Enter array size = ";
  cin >> arr_size;
  while(arr_size > 20 || arr_size < 1) {
    cout << "Invalid array size\n";
    cout << "Enter array size = ";
    cin >> arr_size;
  }
  cout << "Enter array (" << arr_size << " values):\n";
  for (int index = 0; index < arr_size; ++index) {
    cin >> arr[index];
  }
  int negative_pos = -1;
  for (int index = 0; index < arr_size; ++index) {
    if(arr[index] < 0) {
      negative_pos = index;
      break;
    }
  }
  if(negative_pos == -1) {
    cout << "There no are negative elements\n";
    return 0;
  }
  if(negative_pos == arr_size - 1) {
    cout << "There no are elements after first negative element\n";
    return 0;
  }
  int sum = 0;
  for (int index = negative_pos + 1; index < arr_size; ++index) {
    sum += abs(arr[index]);
  }
  cout << "Sum abs values after first negative element = " << sum << '\n';
  return 0;
}
