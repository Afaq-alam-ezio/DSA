#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*first = NULL;


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


void insert(struct node *p, int x, int pos)
{
    struct node *t;
    t = new node;
    if(pos == 0)
    {
        t->data = x;
        t->next = first;
        first = t;
    }
    else if(pos > 0)
    {
        for(int i = 0; i < pos-1 && p != NULL; i++)
        {
            p = p->next;
        }
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}


void display(struct node *p)
{
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}


int main()
{
    int a[] = {5, 4, 6, 2, 3};
    create(first, a, 5);
    insert(first, 30, 5);
    display(first);

    return 0;
}
