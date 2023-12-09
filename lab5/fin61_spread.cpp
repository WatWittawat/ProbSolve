#include <cmath>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int Fs(int v, vector<int> &arr)
{
    if (v == arr[v])
        return v;
    return arr[v] = Fs(arr[v], arr);
}

void Uset(int x, int y, vector<int> &arr)
{
    if (x != y)
    {
        arr[y] = x;
    }
}

int main()
{
    int n, k,f, t, w, tmp = 0;
    double res;
    vector<int> sp;
    vector<tuple<double, int, int>> el;
    cin >> n >> k;
    sp.resize(n);
    for (int i = 0; i < n; i++)
        cin >> sp.at(i);
    for (int i = 0; i < k; i++)
    {
        cin >> f >> t >> w;
        tmp = ceil((0.0 + w) / (sp.at(f - 1) + sp.at(t - 1)));
        el.push_back({ceil(tmp), f - 1, t - 1});
    }
    sort(el.begin(), el.end());
    vector<int> sss;
    vector<tuple<double, int, int>> chosec;
    sss.resize(n);
    for (int i = 0; i < sss.size(); i++)
        sss[i] = i;
    for (auto i : el)
    {
        int u = Fs(get<1>(i), sss);
        int v = Fs(get<2>(i), sss);
        if (u != v)
        {
            chosec.push_back(i);
            Uset(u, v, sss);
            res = max(res, get<0>(i));
        }
    }
    cout << (int)res << "\n";
    return 0;
}