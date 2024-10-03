#include<iostream>
using namespace std;


struct array1
{
    int a[6], len, size;
};


struct array2
{
    int b[6], len, size;
};


void merge(struct array1 arr1, struct array2 arr2)
{
    int len = arr1.len + arr2.len;
    int c[len];
    int i = 0, j = 0, k = 0;

    // merge started below
    while(i < arr1.len && j < arr2.len)
    {
        if(arr1.a[i] < arr2.b[j])
        {
            c[k] = arr1.a[i];
            i++;
        }
        else
        {
            c[k] = arr2.b[j];
            j++;
        }
        k++;
    }

    //For the elements that got left in Array 1
    for(; i < arr1.len; i++)
    {
        c[k] = arr1.a[i];
        k++;
    }

    //For the elements that got left in Array 2 
    for(; j < arr2.len; j++)
    {
        c[k] = arr2.b[j];
        k++;
    }
    //printing the merged Array "C"
    int l = 0;
    cout << "Below is the merged Array = ";
    for(; l < len; l++)
    {
        cout << c[l] << " ";
    }
}


int main()
{
    struct array1 arr1 = {{1, 3, 6, 8, 9, 10}, 6, 6};
    struct array2 arr2 = {{2, 4, 11, 12, 16, 19}, 6, 6};

    merge(arr1, arr2);

    return 0;
}