#include <vector>
#include <iostream>
#include <queue>
#define INF 0xfffffff

using namespace std;

int lst[200010];
int travel[200000] = {0};
queue<int> q;

void bfs(vector<int> f, int *travel, vector<vector<int>> &G, int GS, vector<int> &fac)
{
    for (auto &i : f) {
        q.push(i);
        travel[i] = 1;
    }
    vector<int> dit;
    dit.resize(GS, 0);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        travel[current] = 1;
        for (unsigned int i = 0; i < G[current].size(); i++) {
            if (!travel[G[current].at(i)]) {
                travel[G[current].at(i)] = 1;
                dit[G[current][i]] = dit[current] + 1;
                q.push(G[current].at(i));
            }
        }
    }
    for (auto &j : fac)
        if (lst[j] < dit[j]){
            lst[j] = lst[j];
        } else{
            lst[j] = dit[j];
        }
}

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<int> fac, vill;
    vector<vector<int>> my_graph;
    my_graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        int f, t;
        cin >> f >> t;
        my_graph.at(f - 1).push_back(t - 1);
        my_graph.at(t - 1).push_back(f - 1);
    }
    for (int i = 0; i < s; i++)
    {
        int tmp;
        cin >> tmp;
        vill.push_back(tmp - 1);
    }
    for (int i = 0; i < t; i++)
    {
        int tmp;
        cin >> tmp;
        lst[tmp - 1] = INF;
        fac.push_back(tmp - 1);
    }
    bfs(vill, travel, my_graph, my_graph.size(), fac);
    for (auto &i : fac)
    {
        cout << lst[i] << "\n";
    }
    return 0;
}