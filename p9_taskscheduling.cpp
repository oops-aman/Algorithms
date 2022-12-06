#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;

void taskScheduling1(int &machines, vector<pair<int, int>> exec)
{
    int tasks = exec.size();
    sort(exec.begin(), exec.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < machines; i++)
    {
        pq.push({0, i});
    }
    ll maxTime = 0;
    for (int i = 0; i < tasks; i++)
    {
        int m = pq.top().second, t = pq.top().first;
        pq.pop();
        cout << "Task  " << exec[i].second << " assigned to  machine" << m << " at time " << t << "  and completed at " << t + exec[i].first << "\n";
        pq.push({t + exec[i].first, m});
        maxTime = max(maxTime, 1ll * exec[i].first + t);
    }
    cout << "Completion time of all tasks by 1.5 Approx scheduling Algorithm  : "<< maxTime;
}
void taskScheduling2(int &machines, vector<pair<int, int>> exec)
{
    int tasks = exec.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < machines; i++)
    {
        pq.push({0, i});
    }
    ll maxTime = 0;
    for (int i = 0; i < tasks; i++)
    {
        int m = pq.top().second, t = pq.top().first;
        pq.pop();
        cout << "Task  " << exec[i].second << " assigned to machine  " << m << " at time " << t << "  and completed at " << t + exec[i].first << "\n";
        pq.push({t + exec[i].first, m});
        maxTime = max(maxTime, 1ll * exec[i].first + t);
    }
    cout << "Completion time of all tasks by 2 Approx scheduling Algorithm : "<< maxTime;
}
int main()
{
    int tasks, machines;
    cout << "Enter number of Machines : ";
    cin >> machines;
    cout << "Enter number of tasks  : ";
    cin >> tasks;
    vector<int> machTime(machines, 0);
    vector<pair<int, int>> exec;
    cout << "Enter the execution time of each task  : \n ";
    for (int i = 0; i < tasks; i++)
    {
        int tem;
        cin >> tem;
        exec.push_back({tem, i});
    }
    taskScheduling1(machines,exec);
    cout<<"\n\n";
    taskScheduling2(machines,exec);
}