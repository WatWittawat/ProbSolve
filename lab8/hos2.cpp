#include <queue>
#include <vector>
#include <iostream>
#include <map>

#define INF 0xfffffff

using namespace std;

int main()
{
    vector<vector<int>> my_graph;
    int n, m, k, h;
    cin >> n >> m >> k >> h;
    int types[2] = {60, 30}, hos[n], visited[n][2], dist[n][2], z, o;
    vector<int> hoslst;
    h *= 60;
    for (int i = 0; i < n; i++)
    {
        dist[i][0] = INF;
        dist[i][1] = INF;
        visited[i][0] = 0;
        visited[i][1] = 0;
        hos[i] = -1;
    }
    my_graph.resize(n);
    for (int i = 0; i < k; i++)
    {
        cin >> z;
        hos[z - 1] = 0;
        hoslst.push_back(z - 1);
    }
    for (auto i : hoslst)
    {
        cin >> z;
        hos[i] = z;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> o >> z;
        my_graph.at(o - 1).push_back(z - 1);
        my_graph.at(z - 1).push_back(o - 1);
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        if (hos[i] != -1)
        {
            q.push({i, hos[i]});
            dist[i][hos[i]] = 0;
        }
    }
    while (!q.empty())
    {
        int current = q.front().first;
        int type = q.front().second;
        q.pop();
        if (dist[current][type] == h || visited[current][type])
            continue;
        visited[current][type] = 1;
        for (auto &i : my_graph.at(current))
        {
            if (dist[i][type] > dist[current][type] + types[type])
            {
                dist[i][type] = dist[current][type] + types[type];
                q.push({i, type});
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (min(dist[i][0], dist[i][1]) != INF)
            count++;
    }
    cout << count << "\n";
    return 0;
}