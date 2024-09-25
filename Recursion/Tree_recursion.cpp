<<<<<<< HEAD
#include<iostream>
using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        cout << n;
        fun(n-1);
        fun(n-1);
    }
}

int main()
{
    fun(3);
    return 0;
}
=======
#include<iostream>
using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        cout << n;
        fun(n-1);
        fun(n-1);
    }
}

int main()
{
    fun(3);
    return 0;
}
>>>>>>> af3ecffc8da3c2a94194d6ac50e836800c84c6c8
