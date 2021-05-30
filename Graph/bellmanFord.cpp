#include "iostream"
#include "vector"
#include "climits"
using namespace std;

void print(vector<vector<pair<int, int>>> &g)
{
    for (int i = 0; i < g.size(); i++)
    {
        cout << i << " -> ";
        for (auto nbr : g[i])
        {
            cout << " {" << nbr.first << ", " << nbr.second << "}, ";
        }
        cout << endl;
    }
}

void bellmanFord(int src, vector<vector<pair<int, int>>> &g, int V, int E)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int it = 1;it <= (V -1);it++) {
        for(int )
    }
}

int main(int argc, char *argv[])
{
    int V, E;
    cin >> V, E;
    vector<vector<pair<int, int>>> g(V);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    print(g);
    bellmanFord(0, g, V, E);

    return 0;
}