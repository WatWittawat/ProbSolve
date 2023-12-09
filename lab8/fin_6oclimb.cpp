#include <iostream>
#include <queue>

using namespace std;

int R, C;
char MM[41][41];
int visited[41][41] = {{0}};

void bfs(int row, int col)
{
    int DIT[31][31];
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            DIT[i][j] = 0xffffff;
    }
    DIT[row][col] = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        if (x - 1 >= 0 && MM[x - 1][y] == '.' && DIT[x - 1][y] > DIT[x][y] + 5)
        {
                DIT[x - 1][y] = DIT[x][y] + 5;
                q.push(make_pair(x - 1, y));
        }
        if (x + 1 < R && MM[x + 1][y] == '.')
        {
            if (DIT[x + 1][y] > DIT[x][y] + 0)
            {
                DIT[x + 1][y] = DIT[x][y] + 0;
                q.push(make_pair(x + 1, y));
            }
        }
        if (y - 1 >= 0 && MM[x][y - 1] == '.' && DIT[x][y - 1] > DIT[x][y] + 1) 
        {
                DIT[x][y - 1] = DIT[x][y] + 1;
                q.push(make_pair(x, y - 1));
        }
        if (y + 1 < C && MM[x][y + 1] == '.')
        {
            if (DIT[x][y + 1] > DIT[x][y] + 1)
            {
                DIT[x][y + 1] = DIT[x][y] + 1;
                q.push(make_pair(x, y + 1));
            }
        }
    }
    if (DIT[0][C - 1] != 0xffffff)
        cout << DIT[0][C - 1] << "\n";
    else
        cout << -1 << "\n";
}

int main()
{
    int row, col;
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cin >> MM[i][j];
    }
    R = row;
    C = col;
    bfs(row - 1, 0);
    return 0;
}