#include <iostream>

using namespace std;

int n;
int my_arr[100000];
int dp[100000] = {-1};

int jj(int my_id){
    if (my_id + 2 < n) {
        if (dp[my_id] == -1) {
            if (jj(my_id + 1) > jj(my_id + 3) + my_arr[my_id + 2]){
                dp[my_id] = jj(my_id + 1);
            } else{
                dp[my_id] = jj(my_id + 3) + my_arr[my_id + 2];
            }
        }
        return dp[my_id];
    }
    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        dp[i] = -1;
        cin >> my_arr[i];
    }
    cout << jj(0) << endl;
    return 0;
}
