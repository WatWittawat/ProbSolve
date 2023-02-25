#include <iostream>

using namespace std;

int row, column, ch_num;
bool check;
char my_map[35][35];
bool Walk[35][35];

void Check_move(int c_row, int c_column, char ss)
{
    Walk[c_row][c_column] = true;
    ch_num++;
    if (check == false && my_map[c_row][c_column] != ss)
    {
        if (my_map[c_row][c_column] == '*' || my_map[c_row][c_column] == '$')
        {
            check = true;
        }
    }
    if (Walk[c_row+1][c_column] == false && my_map[c_row+1][c_column] != '#' && c_row + 1 < row)
    {
        Check_move(c_row+1, c_column, ss);
    }
    if (Walk[c_row][c_column+1] == false && my_map[c_row][c_column+1] != '#' && c_column + 1 < column)
    {
        Check_move(c_row, c_column+1, ss);
    }
    if (Walk[c_row-1][c_column] == false && my_map[c_row-1][c_column] != '#' && c_row -1 > -1)
    {
        Check_move(c_row-1, c_column, ss);
    }
    if (Walk[c_row][c_column-1] == false && my_map[c_row][c_column-1] != '#' && c_column -1 > -1 )
    {
        Check_move(c_row, c_column-1, ss);
    }
}

int main(){
    int G1 = 0, G2 = 0;
    cin >> row >> column;
    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cin >> my_map[i][j];
            Walk[i][j] = false;
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (Walk[i][j] == false && (my_map[i][j] == '*' || my_map[i][j] == '$'))
            {
                Check_move(i, j, my_map[i][j]);
                if (check == true)
                {
                    G1 += ch_num;
                }
                else
                {
                    G2 += ch_num;
                }
            }
            check = false;
            ch_num = 0;
        }
    }
    cout << G1 << " " << G2 << "\n";
    return 0;
}