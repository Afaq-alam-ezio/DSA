#include<iostream>
using namespace std;

int main()
{
    char name[] = "helloworld123";

    int i = 0, j = sizeof(name)-2;

    for(; i < j; i++, j--)
    {
        char temp = name[i];
        name[i] = name[j];
        name[j] = temp;
    }

    for(i = 0; name[i] != '\0'; i++)
    {
        cout << name[i] << " ";
    }
    
    return 0;
}