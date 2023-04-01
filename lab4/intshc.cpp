#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool sortsec(const pair<int, int>&a,
             const pair<int, int>&b)
    {
        return (a.second < b.second);
    }


int main(){
    int n, st, en, ans = 1;
    cin >> n;
    vector <pair <int, int>> my_vec;
    for (int i = 0; i<n; i++){
        cin >> st >> en;
        my_vec.push_back({st,en});
    }
    sort(my_vec.begin(), my_vec.end(), sortsec);
    auto it = my_vec.begin();
    pair <int, int> before_my = my_vec.front();
    it ++;
    while(it != my_vec.end())
    {
        if ((*it).first < before_my.second)
        {
            it ++;
        } else{
            ans++;
            before_my = *it;
        }
    }
    cout << ans << "\n";
    return 0;
 }