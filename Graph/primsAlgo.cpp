//www.hackerrank.com/challenges/primsmstsub/problem
#include <bits/stdc++.h>
using namespace std;

// void print(vector<vector<pair<int, int>>> &g)
// {
//     for (int i = 0; i < g.size(); i++)
//     {
//         cout << "[ " << i << " ] -> ";
//         for (pair<int, int> j : g[i])
//             cout << "( " << j.first << ", " << j.second << " ) -> ";
//         cout << endl;
//     }
// }

int findMinVertex(vector<vector<pair<int, int>>> &g, vector<int> &weight, vector<int> &visited)
{
    int minVertex = -1, V = g.size();

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] and (minVertex == -1 or weight[i] < weight[minVertex]))
        {
            minVertex = i;
        }
    }

    return minVertex;
}

int primsAlgo(vector<vector<pair<int, int>>> &g, int &src)
{
    int V = g.size();
    int minCost = 0;

    vector<int> parent(V, -1), weight(V, INT_MAX), visited(V, 0);
    weight[src] = 0;

    for (int i = 0; i < V; i++)
    {
        int minVertex = findMinVertex(g, weight, visited);
        visited[minVertex] = 1;
        for (auto nbr : g[minVertex])
        {
            if (!visited[nbr.first])
            {
                if (weight[nbr.first] > nbr.second)
                {
                    parent[nbr.first] = minVertex;
                    weight[nbr.first] = nbr.second;
                }
            }
        }
    }

    for (int i : weight)
        minCost += i;
    return minCost;
}

int main(int argc, char *argv[])
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
    // print(g);
    cout << primsAlgo(g, src) << endl;
    return 0;
}