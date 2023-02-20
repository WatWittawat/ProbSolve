#include <iostream>

using namespace std;

int row, column;
char my_map[35][35];
bool Walk[35][35] = {{false}};

int main(){
    cin >> row >> column;
    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cin >> my_map[i][j];
        }
    }
    int G1 = 0, G2 = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (my_map[i][j] == '*' || my_map[i][j] == '$')
            {
                
            }
        }
    }
    return 0;
}

