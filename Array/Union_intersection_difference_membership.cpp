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


void Union(struct array1 arr1, struct array2 arr2)
{
    int len = arr1.len + arr2.len;
    int c[len];
    int i = 0, j = 0, k = 0;

    // union started below
    while(i < arr1.len && j < arr2.len)
    {
        if(arr1.a[i] < arr2.b[j])
        {
            c[k] = arr1.a[i];
            i++;
        }
        else if(arr1.a[i] > arr2.b[j])
        {
            c[k] = arr2.b[j];
            j++;
        }
        else
        {
            c[k] = arr1.a[i];
            i++;
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

    len = k;
    //printing the merged Array "C"
    int l = 0;
    cout << "Below is the union of merged Array = ";
    for(; l < len; l++)
    {
        cout << c[l] << " ";
    }
    cout << endl;
}


void Intersection(struct array1 arr1, struct array2 arr2)
{
    int len = arr1.len + arr2.len;
    int c[len];
    int i = 0, j = 0, k = 0;

    // intersection started below
    while(i < arr1.len && j < arr2.len)
    {
        if(arr1.a[i] < arr2.b[j])
        {
            i++;
        }
        else if(arr1.a[i] > arr2.b[j])
        {
            j++;
        }
        else
        {
            c[k] = arr1.a[i];
            i++;
            j++;
            k++;
        }
        // k++ nott need here, only needed when actually an element is added in c[k] that's why it is in above inside else() only.
    }

    len = k;
    //printing the intersection Array "C"
    int l = 0;
    cout << "Below is the intersection of merged Array = ";
    for(; l < len; l++)
    {
        cout << c[l] << " ";
    }
    cout << endl;
}


void difference(struct array1 arr1, struct array2 arr2)
{
    int len = arr1.len + arr2.len;
    int c[len];
    int i = 0, j = 0, k = 0;

    // difference started below
    while(i < arr1.len && j < arr2.len)
    {
        if(arr1.a[i] < arr2.b[j])
        {
            c[k] = arr1.a[i];
            i++;
            k++;
        }
        else if(arr1.a[i] > arr2.b[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for(; i < arr1.len; i++)
    {
        c[k] = arr1.a[i];
        i++;
        k++;
    }

    len = k;
    //printing the differenced Array "C"
    int l = 0;
    cout << "Below is the differenced Array = ";
    for(; l < len; l++)
    {
        cout << c[l] << " ";
    }
    cout << endl;
}

void membership(struct array1 arr, int element)
{
    int low = 0, high = arr.len-1, mid = (low+high)/2;
    while(low <= high)
    {
        if(arr.a[mid] == element)
        {
            cout << "yes it is a member." << endl;
            break;
        }
        else if(element < arr.a[mid])
        {
            high = mid - 1;
            mid = (low+high)/2;
        }
        else
        {
            low = mid + 1;
            mid = (low+high)/2;
        }
    }
    if(low > high)
    {
    cout << "Not a member" << endl;
    }
}

int main()
{
    struct array1 arr1 = {{1, 3, 6, 8, 9, 16}, 6, 6};
    struct array2 arr2 = {{2, 4, 5, 8, 9, 15}, 6, 6};

    Union(arr1, arr2);
    Intersection(arr1, arr2);
    difference(arr1, arr2);
    membership(arr1, 6);

    return 0;
}