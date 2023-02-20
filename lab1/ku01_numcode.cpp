#include <iostream>

using namespace std;

int main(){
    int n,t;
    cin >> n >> t;
    int ar[n], res = 0, newar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    if (t == 1)
        {
        res = n;
        for (int i = 0; i < n; i++)
            {
                if (ar[i] == res - 1)
                    {
                        cout << 0 << "\n";
                        res = res - 1;
                    }
                else if (ar[i] == res + 1)
                    {
                        cout << 1 << "\n";
                        res = res + 1;
                    }
            }
        }
    else if (t == 2)
        {
            newar[0] = ar[0];
            for (int i = 1; i < n; i++)
            {
                if (newar[i-1]*2 > ar[i])
                {
                    newar[i] = ar[i] - newar[i-1];
                    //cout << 1 << endl;
                }
                else if (newar[i-1] * 2 < ar[i])
                {
                    newar[i] = ar[i] - newar[i-1]*2;
                    //cout << 2 << endl;
                }  
            }
            res = n;
            for (int i = 0; i < n; i++)
            {
                if (newar[i] == res - 1)
                    {
                        cout << 0 << "\n";
                        res = res - 1;
                    }
                else if (newar[i] == res + 1)
                    {
                        cout << 1 << "\n";
                        res = res + 1;
                    }
            }

        }
    return 0;
}