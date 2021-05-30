//practice.geeksforgeeks.org/problems/topological-sort/1
#include "iostream"
#include "list"
#include "string"
#include "map"
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> m;

public:
    void addEdge(T u, T v)
    {
        m[u].push_back(v);
    }

    void dfs_helper(T node, map<T, bool> &visited, list<T> &ordering)
    {
        visited[node] = true;

        for (auto nbr : m[node])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited, ordering);
            }
        }

        ordering.push_front(node);
    }

    void dfs()
    {
        map<T, bool> visited;
        list<T> ordering;

        for (auto node : m)
        {
            visited[node.first] = false;
        }

        for (auto node : m)
        {
            if (!visited[node.first])
            {
                dfs_helper(node.first, visited, ordering);
            }
        }

        for (auto node : ordering)
            cout << node << endl;
    }
};

int main(int argc, char *argv[])
{
    Graph<string> g;
    g.addEdge("Python", "Data Preprocessing");
    g.addEdge("Python", "PyTorch");
    g.addEdge("Python", "ML");
    g.addEdge("Data Preprocessing", "ML");
    g.addEdge("PyTorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "Face Recognition");
    g.addEdge("Date Set", "Face Recognition");

    g.dfs();

    return 0;
}