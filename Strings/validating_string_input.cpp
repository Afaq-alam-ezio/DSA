#include<iostream>
#include<string>
using namespace std;

int string_check(string str)  // String check function
{
    for(int i = 0; str[i] != '\0'; i++)
    {

        if (!((str[i] >= 65 && str[i] <= 90) || // Uppercase letters (A-Z)
              (str[i] >= 97 && str[i] <= 122) || // Lowercase letters (a-z)
              (str[i] >= 48 && str[i] <= 57)))   // Digits (0-9)
        {
            return false;
        }
    }
    return true;

}


int main()
{
    string s = "Hello world";    // Returns Invalid string as there's space between the string.

    if(string_check(s))
    {
        cout << "Valid string.";
    }
    else
    {
        cout << "Invalid string.";
    }

    return 0;
}