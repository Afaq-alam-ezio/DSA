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

int del(struct node *&first, int pos, int max_values)
{
    int x = 0;
    struct node *p = first;
    struct node *q = NULL;
    
    if(pos == 1)
    {
        x = first->data;
        first =  first->next;
        delete p;
        return x;
    }
    else if(pos > 1 && pos < max_values)
    {
        for(int i = 0; i < pos-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
    else
    {
        cout << "Invalid Index as input." << endl;
        return 0;
    }
}


int main()
{
    int a[] = {2, 5, 4, 6, 3, 1};
    create(first, a, 6);
    cout << "The deleted element is = " << del(first, 3, 6);
    return 0;
}