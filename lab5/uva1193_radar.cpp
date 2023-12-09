#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

bool chosecom(pair<double, double> &st, pair<double, double> &sc)
{
    if (st.second == sc.second) {
        return (st.first < sc.first);
    } else {
        return (st.second < sc.second);
    }
}

int main()
{
    int round = 1, j = 0;
    int n, d;
    double st, sc;
    while (1)
    {
        vector<pair<double, double>> my_vec;
        int count = 0;
        int valid = 1;
        cin >> n >> d;
        if (n == 0 && d == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (y > d)
            {
                valid = 0;
            }
            else
            {
                st = x - sqrt(d * d - y * y);
                sc = x + sqrt(d * d - y * y);
                my_vec.push_back({st, sc});
            }
        }
        if (valid)
        {
            sort(my_vec.begin(), my_vec.end(), chosecom);
            for (int i = 0; i < n; i = i)
            {
                j = 0;
                for (j = 0; j < n; j++)
                {
                    if (my_vec[j].first > my_vec[i].second)
                        break;
                }
                i = j;
                count++;
            }
            cout << "Case " << round << ": " << count << endl;
        }
        else
        {
            cout << "Case " << round << ": -1\n";
        }
        round++;
    }
    return 0;
}