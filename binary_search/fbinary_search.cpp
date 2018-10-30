#include "fbinary_search.h"
#include <iostream>
using namespace std;

int integerSquareRoot(int n)
{
    return fbinary_search(0, INT_MAX, 
        [n](int x)
        {
            return (long long)x * x > n;
        });
}

int main()
{
    cout << integerSquareRoot(24) << endl; // 4
    cout << integerSquareRoot(25) << endl; // 5
    cout << integerSquareRoot(26) << endl; // 5
    cout << integerSquareRoot(0) << endl; // 0
    cout << integerSquareRoot(1) << endl; // 1
    cout << integerSquareRoot(2) << endl; // 1
    cout << integerSquareRoot(INT_MAX) << endl; // 46340
    cout << integerSquareRoot(-42) << endl; // 0
    cout << fbinary_search(0, 100, [](int _) { return true; }) << endl; // 0
    cout << fbinary_search(0, 100, [](int _) { return false; }) << endl; // 99
    return 0;
}