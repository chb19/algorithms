#include "dsu.h"
#include <iostream>

using namespace std;

int main()
{
    DSU dsu(5); // {{0}, {1}, {2}, {3}, {4}}
    cout << dsu.count << endl; // 5
    dsu.unite(0, 1); // {{0, 1}, {2}, {3}, {4}}
    cout << dsu.count << endl; // 4
    cout << dsu.get_size(1) << endl; // 2
    dsu.unite(3, 4); // {{0, 1}, {2}, {3, 4}}
    cout << dsu.count << endl; // 3
    dsu.unite(1, 4); // {{0, 1, 3, 4}, {2}}
    cout << dsu.count << endl; // 2
    cout << dsu.is_connected(3, 0) << endl; // 1
    cout << dsu.get_size(1) << endl; // 4
}