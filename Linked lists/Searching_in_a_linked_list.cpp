#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void create(struct node *&first, int a[], int n)
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
    cout << "Linked list creation done." << endl;
}

int search(struct node *p, int key)
{
    while(p)
    {
        if(p->data == key)
        {
            cout << "Found" << endl;
            return p->data;     // this means that search found and address of p is returned as a place where key is found.
        }                
        p = p->next;            // else search area is now moved to next node.
                      
    }
    cout << "Not found." << endl;
    return -1;                    // if above key is not found, -1 will be returned.
}


int main()
{
    struct node *first = NULL;
    int a[] = {5, 6, 2, 3, 4};
    create(first, a, 5);
    search(first, 5);
    return 0;
}