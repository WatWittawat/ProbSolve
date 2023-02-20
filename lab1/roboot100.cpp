
#include <iostream>
#include <string>
using namespace std;

int main(){
  string text;
  int FF = 0, BB = 0;
  getline(cin, text);
  for (int i = 0; i < text.length(); i++)
  {
    if (text[i] == 'N')
      FF += 1;
    else if (text[i] == 'S')
      FF -= 1;
    else if (text[i] == 'E')
      BB += 1;
    else if (text[i] == 'W')
      BB -= 1;
    else if (text[i] == 'Z')
      {
        FF = 0;
        BB = 0;
      }
  }

  cout << BB << " " << FF << "\n";
    

}