#include<iostream>
using namespace std;

int main()
{
    int len = 10, size = 10;
    int a[len] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Below are the combinations that together sum up to the value of k : " << endl;
    int i = 0, j = len - 1;
    while(i < j)
    {
        int k = 10;
        if(a[i] + a[j] == k)
        {
            cout << a[i] << " + " << a[j] << " = " << k << endl;
            i++;
            j--;
        }
        else if (a[i] + a[j] > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return 0;
}