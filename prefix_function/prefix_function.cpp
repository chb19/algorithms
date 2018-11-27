#include "prefix_function.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s = "ababaca";
    auto p = prefix_function(s); // p = {0, 0, 0, 1, 2, 3, 0, 1}
    for (auto x : p)
    {
        cout << x << ' ';
    }
    return 0;
}