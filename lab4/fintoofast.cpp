#include <iostream>
#include <vector>
#include <queue>

#define INF 0xfffffff

using namespace std;

struct my_map
{
    int w;
    int v;
    int e;
};

struct comp
{
    bool operator()(my_map const &way1, my_map const &way2)
    {
        return way1.w > way2.w;
    }
};

int shortest_path(vector<vector<my_map>> &GG, int GS, int S)
{
    int my_way[GS][2], rt[GS][2];
    priority_queue<my_map, vector<my_map>, comp> tmp;
    for (int i = 0; i < GS; i++)
    {
        my_way[i][0] = INF;
        my_way[i][1] = INF;
        rt[i][0] = 0;
        rt[i][1] = 0;
    }
    my_way[0][0] = 0;
    tmp.push({0, S, 0});
    while (!tmp.empty())
    {
        int rock = tmp.top().v;
        int cfe = tmp.top().e;
        tmp.pop();
        if (rt[rock][cfe])
            continue;
        rt[rock][cfe] = 1;
        for (auto &i : GG.at(rock))
        {
            int v = i.v;
            int w = i.w;
            int e = i.e;
            if (!e) {
                if (rt[v][cfe] == 0 && my_way[v][cfe] > my_way[rock][cfe] + w) {
                    my_way[v][cfe] = my_way[rock][cfe] + w;
                    tmp.push({my_way[v][cfe], v, cfe});
                }
            } else if (!cfe) {
                if (rt[v][1] == 0 && my_way[v][1] > my_way[rock][cfe] + w) {
                    my_way[v][1] = my_way[rock][cfe] + w;
                    tmp.push({my_way[v][1], v, 1});
                }
            }
        }
    } if (my_way[GG.size() - 1][0] == INF && my_way[GG.size() - 1][0] == INF) {
        return -1;
    }
    return min(my_way[GG.size() - 1][0], my_way[GG.size() - 1][1]);
}

int main()
{
    int n, m;
    int f, t, tim, Ie;
    cin >> n >> m;
    vector<vector<my_map>> graph;
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        cin >> f >> t >> tim >> Ie;
        graph.at(f - 1).push_back({tim, t - 1, Ie});
        graph.at(t - 1).push_back({tim, f - 1, Ie});
    }
    int sp = shortest_path(graph, graph.size(), 0);
    cout << sp << "\n";
    return 0;
}