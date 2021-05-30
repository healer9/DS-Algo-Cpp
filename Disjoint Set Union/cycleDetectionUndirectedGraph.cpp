#include "iostream"
#include "vector"

#define int long long

int findRoot(int node, std::vector<int> &dsu)
{
    return dsu[node] == -1 ? node : findRoot(dsu[node], dsu);
}

void unionOperation(int root1, int root2, std::vector<int> &dsu)
{
    dsu[root1] = root2;
}

bool isCycle(int V, std::vector<std::pair<int, int>> &graph)
{
    std::vector<int> dsu(V, -1);

    for (auto p : graph)
    {
        int from = p.first;
        int to = p.second;

        int root1 = findRoot(from, dsu);
        int root2 = findRoot(to, dsu);

        if (root1 == root2)
            return true; //cycle found beacause they belong to same set

        unionOperation(root1, root2, dsu);
    }

    // for (int i : dsu)
    //     std::cout << i << " ";
    // std::cout << std::endl;
    return false;
}

int32_t main()
{
    int E, V;
    std::cin >> E >> V;

    std::vector<std::pair<int, int>> graph;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        std::cin >> u >> v;
        graph.push_back({u, v});
    }

    if (isCycle(V, graph))
    {
        std::cout << "Cycle is detected!\n";
    }
    else
    {
        std::cout << "Cycle is not detected!\n";
    }

    return 0;
}