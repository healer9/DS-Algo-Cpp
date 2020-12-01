// Adjacency List Implementation.
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    list<int> *l;
    int V;

public:
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

    void const print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "[ " << i << " ] -> ";
            for (int nbr : l[i])
            {
                cout << nbr << " -> ";
            }
            cout << endl;
        }
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

    g.print();
    return 0;
}