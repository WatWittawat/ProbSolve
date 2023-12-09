#include <vector>
#include <iostream>
#include <queue>

#define INF 0xfffffff

using namespace std;

int DIT[100][100];
int miD[100][100];
int r, c;
int r1, c1, r2, c2;
int MYCO[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
char my_G[100][100];
int SEE[100][100];

vector<pair<int, int>> my_vec;
queue<pair<int, int>> q;

int main()
{
    cin >> r >> c;
    cin >> r1 >> c1 >> r2 >> c2;
    r1 = r1 - 1;
    r2 = r2 - 1;
    c1 = c1 - 1;
    c2 = c2 - 1;
    int mode = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> my_G[i][j];
            SEE[i][j] = 0;
            DIT[i][j] = 0;
            miD[i][j] = INF;
            if (my_G[i][j] == '*')
            {
                my_vec.push_back({i, j});
                my_vec.push_back({i, j});
            }
        }
    }
    for (auto &i : my_vec)
    {
        for (int k = 0; k < r; k++)
        {
            for (int j = 0; j < c; j++)
            {
                SEE[k][j] = 0;
                DIT[k][j] = 0;
            }
        }
        if (mode == 0 && my_G[i.first - 1][i.second] == '.' )
        {
            if(my_G[i.first + 1][i.second] == '.'){
                my_G[i.first][i.second] = '.';
            }
        }
        else if (mode == 1 && my_G[i.first][i.second + 1] == '.')
        {
            if (my_G[i.first][i.second - 1] == '.'){
                my_G[i.first][i.second] = '.';
            }
        }
        q.push({r1, c1});
        while (not q.empty())
        {
            int cr, cc;
            cr = q.front().first;
            cc = q.front().second;
            SEE[cr][cc] = 1;
            q.pop();
            if (cr == r2 && cc == c2)
            {
                break;
            }
            for (int j = 0; j < 4; j++)
            {
                if (my_G[cr + MYCO[0][j]][cc + MYCO[1][j]] == '.')
                {
                    if(!SEE[cr + MYCO[0][j]][cc + MYCO[1][j]]){
                        DIT[cr + MYCO[0][j]][cc + MYCO[1][j]] = DIT[cr][cc] + 1;
                        SEE[cr + MYCO[0][j]][cc + MYCO[1][j]] = 1;
                        q.push({cr + MYCO[0][j], cc + MYCO[1][j]});
                    }
                }
            }
        }
        if (miD[r2][c2] > DIT[r2][c2]){
            if (DIT[r2][c2] > 0){
                miD[r2][c2] = DIT[r2][c2];
            }
        }
        my_G[i.first][i.second] = '*';
        mode = (mode + 1) % 2;
    }
    if (miD[r2][c2] == INF)
        cout << -1 << "\n";
    else
        cout << miD[r2][c2] << "\n";
    return 0;
}