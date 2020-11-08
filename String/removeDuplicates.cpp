//practice.geeksforgeeks.org/problems/remove-duplicates3034/1
#include <iostream>
#include <string>
using namespace std;

string removeDups(string S)
{
    // Your code goes here
    string ans;
    int a[26] = {0};

    for (int i = 0; i < S.size(); i++)
    {
        if (a[S[i] - 'a'] == 0)
        {
            ans += S[i];
        }
        a[S[i] - 'a']++;
    }

    return ans;
}

int main()
{
    string S;
    cin >> S;
    string ans = removeDups(S);
    cout << ans << endl;
}