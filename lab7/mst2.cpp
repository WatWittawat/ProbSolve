#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct way
{
    int a;
    int b;
    int w;
};

bool com(way a, way b)
{
    return a.w < b.w;
}

int fS(int v, vector<int> &myarr)
{
    if (v == myarr[v])
        return v;
    return myarr[v] = fS(myarr[v], myarr);
}

void Uset(int a, int b, vector<int> &myarr)
{
    if (a != b)
        myarr[b] = a;
}

int main()
{
    int x, y;
    int a, b, w, res = 0;
    cin >> x >> y;
    vector<way> my_adj;
    for (int i = 0; i < y; i++)
    {
        cin >> a >> b >> w;
        my_adj.push_back({a - 1, b - 1, w});
    }
    sort(my_adj.begin(), my_adj.end(), com);
    vector<int> parent(x);
    for (int i = 0; i < x; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < y; i++)
    {
        int a = fS(my_adj[i].a, parent);
        int b = fS(my_adj[i].b, parent);
        if (a != b)
        {
            res += my_adj[i].w;
            Uset(a, b, parent);
        }
    }
    cout << res << endl;
    return 0;
}