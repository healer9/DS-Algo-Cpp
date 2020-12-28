//www.hackerrank.com/challenges/bfsshortreach/problem
#include <bits/stdc++.h>
using namespace std;

vector<int> shortestBFS(vector<vector<int>> &g, int &src)
{
    int V = g.size();
    vector<int> dist(V, 0);
    vector<int> visited(V, 0);

    queue<int> q;
    q.push(src);
    visited[src] = 1;

    while (!q.empty())
    {
        int parentNode = q.front();
        q.pop();

        for (int nbr : g[parentNode])
        {
            if (!visited[nbr])
            {
                q.push(nbr);
                visited[nbr] = 1;
                dist[nbr] = dist[parentNode] + 1;
            }
        }
    }
    return dist;
}

int main(int argc, char *argv[])
{
    int Q;
    cin >> Q;
    while (Q--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> g(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int src;
        cin >> src;
        --src;

        vector<int> result = shortestBFS(g, src);

        for (int i = 0; i < result.size(); i++)
        {
            if (i == src)
                continue;
            if (result[i] == 0)
                cout << -1 << " ";
            else
                cout << result[i] * 6 << " ";
        }

        cout << endl;
    }

    return 0;
}