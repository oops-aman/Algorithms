#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;

void transitionFunction(string pat, vector<vector<int>> &delta)
{
    delta[0][pat[0]-'a'] = 1;
    int n = pat.size();
    // cout<<" Pater : "<<pat<<"\n";
    set<char> inputSymbols;
    for (auto x : pat)
        inputSymbols.insert(x);
    for (int i = 1; i <=n; i++)
    {
        // cout<<"I = "<<i<<"\n";
        for (auto c : inputSymbols)
        {
            // cout<<" c: "<<c<<" ";
            int k = min(n, i + 1);
            string tem = pat.substr(0, i) + c;
            int x = tem.size();
            while (k > 0 && tem.substr(x - k, k) != pat.substr(0, k))
            {
                k--;
            }
            delta[i][c - 'a'] = k;
            // cout<<k<<"  ";
        }
        // cout<<"\n";
    }
}

int StringMatcher(string text, string pat)
{
    int n = text.size();
    vector<vector<int>> delta(n + 1, vector<int>(26, 0));
    transitionFunction(pat, delta);
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        q = delta[q][text[i] - 'a'];
        // cout<<" q : "<<q<<"\n";
        if (q == pat.size())
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    string text, pattern;
    cout << "Enter the text : ";
    cin >> text;
    cout << "Enter the pattern : ";
    cin >> pattern;
    int res = StringMatcher(text, pattern);
    if (res == -1)
    {
        cout << "Pattern not found in the text .";
    }
    else
    {
        cout << "Pattern found at the index " << res - pattern.size() +1<< "\n";
    }
}