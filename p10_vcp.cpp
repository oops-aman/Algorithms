#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;

bool cmp(vector<int> a, vector<int> b)
{
    return a.size() >= b.size();
}
vector<vector<int>> setCover(vector<int> unvSet, vector<vector<int>> subsets)
{
    int n = unvSet.size();
    map<int, bool> mp;
    for (int i = 0; i < n; i++)
    {
        mp[unvSet[i]] = false;
    }
    vector<vector<int>> res;
    sort(subsets.begin(), subsets.end(), cmp);
    for (int i = 0; i < subsets.size(); i++)
    {
        for (int j = 0; j < subsets[i].size(); j++)
        {
            mp[subsets[i][j]] = true;
        }
        res.push_back(subsets[i]);
        bool tem = true;
        for (auto m : mp)
        {
            tem = tem & m.second;
        }
        if (tem)
        {
            // break;
            return res;
        }
    }
    return {{}};
}
int main()
{
    int n;
    cout << "Enter the size of universal set: ";
    cin >> n;
    vector<int> unvSet(n);
    cout << "Enter the elements of universal set : ";
    for (int i = 0; i < n; i++)
    {
        cin >> unvSet[i];
    }
    int nsbsets;
    cout << "Enter number of subsets : ";
    cin >> nsbsets;
    vector<vector<int>> subsets;
    cout << "Enter all the subsets : (size ,then elements of subset ) \n : ";
    for (int i = 0; i < nsbsets; i++)
    {
        int t;
        cin >> t;
        vector<int> temp(t);
        for (int j = 0; j < t; j++)
        {
            cin >> temp[j];
        }
        subsets.push_back(temp);
    }
    auto res = setCover(unvSet, subsets);
    cout << "Set Cover : \n";
    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
}