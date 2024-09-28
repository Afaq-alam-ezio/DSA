//Binary search code in recursive version 
#include<iostream>
using namespace std;

struct Array
{
    int a[7];
    int len;
    int size;
};


int Rbinsearch(struct Array arr, int key, int l, int h)
{
    while(l <= h)
    {
        int mid = (l+h)/2;
        if (arr.a[mid] == key)
        {
            // cout << "value found at index ";
            return mid;
        }
        else if(key < arr.a[mid])
        {
            return Rbinsearch(arr, key, l, mid-1);
        }
        else
        {
            return Rbinsearch(arr, key, mid+1, h);
        }
    }
    // cout << "Value not found ";
    return -1;
}


int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7}, 7, 7};
 
    int x = Rbinsearch(arr, 50, 0, arr.len-1);
    cout << x;
    return 0;
}