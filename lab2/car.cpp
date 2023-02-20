#include <iostream>
#include <list>

using namespace std;

int main(){
    int n,p,v, reverse_ans = 0;
    list<int> my_list;
    list<int>:: iterator it;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        cin >> p >> v;
        my_list.push_back(v);
    }
    my_list.reverse();
    int tmp = -999;
    for (it = my_list.begin(); it != my_list.end(); it++)
    {
        if (*it > tmp)
        {
            reverse_ans ++;
            tmp = *it;
        }
    }
    

    cout << n - reverse_ans << endl;
}