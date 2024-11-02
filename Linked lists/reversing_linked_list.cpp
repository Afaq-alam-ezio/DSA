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

void link_reverse(struct node *&p)
{
    // struct node *p = first; is invisible as it is above in formal parameter
    struct node *q = NULL;
    struct node *r = NULL;

    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    p = q;  // here p is indirectly first, can also use "first = q;"
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
    int a[] = {1, 2, 2, 3, 3, 4, 4, 6};
    create(first, a, 8);
    link_reverse(first);
    display(first);
    return 0;
}