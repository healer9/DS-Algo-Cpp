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

    void bfs(int src)
    {
        queue<int> q;
        vector<int> visited(V, 0);
        q.push(src);
        cout << src << " , ";
        visited[src] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int nbr : l[node])
            {
                if (!visited[nbr])
                {
                    cout << nbr << " , ";
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        cout << endl;
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
    cout << "\nBFS : -> ";
    g.bfs(src);

    return 0;
}