#include <iostream>
#include <vector>
#define INF 0xfffffff

using namespace std;

struct my_con
{
    int cw;
    int po;
    int wi;
};

int main()
{
    int n, l, my_min = INF, st, sc, th, my_t;
    vector<my_con> vec_conn;
    vector<int> cup;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> st >> sc >> th;
        vec_conn.push_back({st, sc, th});
    }
    for (int i = 0; i < l; i++)
    {
        cin >> my_t;
        cup.push_back(my_t);
    }
    for (auto i : vec_conn)
    {
        int my_total = i.cw;
        bool Ow;
        vector<vector<int>> res;
        vector<int> my_t;
        for (auto j : cup)
        {
            if (j > i.wi)
                Ow = true;
            int my_sum = 0;
            my_t.push_back(j);
            for (auto &i : my_t) {
                my_sum += i;
            }
            if (my_sum > i.wi)
            {
                my_t.pop_back();
                res.push_back(my_t);
                my_t.clear();
                my_t.push_back(j);
            }
        }
        res.push_back(my_t);
        my_t.clear();
        if (Ow) {
            Ow = false;
            continue;
        }
        my_total += res.size() * i.po;
        if (my_total < my_min){
            my_min = my_total;
        } else {
            my_min = my_min;
        }
    }
    cout << my_min << endl;
    return 0;
}