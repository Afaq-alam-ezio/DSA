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


        void check()
        {
            int diff = arr[0] - 0; // difference between the element at 0 index and index i.e 0
            for(int i = 0; i < len; i++)
            {
                if(arr[i]-i != diff) // checking if current value at this index is greater than desired difference
                {
                    while(diff < arr[i] - i) // while our desired difference is less than the calculated difference inside this while loop i.e. arr[i]-i
                    {
                        cout << "Missing element is = " << i + diff << endl;
                        diff++;
                    }
                }
            }
        }
};



int main()
{
    int size, len;
    cout << "Enter the size and number of elements you wanna insert = ";
    cin >> size >> len;
    Harry obj(size, len);

    obj.check();
    
    return 0;
}