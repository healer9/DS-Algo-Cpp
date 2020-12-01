#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    list<int> *l;
    int V;

    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsHelper(int src, vector<int> &visited)
    {
        for (int nbr : l[src])
        {
            if (!visited[nbr])
            {
                cout << nbr << " , ";
                visited[nbr] = 1;
                dfsHelper(nbr, visited);
            }
        }
    }

    void dfs(int src)
    {
        vector<int> visited(V, 0);
        cout << src << " , ";
        visited[src] = 1;
        dfsHelper(src, visited);
    }
};

int main(int argc, char *argv[])
{
    int E, V;
    cin >> E >> V;

    Graph g(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\nEnter the source node(vertex) : ";
    int src;
    cin >> src;
    cout << "\nDFS : -> ";
    g.dfs(src);

    return 0;
}