#include <iostream>

using namespace std;

int main(){
  int n,k,t;
  cin >> n >> k >> t;
  int check = 1, res = 0;
  while (1)
    {
      res += 1;
      check = check + k;
      check = check % n;
      if (check == 1)
        break;
      else if (check == t)
      {
        res += 1;
        break;
      }
    }
  cout << res << "\n";
}