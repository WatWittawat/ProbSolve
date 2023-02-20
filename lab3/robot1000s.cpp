#include <iostream>
#include <string>

using namespace std;

int main(){
    string massage;
    int cal;
    cin >> massage;
    int n= 0, e=0, s=0, w=0;
    cin >> cal;
    for (int i = 0; i < massage.length(); i++)
    {
        if (massage[i] == 'N')
            n += 1;
        else if (massage[i] == 'S')
            s += 1;
        else if (massage[i] == 'E')
            e += 1;
        else if (massage[i] == 'W')
            w += 1;
    }
    if (s>n)
        swap(n,s);
    if (w>e)
        swap(e,w);

    while (cal != 0)
    {
        if (w != 0)
        {
            w--;
            cal--;
        }
        else if (s != 0)
        {
            s--;
            cal--;
        }
        else if (n != 0)
        {
            n--;
            cal--;
        }
        else if (e != 0)
        {
            e--;
            cal--;
        }

    }
    cout << (n+e -s - w)*2 << endl;
    return 0;
}