#include <set>
#include <vector>
#include <iostream>

using namespace std;

int ver, e;
set<pair<int, pair<int, int>>> myway;

int fs(int v, vector<int> &my_arr)
{
    if (v == my_arr[v])
        return v;
    return my_arr[v] = fs(my_arr[v], my_arr);
}

void Us(int a, int b, vector<int> &my_arr)
{
    if (a != b)
        my_arr[b] = a;
}

int main()
{
    cin >> ver >> e;
    int f, t, w;
    vector<int> my_vec(ver);
    for (int i = 0; i < e; i++){
        cin >> f >> t >> w;
        myway.insert({w, {f - 1, t - 1}});
        for (int i = 0; i < ver; i++)
            my_vec[i] = i;
        int res = 0;
        for (auto &i : myway) {
            int a = fs(i.second.first, my_vec);
            int b = fs(i.second.second, my_vec);
            if (a != b)
            {
                Us(a, b, my_vec);
                res += i.first;
            }
        }
        for (int i = 0; i < ver - 1; i++){
            if (fs(i, my_vec) == fs(i + 1, my_vec))
                continue;
            else
                res = -1;
        }
        cout << res << "\n";
    }
    return 0;
}