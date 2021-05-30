//leetcode.com/problems/accounts-merge/
#include "iostream"
#include "list"
#include "map"
#include "vector"
#include "queue"
using namespace std;

template <typename T>
class Graph
{
    map<int, list<T>> m;

public:
    void addEdge(int u, int v)
    {
        m[u].push_back(v);
        m[v].push_back(u);
    }
    void bfs(T src, vector<int> &visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        cout << "\nConnected Components : ";

        while (!q.empty())
        {
            int parent = q.front();
            q.pop();

            cout << parent << " ";

            for (auto nbr : m[parent])
            {
                if (!visited[nbr])
                {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        cout << endl;
    }
};

int main(int argc, char *argv[])
{
    Graph<int> g;
    int E, V;
    cin >> E >> V;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    vector<int> visited(V);

    int components = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            components++;
            g.bfs(i, visited);
        }
    }
    cout << "\nTotal number of connected Components : " << components << endl;
    return 0;
}