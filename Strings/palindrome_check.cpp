#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s = "MADAM";     // input string

    // index computation for i and j, here we have used string inbuilt method to fetch its length
    int i = 0, j = s.length() - 1;
    
    //loop will iterate to compare both end characters till i < j    
    for(; i < j; i++, j--)
    {
        // when characters are not equal on both sides
        if(s[i] != s[j])
        {
            cout << "Given string is not a palindrome.";
            break;
        }
    }

    // if loop met the termination condition, means string is pallindrome
    if(i == j)
    {
        cout << "Given string is a palindrome.";
    }
    
    return 0;
}