#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int maxtime, ontime;
    vector<pair<int, int>> my_vecline;
    for (int i = 0; i < n; i++)
    {
        cin >> maxtime >> ontime;
        my_vecline.push_back({maxtime, ontime});
    }
    sort(my_vecline.begin(), my_vecline.end());
    int tt = 0;
    int res = 0;
    for (auto &i : my_vecline)
    {
        tt += i.second;
        if (tt - i.first > 10)
        {
            if (res > (tt - i.first - 10) * 1000){
                res = res;
            } else {
                res = (tt - i.first - 10) * 1000;
            }
        }
    }
    cout << res;
    return 0;
}