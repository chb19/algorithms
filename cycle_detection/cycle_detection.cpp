#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// Cycle detection
//   detects cycle in undirected graph g
//   if some connected component has more then one cycle - it correctly detects at least one of them
//   Time cimplexity: O(n + m)
vector<vector<int>> g;
vector<char> color;
vector<int> parent;

vector<int> dfs(int u, int from)
{
    color[u] = 1;
    vector<int> cycle;
    for (auto v : g[u])
    {
        if (color[v] == 1 and from != v)
        {
            int w = u;
            while(w != v)
            {
                cycle.push_back(w);
                w = parent[w];
            }
            cycle.push_back(v);
            // reverse(cycle.begin(), cycle.end()); // unnecessary for undirected graph
            break;
        }
        if (color[v] == 0)
        {
            parent[v] = u;
            cycle = dfs(v, u); // replace to dfs(v, -1) for directed graphs
            if (not cycle.empty())
                break;
        }
    }
    color[u] = 2;
    return cycle;
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    color.resize(n);
    parent.assign(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        if (not color[i])
        {
            auto cycle = dfs(i, -1);
            if (not cycle.empty())
            {
                for (auto v : cycle)
                {
                    cout << v + 1 << ' ';
                }
                cout << endl;
            }
        }
    }
    return 0;
}