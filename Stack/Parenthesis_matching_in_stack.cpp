#include<iostream>
#include<cstring>
using namespace std;

struct stack
{
    int size;
    int top = -1;
    char *s;
};

void push(struct stack &st, char x)
{
    st.top++;
    st.s[st.top] = x;
}

void pop(struct stack &st)
{
    st.s[st.top] = 0;
    st.top--;
}


int empty(struct stack st)
{
    if(st.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int is_balance(const char *exp)
{
    struct stack st;
    st.size = strlen(exp);
    st.s = new char[st.size];

    // initializing and checking if parenthesis are matching or not
    for(int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
        {
            push(st, exp[i]);
        }
        else
        {
            if(exp[i] == ')')
            {
                if(empty(st))
                {
                    return false;
                }
                else
                {
                    pop(st);
                }
            }
        }
    }

    int x = empty(st);
    delete[] st.s; // in line 41 there is dynamic array creation
    return x;
}


int main()
{
    const char *exp = "(a+b)*(b+c)"; // i used const keyword because char* is not allowed in C++ because it can lead to modification of string literals, which is undefined behavior.
    if(is_balance(exp))
    {
        cout << endl << "Parenthesis matched." << endl;
    }
    else
    {
        cout << endl << "Parenthesis not matched." << endl;
    }

    return 0;
}