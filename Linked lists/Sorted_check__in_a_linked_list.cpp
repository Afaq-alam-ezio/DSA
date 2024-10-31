#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*first = NULL;

void create(struct node *&first, int a[], int n)
{
    struct node *t;
    struct node *last;
    first = new node; // this line is imp
    first->data = a[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++)
    {
        t = new node; // this line is imp
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout << "Array created." << endl;
}


int sort_check(struct node *first)
{
    int x = -32768;             // smallest value
    struct node *p = first;
    while(p)
    {
        if(p->data < x)
        {
            return false;
        }   
        x = p->data;            // this is the else part
        p = p->next;
    }
    return true;
}


int main()
{
    int a[] = {1, 2, 3, 4, 10, 6};
    create(first, a, 6);
    if(sort_check(first))
    {
        cout << "Yes, the Array is sorted." << endl;
    }
    else
    {
        cout << "No, the Array is not sorted." << endl;
    }


    return 0;
}