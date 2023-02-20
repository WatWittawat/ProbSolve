#include <iostream>
#include <list>

using namespace std;

int main(){
    int n, first, second;
    char c;
    list <int> my_list[100001];
    list<int>:: iterator it;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        cin >> c >> first >> second;
        if (c == 'N')
        {
            my_list[second].push_back(first);
        }
        else if (c == 'M')
        {
            my_list[second].splice(my_list[second].end(),my_list[first]);
            my_list[first].erase(my_list[first].begin(), my_list[first].end());
        }
        
    }
    for (int i = 0; i < 100001; i++)
    {
        for (it = my_list[i].begin() ; it != my_list[i].end(); it++)
        {
            cout << *it << "\n";
        }
    }
    return 0;
}