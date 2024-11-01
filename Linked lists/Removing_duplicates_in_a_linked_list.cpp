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

void duplicate(struct node *&first)
{
    struct node *p = first;
    struct node *q = first->next;
    while(q != NULL)
    {
        if(p->data == q->data)
        {
            cout << "Duplicate is = " << p->data << endl;
            p->next = q->next; // here, we need to modify the link section to next of next node, i.e. slipping 2 nodes (1->3) 
            delete q;
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }       
    }

    if(q == NULL)
    {
        cout << "No duplicates found." << endl;
    }
}

void display(struct node *p)
{
    cout << "Below is the linked list : " << endl;
    p = first;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}


int main()
{
    int a[] = {1, 2, 2, 2, 3, 3, 4, 4, 6};
    create(first, a, 9);
    duplicate(first);
    display(first);
    return 0;
}