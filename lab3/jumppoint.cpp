#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

void bfs(int from, int too, int *visited, vector<int> *Graph, int GraphSize)
{
    queue<int> q;
    int last = 0;
    q.push(from);
    visited[from] = 1;
    int dist[GraphSize];
    for (int i = 0; i < GraphSize; i++)
    {
        dist[i] = 0;
    }
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        visited[current] = 1;
        for (int i = 0; i < Graph[current].size(); i++)
        {
            if (!visited[Graph[current].at(i)])
            {
                visited[Graph[current].at(i)] = 1;
                dist[Graph[current][i]] = dist[current] + 1;
                q.push(Graph[current].at(i));
                if (Graph[current].at(i) == too)
                {
                    last = 1;
                    break;
                }
            }
        }
        if (last)
        {
            break;
        }
    }
    if (dist[GraphSize - 1] == 0)
    {
        cout << -1;
    }
    else
    {
        cout << dist[GraphSize - 1];
    }
}

int main(){
    int node, jump;
    cin >> node >> jump;
    int mostjump = jump * jump;
    vector<pair<int, int>> point;
    vector<int> Graph[node + 2];
    int travelled[node + 2];
    int sizepoint = 2;
    int GraphSize = node + 2;
    for (int i = 0; i < node+2; i++)
    {
        travelled[i] = 0;
    }
    point.push_back({0, 0});
    for (int i = 0; i < node; i++)
    {
        int x, y;
        cin >> x >> y;
        point.push_back({x, y});
        sizepoint ++;
    }
    point.push_back({100, 100});
    for (int i = 0; i < sizepoint; i++)
    {
        for (int j = i; j < sizepoint; j++)
        {
            int z = pow(point.at(i).first - point.at(j).first, 2) + pow(point.at(i).second - point.at(j).second, 2);
            if (i == j)
            {
                continue;
            }
            if (z <= mostjump)
            {
                Graph[i].push_back(j);
                Graph[j].push_back(i);
            }
        }
    }
    bfs(0, GraphSize - 1, travelled, Graph, GraphSize);
    return 0;
}
