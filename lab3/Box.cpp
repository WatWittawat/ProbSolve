#include <iostream>

using namespace std;

int r, c;
char Table[35][35];
bool Walk[35][35] = {{false}};

// check move
bool check_move(int row1,int row2, int column1, int column2){
    Walk[row1][column1] = true;
    Walk[row1][column2] = true;
    Walk[row2][column1] = true;
    Walk[row2][column2] = true;
    // check BoRDer
    if (Table[row2][column1] == 'B' && Table[row2][column2] == 'B')
    {
        return true;
    }
    // check move DOWN
    if (row1 + 1 < r && row2 + 1 < r)
    {
        if  (!(Walk[row1 + 1][column1] && Walk[row2 + 1][column1] && Walk[row1 + 1][column2] && Walk[row2 + 1][column2]))
        {
            if ((((Table[row1 + 1][column1] == '.') || (Table[row1 + 1][column1] == 'B')) && ((Table[row1 + 1][column2] == '.') || (Table[row1 + 1][column2] == 'B')) && ((Table[row2 + 1][column1] == '.') || (Table[row2 + 1][column1] == 'B')) && ((Table[row2 + 1][column2] == '.') || (Table[row2 + 1][column2] == 'B'))))
            {
                if (check_move(row1 + 1, row2 + 1, column1, column2))
                {
                    return true;
                }
            }
        }
    }
    // check move UP
    if (row1 - 1 >= 0 && row2 - 1 >= 0)
    {
        if (!(Walk[row1 - 1][column1] && Walk[row2 - 1][column1] && Walk[row1 - 1][column2] && Walk[row2 - 1][column2]))
        {
            if ((((Table[row1 - 1][column1] == '.') || (Table[row1 - 1][column1] == 'B')) && ((Table[row1 - 1][column2] == '.') || (Table[row1 - 1][column2] == 'B')) && ((Table[row2 - 1][column1] == '.') || (Table[row2 - 1][column1] == 'B')) && ((Table[row2 - 1][column2] == '.') || (Table[row2 - 1][column2] == 'B'))))
            {
                if (check_move(row1 - 1, row2 - 1, column1, column2))
                {
                    return true;
                }
            }
        }
    }
    // check move RIGHT
    if (column1 + 1 < c && column2 + 1 < c)
    {
        if (!(Walk[row1][column1 + 1] && Walk[row2][column1 + 1] && Walk[row1][column2 + 1] && Walk[row2][column2 + 1]))
        {
            if ((((Table[row1][column1 + 1] == '.') || (Table[row1][column1 + 1] == 'B')) && ((Table[row1][column2 + 1] == '.') || (Table[row1][column2 + 1] == 'B')) && ((Table[row2][column1 + 1] == '.') || (Table[row2][column1 + 1] == 'B')) && ((Table[row2][column2 + 1] == '.') || (Table[row2][column2 + 1] == 'B'))))
            {
                if (check_move(row1, row2, column1 + 1, column2 + 1))
                {
                    return true;
            }
            }
        }
    }
    // check move LEFT
   if (column1 - 1 >= 0 && column2 - 1 >= 0)
    {
        if (!(Walk[row1][column1 - 1] && Walk[row2][column1 - 1] && Walk[row1][column2 - 1] && Walk[row2][column2 - 1]))
        {
            if ((((Table[row1][column1 - 1] == '.') || (Table[row1][column1 - 1] == 'B')) && ((Table[row1][column2 - 1] == '.') || (Table[row1][column2 - 1] == 'B')) && ((Table[row2][column1 - 1] == '.') || (Table[row2][column1 - 1] == 'B')) && ((Table[row2][column2 - 1] == '.') || (Table[row2][column2 - 1] == 'B'))))
            {
                if (check_move(row1, row2, column1 - 1, column2 - 1))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// Get_input
void get_input(int r, int c)
{
    for (int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
        {
            cin >> Table[i][j];
        }
    for (int i = 0; i < c; i++)
        Table[r-1][i] = 'B'; // Border
}

int main(){
    cin >> r >> c;
    get_input(r, c);
    bool check = false;
    for (int i = 0; i < c-1; i++)
    {
        if (Table[0][i] == '.' && Table[0][i + 1] == '.' && Table[1][i] == '.' && Table[1][i + 1] == '.' && check_move(0, 1, i, i+1))
            check = true;
    }
    if (check == true)
    {
        cout << "yes";
    } else{
        cout << "no";
    }
    return 0;
}