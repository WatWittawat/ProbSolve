#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,k,res;
    cin >> n >> k;
    int ar[n];
    for (int i = 0; i<n; i++)
        cin >> ar[i];
    sort(ar,ar+n);
    for (int i = 1; i<n; i++)
    {
        if (k * ar[0] <= (k-1)*ar[i])
        {
            res = i;
            break;
        }
    }
    cout << res << "\n";
}