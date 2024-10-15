#include <iostream>

using namespace std;

int main() {
    char vowel[] = "aeiouAEIOU";
    char word[] = "mmiiiil";

    int vowelCount = 0, consonantCount = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        for (int j = 0; vowel[j] != '\0'; j++)
        {
            if (word[i] == vowel[j])
            {
                vowelCount++;
                break;
            }
        }
    }

    cout << "Vowel count: " << vowelCount << endl;
    cout << "Consonant count: " << sizeof(word)-vowelCount-1 << endl;  // extra -1 at last to negate the  
                                                                       // hidden "/0" at end of word[] array.
    return 0;
}