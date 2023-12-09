#include <iostream>

using namespace std;

char my_g[21][21];
bool view[21][21] = {false};
int nu, pq;
int sa, ss, dd, cc;

int dfs(int r, int c, int dr)
{
    view[r][c] = 1;
    if (r == dd && c == cc)
        return 1;
    if (r + 1 < nu && !view[r + 1][c])
    {
        if(my_g[r + 1][c] == '.'){
            if (dfs(r + 1, c, dr))
                return 1;
        }
    }
    if (dr == 0 && r + 1 < nu && !view[r + 1][c])
    {
        if(my_g[r + 1][c] == 'O'){
        dr = 1;
        if (dfs(r + 1, c, dr))
            return 1;
        dr = 0;
        }
    }
    if (r - 1 >= 0 && ! view[r - 1][c])
    {
        if(my_g[r - 1][c] == '.'){
            if (dfs(r - 1, c, dr))
                return 1;
        }
    }
    if (dr == 0 && r - 1 >= 0 && ! view[r - 1][c])
    {
        if(my_g[r - 1][c] == 'O'){
            dr = 1;
            if (dfs(r - 1, c, dr))
                return 1;
            dr = 0;
        }
    }
    if (c + 1 < nu && ! view[r][c + 1])
    {
        if(my_g[r][c + 1] == '.'){
            if (dfs(r, c + 1, dr))
                return 1;
        }
    }
    if (dr == 0 && c + 1 < nu && ! view[r][c + 1] )
    {
        if(my_g[r][c + 1] == 'O'){
            dr = 1;
            if (dfs(r, c + 1, dr))
                return 1;
            dr = 0;
        }
    }
    if (c - 1 >= 0 && ! view[r][c - 1])
    {
        if(my_g[r][c - 1] == '.'){
            if (dfs(r, c - 1, dr))
                return 1;
        }
    }
    if (dr == 0 && c - 1 >= 0 && ! view[r][c - 1])
    {
        if(my_g[r][c - 1] == 'O'){
            dr = 1;
            if (dfs(r, c - 1, dr))
                return 1;
            dr = 0;
        }
    }
    return 0;
}

int main()
{
    cin >> nu >> pq;
    for (int i = 0; i < nu; i++)
    {
        for (int j = 0; j < nu; j++)
            cin >> my_g[i][j];
    }
    for (int i = 0; i < pq; i++)
    {
        cin >> sa >> ss >> dd >> cc;
        sa -= 1;
        ss -= 1;
        dd -= 1;
        cc -= 1;
        for (int i = 0; i < nu; i++)
        {
            for (int j = 0; j < nu; j++)
                view[i][j] = 0;
        }
        if (dfs(sa, ss, 0))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}