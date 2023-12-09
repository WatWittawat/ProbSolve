    #include <iostream>
    #include <map>
    #include <vector>

    using namespace std;

    map<pair<int, int>, int> mm;

    int tarotora(int id, int maxd, vector<pair<int, int>> &s, int d)
    {
        if (d > maxd || d < maxd * -1)
            return 0xfffffff;
        if (id == s.size())
            return 0;
        if (mm.find({id, d}) != mm.end())
            return mm[{id, d}];
        int a = s[id].first + tarotora(id + 1, maxd, s, d + 1);
        int b = s[id].second + tarotora(id + 1, maxd, s, d - 1);
        // mm[{id, d}] = min(a, b);
        if (a < b){
            mm[{id,d}] = a;
        } else{
            mm[{id,d}] = b;
        }
        return min(a, b);
    }

    int main() {
        vector<pair<int, int>> a;
        int r, t, p;
        cin >> r;
        for (int i = 0; i < r; i++) {
            cin >> t >> p;
            for (int j = 0; j < t; j++) {
                int x, y;
                cin >> x >> y;
                a.push_back({x, y});
            }
            cout << tarotora(0, p, a, 0) << endl;
            a.clear();
            mm.clear();
        }
        return 0;
    }
