#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int x,y,z;
  int ans = 0;
  float r;
  cin >> x;
  for(int i = 0; i<x; i++)
    {
    cin >> y >> z;
    r = sqrt(pow(y,2) + pow(z,2));
    //cout << r <<endl;
    if (r<=2)
      ans += 5;
    else if (r<=4)
      ans += 4;
    else if (r<=6)
      ans += 3;
    else if (r<=8)
      ans += 2;
    else if (r<=10)
      ans += 1;
      }
  cout << ans << endl;
  return 0;
}