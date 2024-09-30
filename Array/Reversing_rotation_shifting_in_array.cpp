#include<iostream>
using namespace std;


struct array
{
    int a[8];
    int len;
    int size;
};
 // method 1 : using two loops 
void rev1(struct array *arr1)
{
    int b[arr1->len];
    for(int i = 0, j = arr1->len-1; i < arr1->len; i++, j--)
    {
        b[j] = arr1->a[i];
    }
    for(int i = 0; i < arr1->len; i++)
    {
        arr1->a[i] = b[i];
    }
    cout << "New reversed array is = ";
    for(int i = 0; i < arr1->len; i++)
    {
        cout << arr1->a[i] << " ";
    }
    cout << endl;
}

//method 2: using a single loop
void rev2(struct array *arr2)
{
    for(int i = 0, j = arr2->len-1; i < j; i++, j--)
    {
        int temp = arr2->a[j];
        arr2->a[j] = arr2->a[i];
        arr2->a[i] = temp;
    }

    cout << "New reversed array is = ";
    for(int i = 0; i < arr2->len; i++)
    {
        cout << arr2->a[i] << " ";
    }
    cout << endl;
};


// Below is right shift.it also works for left shift by changing index
void shift(struct array *arr)
{
    int  i = arr->len;
    for(; i > 0; i--)
    {
        arr->a[i] = arr->a[i-1];
    }
    arr->a[i] = 0;
    cout << "Below is the right shifted array = ";
    for(i = 0; i < arr->len; i++)
    {
        cout << arr->a[i] << " ";
    }
    cout << endl;
}


// Below is left rotate.it also works for right rotate just change the index
void rotate(struct array *arr)
{
    int temp = arr->a[0];
    int  i = 0;
    for(; i < arr->len-1; i++)
    {
        arr->a[i] = arr->a[i+1];
    }
    arr->a[arr->len-1] = temp;
    cout << "Below is the left rotated array = ";
    for(i = 0; i < arr->len; i++)
    {
        cout << arr->a[i] << " ";
    }
    cout << endl;
}


int main()
{
    struct array arr1 = {{1, 2, 3, 4, 5, 6, 7, 8}, 8, 8};
    struct array arr2 = {{9, 10, 11, 12, 13, 14, 15, 16}, 8, 8};

    rev1(&arr1);
    rev2(&arr2);

    struct array arr3 = {{1, 2, 3, 4, 5, 6, 7, 8}, 8, 8};
    shift(&arr3);

    struct array arr4 = {{1, 2, 3, 4, 5, 6, 7, 8}, 8, 8};
    rotate(&arr4);

    return 0;
}
