#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, p;
int my_co[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
int M[30][30];
int vit[30][30];

int main() {
    cin >> n >> p;
    int r = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vit[i][j] = 0;
            cin >> M[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        r = q.front().first;
        c = q.front().second;
        if (r == n - 1 && c == n - 1)
            break;
        q.pop();
        vit[r][c] = 1;
        for (int j = 0; j < 4; j++)
        {
            if (r + my_co[0][j] < n && c + my_co[1][j] < n && r + my_co[0][j] >= 0 && c + my_co[1][j] >= 0)
            {
                if (!vit[r + my_co[0][j]][c + my_co[1][j]])
                {
                    if (M[r][c] >= M[r + my_co[0][j]][c + my_co[1][j]])
                    {
                        vit[r + my_co[0][j]][c + my_co[1][j]] = 1;
                        q.push({r + my_co[0][j], c + my_co[1][j]});
                    }
                    else if (M[r + my_co[0][j]][c + my_co[1][j]] - M[r][c] <= p)
                    {
                        vit[r + my_co[0][j]][c + my_co[1][j]] = 1;
                        q.push({r + my_co[0][j], c + my_co[1][j]});
                    }
                }
            }
        }
    }
    if (r == n - 1 && c == n - 1)
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
    return 0;
}