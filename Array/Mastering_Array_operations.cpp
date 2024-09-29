#include<iostream>
using namespace std;

struct array
{
    int a[10];
    int size;
    int len;
};


int get(struct array arr, int index)  
{
    if (index >= 0 && index < arr.len)
    {
        return arr.a[index];
    }
    else
    {
        return -1;
    } 
}


void set(struct array *arr, int index, int value)
{
    if (index >= 0 && index < arr->len)
    {
        arr->a[index] = value;
        // for(int i = 0; i < arr->len-2; i++)
        // cout << arr->a[i] << " ";
        // return arr->a[arr->len-1]; // just to print the last element inside array and having something to return
    }
    else
    {
        cout << "False index as input";
    }
}


int Max(struct array arr)
{
    int max = arr.a[0];
    int i = 0;
    while (i < arr.len)
    {
        if (arr.a[i] > max)
        {
            max = arr.a[i];
        }
        i+=1;
    }
    return max;
}


int Min(struct array arr)
{
    int min = arr.a[0];
    int i = 0;
    while (i < arr.len)
    {
        if (arr.a[i] < min)
        {
            min = arr.a[i];
        }
        i+=1;
    }
    return min;
}


int Sum(struct array arr)
{
    int sum = 0;
    for(int i = 0; i < arr.len; i++)
    {
        sum += arr.a[i];
    }
    return sum;
}


int Avg(struct array arr)
{
    return Sum(arr)/arr.size;
}


void display(struct array arr)
{
    cout << "[ ";
    for(int i = 0; i < arr.len; i++)
    {
        cout << arr.a[i] << " ";
    }
    cout << "]";
}


int main()
{
    struct array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};

    cout << "value at index using get is = "<< get(arr, arr.len-1) << endl;

    // setting the element then just displaying the output using a display() function
    set(&arr, 3, 39);
    cout << "New array is = ";
    display(arr);
    cout << endl;

    // prints the greatest number inside the array
    cout << "Greatest number inside array is = " << Max(arr) << endl; // using set 40 was assigned at index 3

    // prints the smallest number inside the array
    cout << "Smallest number inside array is = " << Min(arr) << endl;

    // prints the sum of all numbers inside the array
    cout << "Sum of all numbers inside array is = " << Sum(arr) << endl;

    // prints the average array
    cout << "The average is = " << Avg(arr);

    return 0;
}
