#include <iostream>

using namespace std;

int main(){
  int x;
  cin >> x;
  int ar[x];
  int check = 0, res = 0,z;
  for(int i = 0; i < x; i++)
    cin >> ar[i];
  for(int j = x-1; j > -1; j--)
    {
    check = ar[j];
    //cout << check << "\n";
    z = j;
    for(z ; z > -1; z--)
      if (check > ar[z])
        res += 1;
    }
  cout << res << "\n";
}
