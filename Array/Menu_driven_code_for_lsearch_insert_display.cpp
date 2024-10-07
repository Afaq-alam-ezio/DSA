#include<iostream>
using namespace std;

class Choice
{
    private:
        int len = 0, size = 0, *arr;
    public:
        Choice() // default const.
        {
            size = 6; //no. of elements that can be stored
            len = 4; // no of elements present
            arr = new int[size]{1, 2, 3, 4, 0, 0};
        }

        Choice(int a, int b) // parameterized const.
        {
            len = a;
            size = b;
            arr = new int[size];
            int i = 0;
            for(; i < len; i++)
            {
                cout << "Enter the element on index " << i << " = ";
                cin >> arr[i];
            }
        }

        ~Choice()
        {
            cout << "memory freed because program terminated completely." << endl;
        }

        void lsearch(int value)
        {
            int i = 0;
            while(i < len)
            {
                if (arr[i] == value)
                {
                    cout << "Found" << endl;
                    break;
                }
                i++;
            }
            if (i == len)
            {
                cout << "Not found." << endl;
            }
        }


        void insert(int index, int value)
        {
            if (index >= 0 && index < len)
            {
                int i = len - 1;
                for(; i >= index; i--)
                {
                    arr[i+1] = arr[i];
                }
                arr[i+1] = value;
                len++;
            }
            else
            {
                cout << "Incorrect index" << endl;
            }
        }

        void display()
        {
            int i = 0;
            for(; i < len; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};


int main()
{
    Choice obj1(4, 6);
    int ch;
    do
    {
        cout << "\n\nSelect from below choices :\n1. linear search\n2. insertion\n3. Display\n--> ";
        cin >> ch;
        
        switch (ch)
        {
            case 1: 
                int p;
                cout << "Enter value to search = ";
                cin >> p;
                obj1.lsearch(p);
                break;
            
            case 2:
                int x, y;
                cout << "Enter the index and value = ";
                cin >> x >> y;
                obj1.insert(x, y);
                break;
            
            case 3:
                obj1.display();
                break;
        }
    }
    while(ch < 4);

    return 0;
}
