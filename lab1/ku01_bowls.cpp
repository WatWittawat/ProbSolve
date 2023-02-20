#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int x;
  cin >> x;
  int ar[x];
  int ans = 1, res = 0;
  for (int i = 0; i < x; i++)
    cin >> ar[i];
  sort(ar, ar + x);
  for (int i = 0; i < x-1; i++)
    {
    if (ar[i] == ar[i+1])
      ans += 1;
    else
      ans = 1;
    if (ans > res)
      res = ans;
    }
  cout << res << endl;
  return 0;
}