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


int count_and_sum(struct node *p)
{
    int x = 0, c = 0;
    while(p)
    {
        c++;
        x = x + p->data;
        p = p->next;
    }
    cout << "Sum is elements inside linked list = " << x << endl ;
    return c;
}


int main()
{
    struct node *first = NULL;
    int a[] = {1, 2, 3, 4 ,5 ,6};
    create(a, 6, first);
    cout << "Number of nodes = " << count_and_sum(first);
    return 0;
}
