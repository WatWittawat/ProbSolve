#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, sumo = 0;
    set<int> my_list;
    cin >> n;
    int tmp[n];
    for (int i = 0; i< n; i++)
    {
        cin >> tmp[i]; 
    }
    for (int i = 0; i<n; i++)
    {   
        for (int j = i; j<n; j++){
            sumo += tmp[j];
            my_list.insert(sumo);
        }
        sumo = 0;
    }
    cout << my_list.size() << endl;
}