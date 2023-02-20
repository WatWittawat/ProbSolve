#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int main(){
    int l,n,x,y;
    cin >> l >> n;
    set<int> pin;
    vector<pair<int,int>> tmp;
    vector<int> check;
    for (auto i = 0; i<n; i++)
    {
        cin >> x >> y;
        tmp.push_back({x,y});
        pin.insert(x);
        pin.insert(y);
    }
    for (auto i = pin.begin(); i != pin.end(); i++)
    {
        check.push_back(*i);
    }
    int maxx = -99999;
    for (int i =0; i < check.size() - 1; i++)
    {
        float cal = (check[i] + check[i+1])/2.0;
        int nub = 0;
        for (int j = 0; j<tmp.size(); j++)
        {
            if (cal >= tmp.at(j).first && cal <= tmp.at(j).second)
                {
                    nub +=1;
                }
        }
        if (nub > maxx)
            maxx = nub;
    }
    cout << maxx << endl;
    return 0;

}