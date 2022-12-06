#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

vector<int> vertexCover(vector<vector<int>> &edges,int v)
{
    vector<int> vc;
    while (edges.size())
    {
        int v= edges[0][0], u= edges[0][1];
        vc.push_back(u);
        vc.push_back(v);
        for (int i = 0; i <edges.size(); i++)
        {
            if (edges[i][0]==u||edges[i][0]==v||edges[i][1]==u||edges[i][1]==v)
            {
                edges.erase(edges.begin()+i);
                i--;
            }
        }
    }
    return vc;
}
int main()
{   
    int v,e;
    cout<<"Enter number of vertices and edges respectively : ";
    cin>>v>>e;
    vector<vector<int>> edges;
    for (int i = 0; i <e; i++)
    {
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    vector<int> VetrtCov= vertexCover(edges,v);
    cout<<"Vertex Cover: ";
    for(auto x: VetrtCov)
    cout<<x<<" ";
}