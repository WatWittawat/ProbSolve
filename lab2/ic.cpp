#include <iostream>
#include <list>

using namespace std;

int main(){
    int n, num, i = 0;
    char c[3];
    list<int> intt;
    list<int>:: iterator it;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
    cin >> c;
    if (c[0] == 'l' && c[1] == 'i')
    {
        cin >> num;
        intt.push_front(num);
    }
    else if (c[0] == 'r' && c[1] == 'i')
    {
        cin >> num;
        intt.push_back(num);
    }
     else if (c[0] == 'l' && c[1] == 'r')
    {
        intt.push_back(intt.front());
        intt.pop_front();
    }
    else if (c[0] == 'r' && c[1] == 'r')
    {
        intt.push_front(intt.back());
        intt.pop_back();
    }
    }

    for (it = intt.begin(); it != intt.end(); it ++)
    {
        cout << *it << "\n";
    }
}