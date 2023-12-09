#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MYMAX = 501;

string k, l;
int arr[MYMAX][MYMAX];
int Ly, Lx;

int min_three(int arr, int b, int c)
{
    return arr<b ? (arr<c ? arr : c) : (b<c ? b : c);
}

int main()
{
    int i, j;
    getline(cin, k);
    getline(cin, l);
    Ly = k.length();
    Lx = l.length();
    for (i=0; i<=Ly; i++)
        arr[i][0] = i;
    for (i=0; i<=Lx; i++)
        arr[0][i] = i;
    for (i=1; i<=Ly; i++)
    {
        for (j=1; j<=Lx; j++)
        {
            if (k[i-1] == l[j-1])
                arr[i][j] = arr[i-1][j-1];
            else
                arr[i][j] = 1 + min_three(arr[i-1][j], arr[i][j-1], arr[i-1][j-1]);
        }
    }
    cout << arr[Ly][Lx] << '\n';
    return 0;
}