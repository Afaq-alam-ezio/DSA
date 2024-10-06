#include<iostream>
using namespace std;


class Harry
{
    private:
        int size;
        int *arr;
        int len;
        int Arrsum = 0;
    public:
        Harry(int s, int l)
        {
            size = s;
            len = l;
            arr = new int[size];

            int i = 0;
            while(i < len)
            {
                cout << "Enter the element at index " << i << " = ";
                cin >> arr[i];
                i++;
            }
        }


        void check1() // when array is sorted and starts from 0 or 1.
        {
            int i = 0;
            while(i < len)
            {
                Arrsum +=arr[i];
                i++;
            }

            int n = arr[len-1];
            int sumbyformula = (n*(n+1))/2;

            if(Arrsum == sumbyformula)
            {
                cout << "No missing element" << endl;
            }
            else
            {
                cout << "Missing element is = " << sumbyformula-Arrsum << endl;
            }
        }


        void check2() // if inside array any number is missing if it doesn't start from 0 or 1.
        {
            int index = 0;
            int diff = arr[0] - index;
            for(int i = 0; i < len - 1; i++)
            {
                if(arr[i] - index != diff)
                {
                    cout << "Missing element is = " << index + diff << endl;
                    break;
                }
                index++;  
            }
        }


        ~Harry()// destructor called
        {
            delete []arr;
            cout << "Destructor called and memory is freed as program terminated." << endl;
        }
};


int main()
{
    int size, len;
    cout << "Enter the size and number of elements you wanna insert = ";
    cin >> size >> len;
    Harry obj(size, len);

    char ch;
    cout << "If array is starts from 0 or 1, enter 'y'.\nIf array doesn't start from 0 or 1, enter 'n'.\n---> ";
    cin >> ch;

    switch (ch)
    {
        case 'y': obj.check1();
                    break;
        case 'n': obj.check2();
                    break;
        default : cout << "Invalid input." << endl;
    }

    return 0;
}