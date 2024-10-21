#include<iostream>
using namespace std;

int main()
{
    char a[] = "finder";
    char b[] = "friend";
    
    int i, j;
    for(i = 0; a[i] != '\0'; i++)
    {   
        for(j = 0; b[j] != '\0'; j++)
        {
            if (a[i] == b[j])
            {
                b[j] = 48;
            }
        }
    }

    for(j = 0; b[j] != '\0'; j++)
        {
            if (b[j] != 48)
            {
                cout << "Its not an Anagram." << endl;
                break;
            }
        }
    if (b[j] == '\0')
    {
        cout << "Yes, its an Anagram." << endl;
    }

    return 0;
}