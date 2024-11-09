#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*top = NULL;


void push(int x)
{
    struct node *t = new node;
    if(t == NULL)
    {
        cout << "Stack overflow." << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}


int pop()
{
    struct node *p = top;
    int x = -1;
    if(top != NULL)
    {
        x = p->data;
        top = top->next;
        delete p;
        return x;
    }
    else
    {
        cout << "The stack is empty , hence stack underflow." << endl;
        return 0;
    }
}


int peek(int position)
{
    struct node *p = top;
    for(int i = 0; i < position - 1 && p != NULL; i++)
    {
        p = p->next;
    }
    return p->data;
}


void display(struct node *p)
{
    cout << endl << "Below is the stack :" << endl;
    while(p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

int stack_top()
{
    struct node *p = top;
    if(p)
    {
        return p->data;
    }
}

int empty()
{
    struct node *p = top;
    if(p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int full()
{
    struct node *t = new node;
    if(t == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    cout << endl << "The data deleted is = " << pop() << endl;

    cout << endl << "The data at position 3 is = " << peek(3) << endl;

    cout << endl << "The data at top position is = " << stack_top() << endl;

    if(empty())
    {
        cout << endl << "Yes, the stack is empty." << endl;
    }
    else
    {
        cout << endl << "No the stack is not empty." << endl;
    }

    if(full())
    {
        cout << endl << "The stack is full." << endl;
    }
    else
    {
        cout << endl << "The stack is not Full." << endl;
    }


    display(top);

    return 0;
}