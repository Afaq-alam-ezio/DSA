#include<iostream>
using namespace std;

int main()
{
    int len = 17;
    int a[17] = {-1, -2, -3, -40, 9, 7, 9, 8, 5, 6, 4, 5, 6, 2, 11, 330, 100};
    int min = a[0], max = a[0];
    for(int i = 1; i < len; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        else if(a[i] > max)
        {
            max = a[i];
        }
        // else      // we can skip this else part also 
        // {
        //     i = i; // for the value that is (min <= value <= max), we need no task to be done, therefore we skipped that index.
        //                // here above elese has a hidden condition of (min <= a[i] <= max).
        // }
    }

    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;

    return 0;
}