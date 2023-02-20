#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(){
    string massage;
    list<char> my_text;
    list<char>:: iterator it;
    while (getline(cin, massage))
    {
        my_text.clear();
        it = my_text.begin();
        for (int i = 0; i<massage.size(); i++)
        {
            if (massage[i] == '[')
                it = my_text.begin();
            if (massage[i] == ']')
                it = my_text.end();
            if (massage[i] != '[' && massage[i] != ']')
                my_text.insert(it, massage[i]);       
        }
        for(it = my_text.begin(); it != my_text.end() ;it++)
            cout << *it;
        cout << "\n";
    }
}