#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;
void computePrefix(int pi[], int n, string pat)
{
    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        while (k > 0 && pat[k] != pat[i])
        {
            k = pi[k];
        }
        if (pat[k] == pat[i])
            k++;
        pi[i] = k;
    }
}
int main()
{
    string text, pat;
    cout << "Enter the text :";
    cin >> text;
    cout << "Enter the Pattern :";
    cin >> pat;
    int n = text.size(), m = pat.size();
    int pi[m];
    computePrefix(pi, m, pat);
    // cout << "Pi: ";
    // for (int i = 0; i < m; i++)
    // {
    //     cout << pi[i] << " ";
    // }
    // cout << "\n";
    int q = 0;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        while (q > 0 && pat[q] != text[i])
        {
            q = pi[q];
        }
        if (pat[q] == text[i])
        {
            q++;
        }
        if (q == m)
        {
            found = true;
            cout << "Pattern found at index " << i - m + 1 << "\n";
        }
    }
    if (!found)
    {
        cout << "Patern Not Found \n";
    }
}