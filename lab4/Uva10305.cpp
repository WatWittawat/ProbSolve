#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int ft = 1;

int main()
{
    int n, x, f, t;
    queue<int> q;
    while (true){
        cin >> n >> x;
        if (n == 0 and x == 0)
        {
            cout << endl;
            break;
        }
        if (ft > 1)
            cout << endl;
        ft++;
        vector<vector<int>> my_g;
        my_g.resize(n);
        int ind[n];
        for (int i = 0; i < n; i++){
            ind[i] = {0};
        }
        for (int i = 0; i < x; i++)
        {
            cin >> f >> t;
            my_g.at(f - 1).push_back(t - 1);
            ind[t - 1]++;
        }
        for (int i = 0; i < (int)my_g.size(); i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (not q.empty())
        {
            int current = q.front();
            q.pop();
            ans.push_back(current + 1);
            for (int i = 0; i < my_g.at(current).size(); i++)
            {
                ind[my_g.at(current).at(i)]--;
                if (ind[my_g.at(current).at(i)] == 0)
                    q.push(my_g.at(current).at(i));
            }
        }
        for (int i = 0; i < ans.size() - 1; i++)
        {
            cout << ans[i] << " ";
        }
        cout << ans[ans.size() - 1];
        ans.clear();
    }
    return 0;
}