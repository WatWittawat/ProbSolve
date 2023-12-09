#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct MMV
{
    int n;
    int c;
};

struct now
{
    int MMV;
    int cc;
};

int see[60001][3];
int my_dist[60001][3];
vector<vector<MMV>> my_graph;
int n, m, x, y;
queue<now> q;

int main()
{
    cin >> n >> m >> x >> y;
    x = x -1;
    y = y -1;
    my_graph.resize(n);
    int df, tt, ccc, my_min = 0xfffffff;
    for (int i = 0; i < m; i++)
    {
        cin >> df >> tt >> ccc;
        my_graph.at(df - 1).push_back({tt - 1, ccc});
        my_graph.at(tt - 1).push_back({df - 1, ccc});
    }
    for (int i = 0; i < n; i++)
    {
        see[i][0] = 0;
        see[i][1] = 0;
        see[i][2] = 0;
    }
    for (int i = 0; i<n; i++){
        my_dist[i][0] = 0;
        my_dist[i][1] = 0;
        my_dist[i][2] = 0;
    }
    q.push({x, 0});
    while (! q.empty())
    {
        int now = q.front().MMV;
        int cc = q.front().cc;
        q.pop();
        see[now][cc] = 1;
        for (auto &i : my_graph.at(now))
        {
            if (i.c == 0 )
            {
                if(! see[i.n][cc]){
                    my_dist[i.n][cc] = my_dist[now][cc] + 1;
                    see[i.n][cc] = 1;
                    q.push({i.n, cc});
                }
            }
            else if (i.c > 0 && cc == 0)
            {
                if(! see[i.n][i.c]){
                my_dist[i.n][i.c] = my_dist[now][cc] + 1;
                see[i.n][i.c] = 1;
                q.push({i.n, i.c});
                }
            }
            else if (cc > 0 && i.c == cc)
            {
                if(! see[i.n][cc]){
                my_dist[i.n][cc] = my_dist[now][cc] + 1;
                see[i.n][cc] = 1;
                q.push({i.n, cc});
                }
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (my_dist[y][i] < my_min && my_dist[y][i] != 0)
            my_min = my_dist[y][i];
    }
    if (my_min == 0xfffffff)
        cout << -1 << "\n";
    else
        cout << my_min << "\n";
    return 0;
}