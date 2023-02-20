#include <iostream>
#include <list>

using namespace std;

int main(){
    int n;
    list<int> my_list;
    list<int> new_list;
    list<int> :: iterator it;
    while (true)
    {
    cin >> n;
    if (n == 0)
        break;        
    {
    for (int i = 1; i <= n; i++)
    {
        my_list.push_back(i);
    }
    while (true)
    {
        if (n == 1)
            break;
        if (new_list.size() == n - 1 && my_list.size() == 1)
            break;
        new_list.push_back(my_list.front());
        my_list.erase(my_list.begin());
        my_list.push_back(my_list.front());
        my_list.erase(my_list.begin());
    }
    if ( n == 1)
        cout << "Discarded cards:" << "\n";
    else
        cout << "Discarded cards: ";
    for (it = new_list.begin(); it != new_list.end(); it++)
    {   
        if (*it == new_list.back())
            cout << *it << "\n";
        else
            cout << *it << ", ";
    }
    it = my_list.begin();
    cout <<"Remaining card: ";
    cout << *it << "\n"; 
    new_list.erase(new_list.begin(), new_list.end());
    my_list.erase(my_list.begin(),my_list.end());
}
}
return 0;
}