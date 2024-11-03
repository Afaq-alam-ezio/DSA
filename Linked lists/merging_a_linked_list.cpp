#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*first = NULL, *second = NULL, *third = NULL;


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


void merge(struct node *&first, struct node *&second)
{
    // struct node *third = NULL;  no need to take this as it is already global.
    struct node *last = NULL;

    if(first->data < second->data)
    {
        third = first;
        last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = second;
        last = second;
        second = second->next;
        last->next = NULL;
    }

    while(first != NULL && second != NULL) // can't use || i.e. "logical or" as it will lead to comparision error of null with a number.
    {
        if(first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }

    if(first != NULL) // here no need to loop for connection , as they are already connected, we just connected the link of last node with next node that already has the greater value, rest other nodes are already connected
    {
        last->next = first;
        last = first;
    }
    else
    {
        last->next = second;
        last = second;
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
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 4, 6, 8, 10};
    create(first, a, 5);
    create(second, b, 5);
    merge(first, second);
    display(third); // pass third as third is now the new Head

    return 0;
}
