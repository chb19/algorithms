// Disjoint set union
//   Uses path compression and union by size heuristic
//   For root nodes parent is equal to negative size of set
//   count - the number of disjoint sets
//   Time complexity: O(a(n)) where a(n) is the inverse Ackermann function

#include <vector>
struct DSU
{
    DSU(int n) : parent(n, -1), count(n) {}

    int get_root(int u)
    {
        if (parent[u] < 0)
            return u;
        parent[u] = get_root(parent[u]);
        return parent[u];
    }

    void unite(int u, int v)
    {
        u = get_root(u);
        v = get_root(v);
        if (u != v) count--;
        if (parent[u] < parent[v])
        {
            parent[u] += parent[v];
            parent[v] = u;
        }
        else
        {
            parent[v] += parent[u];
            parent[u] = v;
        }
    }

    bool is_connected(int u, int v)
    {
        return get_root(u) == get_root(v);
    }

    int get_size(int u)
    {
        return -parent[get_root(u)];
    }

    std::vector<int> parent;
    int count;
};