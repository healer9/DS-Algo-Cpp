//hack.codingblocks.com/app/contests/1211/292/problem
#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<pair<int, int>>> &g)
{
    for (int i = 0; i < g.size(); i++)
    {
        cout << "[ " << i << " ] -> ";
        for (pair<int, int> j : g[i])
            cout << "( " << j.first << ", " << j.second << " ) -> ";
        cout << endl;
    }
}

vector<int> dijkstra(vector<vector<pair<int, int>>> &g, int &src)
{
    int V = g.size();
    vector<int> distance(V, INT_MAX);
    // (dist, node)
    set<pair<int, int>> s;
    distance[src] = 0;
    s.insert({distance[src], src});

    while (!s.empty())
    {
        pair<int, int> p = *(s.begin());
        s.erase(p);

        int parent = p.second;
        int parentNodeDistance = p.first;

        for (auto nbr : g[parent])
        {
            if (distance[nbr.first] > (parentNodeDistance + nbr.second))
            {
                int dest = nbr.first;
                auto f = s.find({distance[dest], dest});

                if (f != s.end())
                    s.erase(f);

                distance[dest] = parentNodeDistance + nbr.second;
                s.insert({distance[dest], dest});
            }
        }
    }

    return distance;
}

int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        int E, V;
        cin >> V >> E;

        vector<vector<pair<int, int>>> g(V);

        for (int i = 0; i < E; i++)
        {
            int u, v, weight;
            cin >> u >> v >> weight;
            --u, --v;
            g[u].push_back({v, weight});
            g[v].push_back({u, weight});
        }

        int src;
        cin >> src;
        --src;
        print(g);

        vector<int> dist = dijkstra(g, src);
        for (int i = 0; i < dist.size(); i++)
            cout << i << " -> " << dist[i] << endl;

        for (int i = 0; i < dist.size(); i++)
        {
            if (i == src)
                continue;
            if (dist[i] == INT_MAX)
                cout << -1 << " ";
            else
                cout << dist[i] << " ";
        }
        cout << endl;
    }
    return 0;
}