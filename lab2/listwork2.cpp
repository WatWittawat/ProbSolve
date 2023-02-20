#include <iostream>
#include <list>

using namespace std;

int main()
{
    int n, res0;
    char res1;
    list<int> intt;
    list<int>::iterator it;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> res1 >> res0;
        if (res1 == 'I')
            intt.push_front(res0);
        else if (res1 == 'A')
            intt.push_back(res0);
        else if (res1 == 'D')
        {
                if(intt.size() < res0)
                {
                    continue;
                }
                it = intt.begin();
                advance(it, res0 - 1);
                intt.erase(it);
        }
    }

    for (it = intt.begin(); it != intt.end(); ++it)
        cout << *it << "\n";
    return 0;
}