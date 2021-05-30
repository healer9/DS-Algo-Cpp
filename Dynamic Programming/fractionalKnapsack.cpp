//hack.codingblocks.com/app/contests/1289/328/problem
#include <bits/stdc++.h>
using namespace std;

float fractionalKnapsack(vector<pair<int, int>> &v, int &cap)
{
    float profit = 0;
    float fcapacity = (float)cap * 1.0;
    // cout << fcapacity << endl;
    vector<pair<float, pair<float, float>>> temp;

    for (auto i : v)
        temp.push_back({i.first / (i.second * 1.0), {i.first * 1.0, i.second * 1.0}});

    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());

    // for (auto i : temp)
    //     cout << i.first << " " << i.second.first << " " << i.second.second << endl;

    float newCap = 0;
    for (int i = 0; i < (int)temp.size(); i++)
    {
        // if (fcapacity >= temp[i].second.second)
        if (newCap + temp[i].second.second < fcapacity)
        {
            newCap += temp[i].second.second;
            profit += temp[i].second.first;
        }
        else
        {
            // fcapacity -= (fcapacity / temp[i].second.second);
            float ratio = (fcapacity - newCap) / temp[i].second.second;
            // cout << "r = " << ratio << endl;
            // newCap += abs(fcapacity - newCap);
            profit += temp[i].second.first * ratio;
            break;
        }
    }
    return profit;
}

int main(int argc, char *argv[])
{
    int n, capacity;
    cin >> n >> capacity;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int p, w;
        cin >> p >> w;
        v.push_back({p, w});
    }

    // cout << setprecision(1) << fractionalKnapsack(v, capacity) << endl;
    printf("%0.1f\n", fractionalKnapsack(v, capacity));
    return 0;
}