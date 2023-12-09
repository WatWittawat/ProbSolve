#include <utility>
#include <vector>
#include <iostream>
#include <queue>

const int MYMAX = 100001;

using namespace std;

int n, x, y, z;

int dist[MYMAX][2] = {0};
int school[MYMAX] = {0};
int visited[MYMAX][2] = {0};


int main(){
    int w, u, v, p, res = 0;
    cin >> n >> x >> y >> z;
    vector<vector<pair<int, int>>> mG;
    vector<int> SL;
    mG.resize(n);
    for (int i = 0; i < y; i++)
    {
        cin >> w;
        school[w - 1] = 1;
        SL.push_back(w - 1);
    }
    for (int i = 0; i < x; i++)
    {
        cin >> u >> v >> p;
        mG.at(u - 1).push_back({v - 1, p});
        mG.at(v - 1).push_back({u - 1, p});
    }
    for (int i = 0; i < n; i++)
    {
        visited[i][0] = 0;
        visited[i][1] = 0;
        dist[i][0] = MYMAX;
        dist[i][1] = MYMAX;
    }
    dist[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        int now = q.front().first;
        q.pop();
        if (z < dist[now][0])
            continue;
        visited[now][0] = 1;
        for (auto i : mG[now]){
            int v = i.first;
            int mr = i.second;
            if (dist[v][0] > dist[now][0] + 1 ){
                if (mr == 0){
                    dist[v][0] = dist[now][0] + 1;
                    q.push({v, 0});
                }
            }
        }
    }
    for (auto a : SL)
    {
        if (visited[a][0])
        {
            dist[a][1] = dist[a][0];
            q.push({a, 1});
        }
    }
    while (!q.empty())
    {
        int now = q.front().first;
        visited[now][1] = 1;
        q.pop();
        if (z < dist[now][1])
        {
            continue;
        }
        for (auto i : mG[now])
        {
            int v = i.first;
            if (dist[v][1] > dist[now][1] + 1)
            {
                dist[v][1] = dist[now][1] + 1;
                q.push(i);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dist[i][0] != -1 && dist[i][1] != -1){
            if (z >= min(dist[i][0], dist[i][1])){
                res++;
            }
        }
        else if (dist[i][0] != -1){
            if(z >= dist[i][0]){
                res++;
            }
        }
        else if (dist[i][1] != -1){
            if(z >= dist[i][1]){
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}