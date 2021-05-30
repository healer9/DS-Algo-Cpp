//hack.codingblocks.com/app/contests/1211/211/problem
#include <iostream>
#include <vector>
#include <algorithm>
#include "stack"
#include "climits"
using namespace std;

#define int long long

int largest_rectangular_area_using_stack(vector<int> &height, int n)
{
    stack<int> index;
    vector<int> left_limit(n);

    index.push(0);
    left_limit[0] = index.top();

    for (int i = 1; i < n; i++)
    {
        if (height[index.top()] >= height[i])
        {
            while (!index.empty() and height[index.top()] >= height[i])
            {
                index.pop();
            }
            index.empty() ? left_limit[i] = 0 : left_limit[i] = index.top() + 1;
            index.push(i);
        }
        else
        {
            left_limit[i] = index.top() + 1;
            index.push(i);
        }
    }

    // for (int i : left_limit)
    //     std::cout << i << " ";
    // std::cout << endl;

    while (!index.empty())
        index.pop();

    vector<int> right_limit(n);

    index.push(n - 1);
    right_limit[n - 1] = index.top();

    for (int i = n - 2; i >= 0; i--)
    {
        if (height[index.top()] >= height[i])
        {
            while (!index.empty() and height[index.top()] >= height[i])
            {
                index.pop();
            }
            index.empty() ? right_limit[i] = (n - 1) : right_limit[i] = index.top() - 1;
            index.push(i);
        }
        else
        {
            right_limit[i] = index.top() - 1;
            index.push(i);
        }
    }

    // for (int i : right_limit)
    //     std::cout << i << " ";
    // std::cout << endl;

    int max_area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int width = right_limit[i] - left_limit[i] + 1;
        max_area = max(max_area, height[i] * width);
    }

    return max_area;
}

int largest_rectangular_area(vector<int> &height, int n)
{
    vector<int> area(n);

    for (int i = 0; i < n; i++)
    {
        int left = i;
        while (left >= 0 and height[left] >= height[i])
        {
            left--;
        }

        left++;

        int right = i;
        while (right < n and height[right] >= height[i])
        {
            right++;
        }

        right--;

        // cout<<i<<"->"<<right<<" "<<left<<endl;
        int width = (right - left + 1);
        area[i] = height[i] * width;
    }
    // for(int i : area)
    // 	cout<<i<<" ";
    // cout<<endl;
    int max_area = *max_element(area.begin(), area.end());

    return max_area;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> height(n);

    for (int &i : height)
        cin >> i;

    std::cout << largest_rectangular_area(height, n) << endl;
    std::cout << largest_rectangular_area_using_stack(height, n) << endl;
    return 0;
}