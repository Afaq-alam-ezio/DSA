#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void create(struct node *&first, int a[], int n) // head pointer, array, size of array
{
    struct node *t;
    struct node *last;
    first = new node;
    first->data = a[0];
    first->next = NULL;
    last = first;


    for(int i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = NULL;
        last->next = t; // here last means first->next
        last = t;
    }
}

int max(struct node *p) // loop method
{
    int x = 0;
    while(p)
    {
        if(p->data > x)
        {
            x = p-> data;
        }
        p = p-> next;
    }
    return x;
}

int max1(struct node *p) // recursive method
{
    if(p == 0)
    {
        return 0;
    }
    else
    {
        int x = max1(p->next);
        if(x > p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
    }
}

int main()
{
    struct node *first = NULL;
    int a[] = {5, 4, 6, 2, 3};
    create(first, a, 5);
    cout << "The max value is = " << max(first) << endl;
    cout << "The max value is = " << max1(first) << endl;
    return 0;
}