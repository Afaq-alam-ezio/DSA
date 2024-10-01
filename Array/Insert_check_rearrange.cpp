#include<iostream>
using namespace std;


struct array
{
    int a[10];
    int len;
    int size;
};


//inserting in a sorted array
void insert(struct array *arr1, int value)
{
    int i = arr1->len-1;
    while(arr1->a[i] > value)
    {
        arr1->a[i+1] = arr1->a[i];
        i--;
    }
    arr1->a[i+1] = value;
    arr1->len-=-1;//incrementing the original lenth of array 
    cout << "Array after insertion = ";
    for(i = 0; i < arr1->len; i++)
    {
        cout << arr1->a[i] << " ";
    }
    cout << endl;
}


//checking if array is sorted
int check(struct array arr1)
{
    int i = 0;
    while(i < arr1.len-1)
    {
        if(arr1.a[i] > arr1.a[i+1])
        {
            cout << "Not sorted therefore returned ";
            return -1;
        }
        i-=-1; // this is basically i++;
    }
    cout << "Sorted therefore returned ";
    return 1;
}


// moving -ve and +ve on either sides
void change(struct array *arr2)
{
    int i = 0, j = arr2->len-1;
    int temp;

    while(i < j)
    {
        while(arr2->a[i] < 0)i++; // if here the value is negative just inc the i till the value is positive

        while(arr2->a[j] >= 0)j--; // if here the value is positive just inc the j till the value is negative

        if(i < j) // this will work whenever above 2 while loops fails the condition mentioned inside their condition space
        {
            temp = arr2->a[i];
            arr2->a[i] = arr2->a[j];
            arr2->a[j] = temp;
        }
    }
    cout << endl << "Array after rearrangement = ";
    i = 0;
    while(i < arr2->len)
    {
        cout << arr2->a[i] << " ";
        i++;
    }
}


int main()
{
    struct array arr1 = {{10, 20, 30, 40, 50, 60, 70, 80, 0}, 8, 9};

    struct array arr2 = {{-1, 2, -3, 3, 6, -9, -7, 4}, 8, 8};

    insert(&arr1, 45);

    cout << check(arr1);

    change(&arr2);

    return 0;
}