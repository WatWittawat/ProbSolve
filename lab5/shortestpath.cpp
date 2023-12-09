#include <vector>
#include <iostream>
#include <utility>
#include <set>

#define INF 0xfffffff

using namespace std;

int main(){
    int n, m;
    int f, t, w;
    cin >> n >> m;
    vector<vector<pair<int, int>>> my_graph;
    my_graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        cin >> f >> t >> w;
        my_graph.at(f - 1).push_back({w, t - 1});
        my_graph.at(t - 1).push_back({w, f - 1});
    }
    set<pair<int, int>> priQ;
    vector<int> dist(my_graph.size(), INF);
    vector<bool> visit(my_graph.size(), false);
    priQ.insert({0, 0});
    dist.at(0) = 0;
    while (!priQ.empty())
    {
        int u = (*priQ.begin()).second;
        priQ.erase(priQ.begin());
        if (visit[u])
            continue;
        visit[u] = true;
        for (auto i : my_graph.at(u))
        {
            int v = i.second;
            int w = i.first;
            if (visit[v] == false && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                priQ.insert({dist[v], v});
            }
        }
    }
    cout << dist[my_graph.size() - 1] << endl;
    return 0;
}