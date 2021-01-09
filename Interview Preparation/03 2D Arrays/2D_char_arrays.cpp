#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

char* findStringVowelFirstAndLast(int input1, char* input2[]) {
    int index = 0;
    char *result = new char[1000];
    for(int i = 0; i < input1; i++) {
        char first = tolower(input2[i][0]);
        int k = 0;
        if(first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') {
            for(int j = 1; input2[i][j] != '\0'; j++) {
                k = j;
            }
            char last = tolower(input2[i][k]);
            if(last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u') {
                for(int m = 0; m <= k; m++) {
                    result[index++] = tolower(input2[i][m]);
                }
            }
        }
    }
    if(index == 0)
 
    else
        result[index] = '\0';
    return result;
}

int main() {
    int input1;
    cin >> input1;

    char *input2[input1];
    for(int i = 0; i < input1; i++) {
        input2[i] = new char[1000];
    }

    for(int i = 0; i < input1; i++) {
        cin >> input2[i];
    }

    char *str  = findStringVowelFirstAndLast(input1, input2);

    for(int i = 0; str[i] != '\0'; i++) {
        cout << str[i];
    }

}
