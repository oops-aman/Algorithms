#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;

void PrimsMst(vector<vector<pair<ll, ll>>> graph)
{
    int v = graph.size();
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> wt(v, INT_MAX);
    vector<bool> inMst(v, false);
    vector<ll> par(v);
    par[0] = -1;
    pq.push({0, 0});
    wt[0] = 0;
    ll cost = 0;
    while (!pq.empty())
    {
        int u = pq.top().second, w = pq.top().first;
        pq.pop();
        if (!inMst[u])
        {
            cost += w;
        }
        inMst[u] = true;
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first, vwt = graph[u][i].second;
            if (!inMst[v] && wt[v] > (vwt))
            {
                wt[v] = vwt;
                par[v] = u;
                pq.push({wt[v], v});
            }
        }
    }
    cout << "MST : \n";
    for (int i = 1; i < v; i++)
    {
        cout << par[i] << "  -->  " << i << "\n";
    }
    cout << "\nCost : " << cost << "\n";
}
int main()
{
    int v;
    cout << "Enter number of vertices : ";
    cin >> v;
    vector<vector<pair<ll, ll>>> graph(v);
    cout << "Enter number of edges : ";
    int e;
    cin >> e;
    cout << "Enter the edges respectively : (U --> V of weight W as U, V, W ) \n ";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    PrimsMst(graph);
}