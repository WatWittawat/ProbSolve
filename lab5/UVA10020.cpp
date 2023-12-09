#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        n = n -1;
        int m, i = 1;
        cin >> m;
        vector<pair<int, int>> mycoo(1);
        vector<pair<int, int>> Mysec;
        int LL = 0, accex = 0, way =0;
        while (true)
        {
            cin >> mycoo.at(0).first >> mycoo.at(0).second;
            if (mycoo.at(0).first == 0 && mycoo.at(0).second == 0)
                break;
            else
                mycoo.push_back({mycoo.at(0).first, mycoo.at(0).second});
        }
        sort(mycoo.begin() + 1, mycoo.end());
        while (accex < m)
        {
            int lastedL = LL;
            for (; i < mycoo.size(); i++)
            {
                if (mycoo.at(i).first > LL)
                    break;
                else if (mycoo.at(i).second >= lastedL) {
                    lastedL = mycoo.at(i).second;
                    way = i;
                }
            }
            if (way == 0)
                break;
            Mysec.push_back(mycoo.at(way));
            LL = accex = lastedL;
        }
        if (accex >= m)
        {
            cout << Mysec.size() << "\n";
            for (auto i : Mysec)
                cout << i.first << " " << i.second << "\n";
        }
        else
            cout << 0 << endl;
        if (n)
            cout << endl;
    }
    return 0;
}