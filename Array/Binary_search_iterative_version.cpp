//Binary search code in iterative version
#include<iostream>
using namespace std;

struct Array
{
    int a[7];
    int len;
    int size;
};

ś
int binsearch(struct Array arr, int key)
{
    int l = 0;
    int h = arr.len-1;
    
    while(l<=h)
    {
        int mid = (l+h)/2;
        if (arr.a[mid] == key)
        {
            cout << "key is found at index ";
            return mid;
        }
        else if(key < arr.a[mid])
        {
            h = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    cout  << "Not found ";
    return -1;
}


int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7}, 7, 7};

    cout << binsearch(arr, 55);

    return 0;
}