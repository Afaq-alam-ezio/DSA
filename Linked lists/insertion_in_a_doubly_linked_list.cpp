#include<iostream>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first = NULL, *last = NULL;

void create(struct node *&first, int a[], int n)
{
    struct node *t;
    first = new node;
    first->data = a[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++)
    {
        t = new node;
        t->prev = last;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int length(struct node *p)
{
    int len = 0;
    while(p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void insert(struct node *&first, struct node *&last, int x, int index)
{
    struct node *p = first;   
    struct node *t;
    struct node *l = last;

    if(index == 0)
    {
        t = new node;
        t->data = x;
        t->prev = NULL;
        t->next = p;
        p->prev = t;
        first = t;
    }
    else if(index > 0 && index < length(first))
    {
        for(int i = 0; i < index-1; i++)
        {
            p = p->next;
        }
        t = new node;
        t->data = x;

        t->prev = p;    // linking of p to its next and prev node
        t->next = p->next;

        p->next = t;    // linking rest front and back nodes to t
        p->next->prev = t;
    }
    else
    {
        while(p->next != NULL)
        {
            p = p->next;
        }
        t = new node;
        t->data = x;
        t->next = NULL;
        t->prev = p;
        p->next = t;

        l = t; // setting up new last node to t
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
    int a[] = {1, 2, 3, 4, 5, 6};

    create(first, a, 6);
    insert(first, last, 25, 6);
    display(first);
    
    return 0;
}