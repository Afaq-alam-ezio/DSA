#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 0, 0};  // Array with 5 elements and 2 extra elements for extra space for shifting the elemnts 
    int n = 5;  // Current elements inside array
    int element, pos;

    // Display the original array
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Input the element to insert
    cout << "Enter the element to insert: ";
    cin >> element;

    // Input the position to insert at
    cout << "Enter the position (1 to " << n+1 << "): ";
    cin >> pos;

    // Shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[pos - 1] = element;

    // Increase the size of the array
    n++;

    // Display the updated array
    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
