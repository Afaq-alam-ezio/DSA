#include<iostream>
using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        // cout << n << " ";  // # will give 3 2 1 -- uncommenting this line will make this a tail recursion
        fun(n-1);
        // cout << n << " ";  // # will give 1 2 3 -- uncommenting this line will make this a head recursion
    }
}

int main()
{
    int x;
    cout << "Enter any number : ";
    cin >> x;
    fun(x);
    return 0;
}
