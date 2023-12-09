#include <iostream>

using namespace std; 

const int MAX_N = 301;

int n;
int A[MAX_N][MAX_N];
string rna;

int MAM(int l, int r)
{
    int k, mmpair = 0;
    int cu_T, pp;
    if (l<0 || r<0)
        return 0;
    if (r < l+4)
    {
        A[l][r] = 0;
        return 0;
    }
    if (A[l][r] != -1)
        return A[l][r];
    cu_T = MAM(l, r-1);
    for (k=l; k<r-4; k++)
    {
        if (rna[k]+rna[r]==150 || rna[k]+rna[r]==138)
        {
            pp = 1 + MAM(l, k-1) + MAM(k+1, r-1);
            if (pp > mmpair){
                mmpair = pp;
            } else{
                mmpair = mmpair;
            }
        }
    }
    return A[l][r] = max(cu_T, mmpair);
}

int main()
{
    int mmpair, i, j;
    getline(cin, rna);
    n = rna.length();
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
            A[i][j] = -1;
    }
    MAM(0, n-1);
    mmpair = A[0][0];
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
            mmpair = max(mmpair, A[i][j]);
    }
    cout << mmpair << '\n';
    return 0;
}