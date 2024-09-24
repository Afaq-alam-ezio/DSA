#include<iostream>
using namespace std;

// int x = 5;  # Global variable

int fun(int n)
{
    int x = 0;
    if (n > 0)
    {
        x++;
        return fun(n-1) + x;
    }
    return 0;
}


int main()
{
    // static int x = 0;
    int a = 5;
    cout << fun(a);
    return 0;
}