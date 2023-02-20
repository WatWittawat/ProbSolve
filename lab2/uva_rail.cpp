#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n, my_list[1001];
    stack<int> my_stack;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i<n; i++)
            my_list[i] = i+1;
        int new_list[n];
        while (true)
        {
            cin >> new_list[0];
            if (new_list[0] == 0)
            {
                cout << endl;
                break;
            }
            for (int i = 1; i<n; i++)
            {
                cin >> new_list[i];
            }
            int tmp=0;
            for (int j=0 ; j<n; j++)
            {
                my_stack.push(my_list[j]);
                while (!my_stack.empty() && my_stack.top() == new_list[tmp])
                {
                    my_stack.pop();
                    tmp++;
                }
            }
            if (my_stack.empty())
                cout << "Yes" << "\n";
            else
                {
                    cout << "No" << "\n";
                    while(!my_stack.empty())
                        my_stack.pop();
                }            
        }
    }
}