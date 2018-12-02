#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > g;
vector<char> color;
vector<int> p, cycle;
// Cycle detection
//   detects cycle in undirected graph g
//   if some connected component has more then one cycle - it correctly detects at least one of them
//   Time cimplexity: O(n + m)

void dfs(int u, int parent)
{
    color[u] = 1;
    p[u] = parent;
    for (auto v : g[u])
    {
        if (color[v] == 1 and parent != v)
        {
            int w = u;
            while(w != v)
            {
                color[w] = 2;
                cycle.push_back(w);
                w = p[w];
            }
            color[w] = 2;
            cycle.push_back(w);
        }
        if (color[v] == 0)
        {
            p[v] = u;
            dfs(v, u); // replace to dfs(v, -1) for directed graphs
        }
    }
    color[u] = 2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    color.resize(n);
    p.assign(n, -1);
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
            dfs(i, - 1);
        }
    }

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << endl;
    for(int v : cycle)
    {
        cout << v + 1 << " ";
    }
    return 0;
}
