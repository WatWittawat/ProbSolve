#include <vector>
#include <iostream>

using namespace std;

struct WIN
{
    int st;
    int ee;
    int pf;
};

int main()
{
    int n;
    vector<int> res;
    cin >> n;
    vector<WIN> WS(n);
    int My_max[n];
    vector<int> chose[n];
    for (int i = 0; i < n; i++){
        cin >> WS[i].st >> WS[i].ee >> WS[i].pf;
    }
    for (int i = 0; i < n; i++){
        My_max[i] = WS[i].pf;
        chose[i].push_back(i);
        for (int j = 0; j < i; j++){
            if (WS[j].ee <= WS[i].st){
                if (My_max[i] < My_max[j] + WS[i].pf){
                    My_max[i] = My_max[j] + WS[i].pf;
                    chose[i] = chose[j];
                    chose[i].push_back(i);
                }
            }
        }
    }
    int fMax = 0;
    for (int i = 0; i < n; i++){
        if (fMax < My_max[i]){
            fMax = My_max[i];
            res = chose[i];
        }
    }
    cout << fMax << endl;
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++){
        cout << res[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}