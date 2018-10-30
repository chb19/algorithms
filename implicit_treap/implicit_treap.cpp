#include "implicit_treap.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    Treap treap;
    for (int i = 0; i < 5; i++)
    {
        treap.push_back(i);
    }
    treap[0] = 42;
    treap.insert(2, -1);
    // now treap is (-42, 1, -1, 2, 3, 4)
    for (int i = 0; i < treap.size(); i++)
    {
        cout << treap[i] << " ";
    }
    cout << endl;
    cout << treap.rangeSum(1, 2) << endl; // 1
    cout << treap.rangeSum(0, 6) << endl; // 51
    cout << treap.rangeSum(4, 6) << endl; // 7
    cout << treap.rangeSum(0, 0) << endl; // 0
    cout << treap.rangeSum(2, 4) << endl; // 1
    return 0;
}