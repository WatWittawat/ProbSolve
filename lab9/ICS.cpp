#include <iostream>

using namespace std;

string wsw, wrw;
const int MYMAX = 303;
int ARR[MYMAX][MYMAX];
int Lws, Lwr;

void get_input()
{
    int i, j;
    for (i=0; i<MYMAX; i++)
    {
        for (j=0; j<MYMAX; j++)
            ARR[i][j] = -1;
    }
    getline(cin, wsw);
    getline(cin, wrw);
    Lws = wsw.length();
    Lwr = wrw.length();
}

int max3(int a, int b, int c)
{
    return a>b ? a>c ? a : c : b>c ? b : c;
}

int MYM(int i, int j)
{
    int l, r, lr;
    if (i<=0 || j<=0)
        return 0;
    if (ARR[i][j] != -1)
        return ARR[i][j];
    l = ARR[i-1][j]==-1 ? MYM(i-1, j) : ARR[i-1][j];
    r = ARR[i][j-1]==-1 ? MYM(i, j-1) : ARR[i][j-1];
    if (wsw[i-1] == wrw[j-1])
        lr = ARR[i-1][j-1]==-1 ? 1+MYM(i-1, j-1) : 1+ARR[i-1][j-1];
    else
        lr = 0;
    ARR[i][j] = max3(l, r, lr);
    return ARR[i][j];
}

int main()
{
    get_input();
    MYM(Lws, Lwr);
    cout << ARR[Lws][Lwr] << '\n';
    return 0;
}
