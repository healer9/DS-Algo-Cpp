//leetcode.com/problems/course-schedule/
#include "iostream"
#include "vector"
#include "queue"
using namespace std;

void topologicalSortBfs(vector<vector<int>> &graph)
{
    const int V = (int)graph.size();
    vector<int> indegree(V);

    for (int i = 0; i < graph.size(); i++)
    {
        for (int nbr : graph[i])
        {
            indegree[nbr]++;
        }
    }

    // for (int i : indegree)
    //     cout << i << " ";
    // cout << endl;

    //  Perform BFS push the node having indegree 0 in the queue first.

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (!indegree[i])
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " -> ";

        for (int nbr : graph[node])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
                q.push(nbr);
        }
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    topologicalSortBfs(graph);

    return 0;
}