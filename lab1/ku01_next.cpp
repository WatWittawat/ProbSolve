#include <iostream>

using namespace std;

int main(){
  int check = 0, x, t = 0;
  cin >> x;
  int key[x], main[x], tmp[x], ar[x];
  for (int i =0; i < x; i++)
    {
    main[i] = i + 1;
    cin >> key[i];
    }
  while(1)
  {
  check = 1;
  for (int i = 0; i < x; i++)
      {
      tmp[key[i] - 1] = main[i];
      if (tmp[key[i] - 1] == key[i])
        ar[i] = 1;
      }
  for (int i = 0; i < x ; i++)
    main[i] = tmp[i];
  t++;
  for (int i = 0; i < x; i++)
  {
    if (ar[i] == 0)
      {
        check = 0;
        break;
      }
  }
  if (check == 1)
    break;
  }
  cout << t << "\n";
}