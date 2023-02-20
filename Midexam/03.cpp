#include <iostream>
#include <list>

using namespace std;

int main(){
    long long int n;
    cin >> n;
    long long int num[n], check[n-1], diff = 0;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n - 1; i++)
    { 
        diff = abs(num[i] - num[i + 1]);
        check[i] = diff;
    }
    long long int maxx = -9999 ,minn = 9999, my_inmax, my_inmin;
    for (int i = 0; i < n-1; i++)
    {
        if (check[i] > maxx)
        {
            maxx = check[i];
            my_inmax  = i;
        }
        if (check[i] < minn)
        {
            minn = check[i];
            my_inmin = i;
        }
    }
    //cout << my_inmax << endl;
    //cout << my_inmin;
    long long int f = num[my_inmax], s = num[my_inmin], ans = 0;
    num[my_inmax] = s;
    for (int i = 0; i < n - 1; i++)
    { 
        diff = abs(num[i] - num[i + 1]);
        ans += diff;
    }
    cout << ans << endl;
    //for (int i = 0; i < n; i++)
    //   cout << num[i] << endl;
}