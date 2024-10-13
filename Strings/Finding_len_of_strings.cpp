#include<iostream>
using namespace std;

// Function to find the length of a string
int findLength(string str) {
    int length = 0;
    
    // Traverse the string until null character is encountered
    for(int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    
    return length;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);  // Input string from user also getline is a builtin function in cpp
    
    // Find and print the length of the string
    int length = findLength(str);
    cout << "The length of the string is: " << length << endl;
    
    return 0;
}
