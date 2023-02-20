#include <iostream>

using namespace std;

int main(){
    int row,colum, A, B, X, Y;
    //int create[5][8] = {{1,1,2,2,2,3,3,3}, {1,4,2,2,2,3,3,3}, {4,4,2,2,2,5,6,3}, {4,4,4,4,5,5,6,6}, {4,4,5,5,5,6,6,6}};
    cin >> row >> colum >> A >> B >> X >> Y;
    int create[row][colum];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < colum; j++)
        {
            cin >> create[i][j];
        }
    }
    // แก้ index 
    A = A - 1;
    B = B - 1;
    X = X -1;
    Y = Y -1;
    int start = create[A][B], endd = create[X][Y];
    int ans = -1;
    if (start == endd)
        cout << 0 << endl;
    else
    {
        while (start != endd)
        {
            if (B != Y && Y> B)
                B++;
            else if (A != X && X > A)
                A++;
            start = create[A][B];
            ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}