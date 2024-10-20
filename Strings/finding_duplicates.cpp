#include<iostream>
using namespace std;

int main()
{
    char name[] = "data structures";
    int i = 0, j = 0;
    for(; name[i] != '\0'; i++)
    {
        int count = 0;
        for(j = i + 1; name[j] != '\0'; j++)
        {
            if(name[i] == name[j])
            {
                name[j] = 48;  // This replaces the duplicate character with '0' (ASCII value of 0 is 48)
                count++;
            }
        }
        if(name[i] != 48)
        {
            if(count > 0)
            {
                cout << name[i] << " is duplicated by " << count << " times in the given string." << endl;
                count = 0;
            }
        }
    }
    return 0;
}
