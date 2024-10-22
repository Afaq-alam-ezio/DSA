#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};


void create(int a[], int n, struct node *&first) // pass by reference is mandatory here
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
        last->next = t;
        last = t;
    }
}

void display(struct node *p)
{
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    struct node *first = NULL;
    int a[] = {1, 2, 3, 4 ,5 ,6};
    create(a, 6, first);
    display(first);
    return 0;
}