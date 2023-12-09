#include <utility>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int node, way;
vector<pair<int, int>> my_vec;

bool is_bipartite(vector<vector<int>> &GG, int st, int *sk)
{
    queue<int> q;
    for (unsigned int i = st; i < GG.size(); i++) {
        if (GG.at(i).size() != 0 && sk[i] == -1) {
            sk[i] = 1;
            q.push(i);
            break;
        }
    }
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int i = 0; i < GG.at(current).size(); i++) {
            if (current == GG.at(current).at(i)) {
                return 0;
            } if (sk[GG.at(current).at(i)] == -1) {
                sk[GG.at(current).at(i)] = 1 - sk[current];
                q.push(GG.at(current).at(i));
            } else if (sk[current] == sk[GG.at(current).at(i)]) {
                return 0;
            }
        }
    }
    return 1;
}
bool isBipartite(int mode, pair<int, int> select)
{
    vector<vector<int>> GG;
    GG.resize(node);
    for (auto &i : my_vec)
    {
        if (select.first == i.first && select.second == i.second)
            continue;
        if (select.first == i.second && select.second == i.first)
            continue;
        else {
            GG.at(i.first).push_back(i.second);
            GG.at(i.second).push_back(i.first);
        }
    }
    int gate = 1;
    int my_ar[200000];
    for (int i = 0; i < GG.size(); i++)
        my_ar[i] = -1;
    for (int i = 0; i < GG.size(); i++) {
        if (GG.at(i).size() != 0 && my_ar[i] == -1) {
            gate = gate & is_bipartite(GG, i, my_ar);
            if (gate == 0) {
                return gate;
            }
        }
    }
    return gate;
}

int main() {
    cin >> node >> way;
    for (int i = 0; i < way; i++) {
        int f, t;
        cin >> f >> t;
        my_vec.push_back({f - 1, t - 1});
    }
    for (auto &i : my_vec)
    {
        if (isBipartite(1, i))
        {
            cout << i.first + 1 << " " << i.second + 1;
            cout << endl;
            break;
        }
    }
    return 0;
}
