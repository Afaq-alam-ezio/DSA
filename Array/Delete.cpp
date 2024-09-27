#include<iostream>
using namespace std;

struct Array 
{
    int a[20];
    int size;
    int len;
};


// Deletion is done inside below function
int del(struct Array *arr, int index, int value)
{
    for(int i = index; i < arr->len; i++) // i < arr->len-1 replaced as shifting elements towards left side from right as deletion is done
    {
        arr->a[i] = arr->a[i+1];
    }
    // arr->a[arr->len-1] = 0; // At last iteration, 0 is assigned from the element ahead of index len, hence this statement is not needed
    arr->len--;
}


// Array elements are displayed using below function
int disp(struct Array *arr)
{
    cout << "[ " << "";
    for(int i = 0; i < arr->len; i++)
    {
        cout << arr->a[i] << " ";
    }
    cout << "]";
}


int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 20, 5};

    cout << "Array elements before deletion =" << " ";
    disp(&arr);
    cout << endl;

    del(&arr, 2, 10);
    cout << "Array elements after deletion  =" << " ";
    disp(&arr);

    return 0;
}
