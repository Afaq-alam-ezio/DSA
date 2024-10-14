#include <iostream>
using namespace std;

int main() {
    char temp[10] = "wElComE";

    for(int i = 0; temp[i] != '\0'; i++) {
        if (temp[i] < 91)  // 90 is 'Z'
        {
            temp[i] += 32;  // Convert uppercase to lowercase
        }
        else
        {
            temp[i] -= 32;  // Convert lowercase to uppercase
        }
    }

    printf("The reversed string is = %s", temp);
    return 0;
}
