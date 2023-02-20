#include <iostream>

using namespace std;

int main(){
    int n, indexx, num, keep1, keep2, e;
    cin >> n;
    int ans[n+1], check[n+1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = 0;
        check[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        cin >> num >> indexx;
        if (ans[indexx] == 0)
            ans[indexx] = num;
        else 
        {
            keep1 = ans[indexx];
            keep2 = num;
            ans[indexx] = num;
            while (ans[keep2] != 0)
                keep2 = ans[keep2];
            ans[keep2] = keep1;
        }
        check[num] = 1;
    }
    for (int i = 1; i<n; i++)
        if (check[i] == 0)
            e = i;
    cout << e;
    
    for (int i = 1; i<n ;i++)
    {
        cout << " " << ans[e];
        e = ans[e];
    }
    cout << "\n";
}