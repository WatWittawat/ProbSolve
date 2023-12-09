#include <iostream>
#include <list>

using namespace std;

const int MYMAX = 402;
string s, r;
int A[MYMAX][MYMAX];
int B[MYMAX][MYMAX];
int L_S, L_R;

int max_three(int x, int y, int z, int i, int j)
{
    if (x >= y)
    {
        if (x >= z)
        {
            B[i][j] = 0;
            return x;
        }
        else
        {
            B[i][j] = 2;
            return z;
        }
    }
    else if (y >= z)
    {
        B[i][j] = 1;
        return y;
    }
    B[i][j] = 2;
    return z;
}

int MAM(int i, int j)
{
    int cut_l, cut_r, cut_lr;
    if (i<=0 || j<=0)
        return 0;
    if (A[i][j] != -1)
        return A[i][j];
    cut_l = A[i-1][j]==-1 ? MAM(i-1, j) : A[i-1][j];
    cut_r = A[i][j-1]==-1 ? MAM(i, j-1) : A[i][j-1];
    if (s[i-1] == r[j-1])
        cut_lr = A[i-1][j-1]==-1 ? 1+MAM(i-1, j-1) : 1+A[i-1][j-1];
    else
        cut_lr = 0;
    A[i][j] = max_three(cut_l, cut_r, cut_lr, i, j);
    return A[i][j];
}

int main()
{
    int i, j;
    list<char> tmp;
    for (i=0; i<MYMAX; i++)
    {
        for (j=0; j<MYMAX; j++)
            A[i][j] = -1;
    }
    getline(cin, s);
    getline(cin, r);
    L_S = s.length();
    L_R = r.length();
    i = L_S;
    j = L_R;
    MAM(L_S, L_R);
    cout << A[L_S][L_R] << '\n';
    while (i>0 && j>0)
    {
        if (B[i][j] == 0)
            i -= 1;
        else if (B[i][j] == 1)
            j -= 1;
        else if (B[i][j] == 2)
        {
            tmp.push_front(s[i-1]);
            i -= 1; 
            j -= 1;
        }
    }
    for (auto ki: tmp)
        cout << ki;
    cout << '\n';
    return 0;
}
