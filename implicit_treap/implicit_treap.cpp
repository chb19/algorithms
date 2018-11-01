#include "implicit_treap.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    Treap treap;
    for (int i = 1; i < 9; i++)
    {
        treap.push_back(2 * i);
    }
    print(treap); // (2, 4, 6, 8, 10, 12, 14, 16)

    cout << treap.rangeSum(1, 3) << endl; // 10

    treap.remove(2);
    print(treap); // (2, 4, 8, 10, 12, 14, 16)

    cout << treap.rangeSum(1, 3) << endl; // 12

    cout << treap.size() << endl; // 7

    treap.rangeAssign(1, 6, 5);
    print(treap); // (2, 5, 5, 5, 5, 5, 16)

    cout << treap.rangeSum(0, 4) << endl; // 17

    treap.set(4, 7);
    print(treap); // (2, 5, 5, 5, 7, 5, 16)

    cout << treap.rangeSum(4, 5) << endl; // 7

    treap.insert(2, -1);
    print(treap); // (2, 5, -1, 5, 5, 7, 5, 16)

    cout << treap.rangeSum(2, 4) << endl; // 4

    cout << treap[0] + treap[2] << endl; // 1

    cout << treap.rangeSum(4, 4) << endl; // 0
    return 0;
}