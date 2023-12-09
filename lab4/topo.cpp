#include <iostream>
#include <list>
#include <vector>

using namespace std;

bool topo_sort(vector<vector<int>> &G, list<int> &ves, vector<int> &TP, int *deg)
{
    int tmp = 0;
    while (!ves.empty())
    {
        int now = ves.front();
        ves.pop_front();
        TP.push_back(now);
        for (int i = 0; i < G.at(now).size(); i++)
        {
            deg[G.at(now).at(i)]--;
            if (deg[G.at(now).at(i)] == 0)
                ves.push_back(G.at(now).at(i));
        }
        tmp++;
    }
    if (tmp != (int)G.size())
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int nd, wa;
    vector<vector<int>> G;
    vector<int> TP;
    list<int> ver_in;
    cin >> nd >> wa;
    G.resize(nd);
    int my_in[nd];
    int myout[nd];
    for (int i = 0; i < nd; i++){
        my_in[i] = 0;
    }
    for (int i = 0; i < nd; i++){
        myout[i] = 0;
    }
    for (int i = 0; i < wa; i++)
    {
        int from, too;
        cin >> from >> too;
        G.at(from - 1).push_back(too - 1);
        my_in[too - 1] += 1;
        myout[from - 1] += 1;
    }
    for (int i = 0; i < nd; i++)
    {
        if (my_in[i] == 0)
            ver_in.push_back(i);
    }
    if (topo_sort(G, ver_in, TP, my_in))
    {
        for (auto &i : TP)
            cout << i + 1 << endl;
    }
    else
        cout << "no" << endl;
    return 0;
}