#include <bits/stdc++.h>
using namespace std;

// Cycle detection
//   sets cycle detection to true if undirected graph g contains cycle
//   Time cimplexity: O(n + m)
vector<vector<int>> g;
vector<char> color;
bool cycle_found;

void dfs(int u, int parent)
{
    color[u] = 1;
    for (auto v : g[u])
    {
        if (color[v] == 1 and parent != v)
        {
            cycle_found = true;
            return;
        }
        if (color[v] == 0)
            dfs(v, u);
    }
    color[u] = 2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    color.resize(n);
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
            dfs(i, -1);
    }
    cout << (cycle_found? "YES" : "NO");
    return 0;
}