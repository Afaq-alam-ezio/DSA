#include<iostream>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first = NULL;

void create(struct node *&first, int a[], int n)
{
    struct node *t, *last;
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

void display(struct node *p)
{
    // p = p->next->next->next->next->next;   /// for reverse printing check
    while(p)
    {
        cout << p->data << " ";
        p = p->next;    /// also for reverse printing we need to write p = p->prev
    }
}


int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    create(first, a, 6);
    cout << "The doubly linked list looks like : ";
    display(first);
    
    return 0;
}