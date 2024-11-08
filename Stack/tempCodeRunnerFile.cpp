#include<iostream>
using namespace std;

struct stack
{
    int size;
    int top = -1;
    int *s;     // its an array that will be made at runtime and will be indirectly our stack
};


// 1. push() adding new element inside stack
void push(struct stack &st, int element) // always pass by address to actually modify the stack
{
    st.top++;
    st.s[st.top] = element;
}


// 2. pop() deleting the last element from stack
void pop(struct stack &st)
{
    st.s[st.top] = NULL;
    st.top--;
}


// 3. peek(index) this will help to retrieve any value at any position in stack
int peek(struct stack st, int pos) // here a formula will be used to compute the index value by position value
{
    return st.s[st.top-pos+1];
}


// 4. stacktop() returns the topmost element from stack
int top(struct stack st)
{
    if(st.top == -1)
    {
        return 0;
    }
    else
    {
        return st.s[st.top];
    }
}


// 5. isempty() checks for if stack is empty
int isempty(struct stack st)
{
    if(st.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// 6. isfull() checks for if the stack is full or not
int isfull(struct stack st)
{
    if(st.top == st.size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



// 7. Displaying the stack
void display(struct stack st)
{
    cout << endl << "Below is the stack :" << endl;
    for(int i = st.top; i > -1; i--)
    {
        cout << st.s[i] << endl;
    }
}


int main()
{
    struct stack st;
    cout << "Enter the size of stack = ";
    cin >> st.size;
    st.s = new int[st.size];

    push(st, 20);
    push(st, 30);
    push(st, 40);
    push(st, 50);
    push(st, 60);
    pop(st); // this will delete the value 6 from stack i.e. push(st, 6);
    cout << endl << "The value at position 3 is " << peek(st, 3) << endl; // this will help to retrieve any value at any position in stack
    cout << endl << "The topmost element in stack = " << top(st) << endl; // returns the topmost element from stack
    if(isempty(st)) // checks for if stack is empty
    {
        cout << endl << "The stack is empty." << endl;
    }
    else
    {
        cout << endl << "The stack is not empty." << endl;
    }
    if(isfull(st)) // checks for if the stack is full or not ,,,  it will show not full as we have poped one element above
    {
        cout << endl << "Yes the stack is full." << endl;
    }
    else
    {
        cout << endl << "No the stack is not full." << endl;
    }
    display(st);
    return 0;
}