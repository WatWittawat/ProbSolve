#include <iostream>

using namespace std;

int fs(int x, int *father) {
    if (father[x] == x)
        return x;
    else
        return father[x] = fs(father[x], father);
}

void Uset(int x, int y, int *father) {
    father[x] = y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    char c;
    int A, B;
    cin >> n >> q;
    int my_arr[n];
    for (int i = 0; i < n; i++)
        my_arr[i] = i;
    for (int i = 0; i < q; i++)
    {
        cin >> c >> A >> B;
        int x = fs(A - 1, my_arr);
        int y = fs(B - 1, my_arr);
        if (c == 'q')
        {
            if (x == y)
            {
                cout << "yes"
                     << "\n";
            }
            else
            {
                cout << "no"
                     << "\n";
            }
        }
        else
        {
            if (x != y)
            {
                Uset(x, y, my_arr);
            }
        }
    }
    return 0;
}