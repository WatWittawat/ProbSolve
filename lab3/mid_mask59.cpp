#include <iostream>

using namespace std;

int main(){
    int n , y, ind = 0;
    cin >> n;
    int num[4*n], my_index[n];
    int kk = 0;
    for (int i = 0; i < 4; i++)
    {
        int maxx = -999;
        int check_index = i;
        for(int j = 0; j < n; j++)
        {
            cin >> y;
            num[kk] = y;
            kk += 1;
            if (y > maxx)
            {
                maxx = y;
                check_index = ind;
            }
            ind += 1;
        }
        my_index[i] = check_index;
    }
    int fi,s,t,fo;
    int a,b, st,sc;
    fi = num[my_index[0]];
    s = num[my_index[1]];
    t = num[my_index[2]];
    fo = num[my_index[3]];
    if (fi > s)
    {
        a = my_index[1];
        if (t > fo)
        {
            b = my_index[3];
            if (fi > t)
                {
                    st = my_index[0];
                    sc = my_index[2];
                }
            else
                {
                    st = my_index[2];
                    sc = my_index[0];
                }
        }
        else
        {
            b = my_index[2];
            if (fi > fo)
                {
                    st = my_index[0];
                    sc = my_index[3];
                }
            else
                {
                    st = my_index[3];
                    sc = my_index[0];
                }
        }
    }
    else
    {
        a = my_index[0];
        if (t > fo)
        {
            b = my_index[3];
            if (s > t)
                {
                    st = my_index[1];
                    sc = my_index[2];
                }
            else
                {
                    st = my_index[2];
                    sc = my_index[1];
                }
        }
        else
        {
            b = my_index[2];
            if (s > fo)
                {
                    st = my_index[1];
                    sc = my_index[3];
                }
            else
                {
                    st = my_index[3];
                    sc = my_index[1];
                }
        }
    }
    cout << st+1 << " " << sc+1 << " " << a+1 << " " << b+1 << "\n";
    
    return 0;
}