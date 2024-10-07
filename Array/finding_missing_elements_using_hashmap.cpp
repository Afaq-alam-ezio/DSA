#include<iostream>
using namespace std;


int main()
{
    int len = 6, size = 10;
    int a[10] = {3, 5, 6, 8, 9, 10};
    int s = 3, l = 10; // Smallest and largest elements are stored from above array.


    int h[l+1];
    for(int i = 0; i < l+1; i++) // Setting all elements to 0 in this array.
    {
        h[i] = 0;
    }

    for(int i = 0; i < len; i++) // below a[i] is acting as index to array h for setting its value to 1.
    {
        h[a[i]] = 1;
    }

    for(int i = 0; i < l+1; i++) // Setting all elements to 0 in this array.
    {
        if (h[i] == 0)
        {
            cout << "Missing element is " << i << endl;
        }
    }

    return 0;
}