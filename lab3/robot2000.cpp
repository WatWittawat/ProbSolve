#include <iostream>


using namespace std;

int main(){
    string massage;
    int check = 0;
    int num = 0;
    cin >> massage;
    for (int i = 0; i < massage.length(); i++)
        {
            if (massage[i] == 'Z')
            {
                cout << "Z";
                check = 0;
                continue;
            }
            else if (massage[i] == 'N')
                num = 0;
            else if (massage[i] == 'E')
                num = 1;
            else if (massage[i] == 'S')
                num = 2;
            else if (massage[i] == 'W')
                num = 3;

            while (check != num)
            {
                cout << "R";
                check += 1;
                check %= 4;
            }
            cout << "F";

        }
    cout << "\n";
    return 0;
}