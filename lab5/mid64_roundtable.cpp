#include <iostream>
#include <map>

using namespace std;

map<int, int> mm;
int my_arr[200001];
int check[200001];

int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        my_arr[i] = x - 1;
        mm[x - 1] = ((x - i - 1) % n);
        mm[x - 1] += n;
        mm[x - 1] %= n;
    }
    for (auto i : mm)
    {
        check[i.second]++;
    }
    int my_max = -9999;
    for (int i = 0; i < n; i++)
    {
        if (check[i] > my_max) {
            my_max = check[i];
        } else {
            my_max = my_max;
        }
    }
    cout << my_max << "\n";
    return 0;
}
