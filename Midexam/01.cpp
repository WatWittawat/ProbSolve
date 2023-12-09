#include <iostream>
#include <queue>
#include <utility>
#define INF 0xfffffff

using namespace std;

int mapp[31][31];
int vit[31][31];
int diss[31][31];
int myco[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};

int main()
{
    int r, c, a, b, x, y;
    cin >> r >> c >> a >> b >> x >> y;
    a = a -1;
    b = b -1;
    x = x -1;
    y = y -1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mapp[i][j];
            vit[i][j] = 0;
            diss[i][j] = INF;
        }
    }
    queue<pair<int, int>> q;
    queue<int> d;
    q.push({a, b});
    d.push(0);
    diss[a][b] = 0;
    while (not q.empty() and not d.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        int dis = d.front();
        q.pop();
        vit[row][col] = 1;
        for (int j = 0; j < 4; j++)
        {
            if (row + myco[0][j] < r and row + myco[0][j] >= 0 and col + myco[1][j] < c and col + myco[1][j] >= 0)
            {
                if (mapp[row][col] == mapp[row + myco[0][j]][col + myco[1][j]])
                {
                    if (diss[row + myco[0][j]][col + myco[1][j]] > diss[row][col] + dis)
                    {
                        diss[row + myco[0][j]][col + myco[1][j]] = diss[row][col] + dis;
                        q.push({row + myco[0][j], col + myco[1][j]});
                        d.push(dis);
                    }
                }
                else
                {
                    if (diss[row + myco[0][j]][col + myco[1][j]] > diss[row][col] + dis + 1)
                    {
                        diss[row + myco[0][j]][col + myco[1][j]] = diss[row][col] + dis + 1;
                        q.push({row + myco[0][j], col + myco[1][j]});
                        d.push(dis + 1);
                    }
                }
            }
        }
    }
    cout << diss[x][y] << endl;
    return 0;
}