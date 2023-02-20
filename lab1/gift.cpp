#include <iostream>

using namespace std;

int main() {
  int x,in_put,ans = 0;
  cin >> x;
  int y[x];
  for (int i = 0; i<x; i++)
    {
    cin >> in_put;
    y[i] = in_put;
    }
  for (int i = 0; i<x; i++)
    {
      if (y[i] < 0)
        ans = ans;
      else
        ans += y[i];
    }
  cout << ans << endl;
  return 0;
  }