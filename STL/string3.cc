#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    char s[100] = "Today is sunday";
    char* ptr = strtok(s, " ");
    cout << ptr << endl;

    // ptr = strtok(NULL, " ");
    // cout << ptr << endl;

    while (ptr != NULL) {
        cout << ptr << endl;
        ptr = strtok(NULL, " ");
    }
}