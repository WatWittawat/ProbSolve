#include <iostream>

using namespace std;

int n;
int storage[100001][3];
pair<int, int> p[100001];

int ss(int my_id, int mm){
    if (storage[my_id][mm] != -1) {
        return storage[my_id][mm];
    }
    if (my_id >= n) {
        return 0;
    }
    else {
        int a = ss(my_id + 2, 0);
        int b = ss(my_id + 3, 0);
        int tmp = 0;
        if (a > b){
            tmp = a;
        } else {
            tmp = b;
        }
        storage[my_id][0] = p[my_id].first + tmp;
        return storage[my_id][0];
    }
    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
        storage[i][0] = -1;
        storage[i][1] = -1;
        storage[i][2] = -1;
    }
    int ans1 = max(ss(0, 0), ss(1, 0));
    cout << ans1 << "\n";
    return 0;
}
