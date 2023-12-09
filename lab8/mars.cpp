#include <iostream>

using namespace std;

string ww[20];

int dit[2001][30][30];

int check(int a, int b) {
    if (abs(a - b) < 26 - abs(a - b)) {
        return abs(a - b);
    } else { 
        return 26 - abs(a - b);
    }
}

int main()
{
    int n, mimi;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ww[i];
    }
    for (int j = 0; j < n; j++) {
        mimi = 0xffffff;
        for (int i = 0; i < ww[j].length(); i++) {
            for (int k = 0; k < 26; k++) {
                for (int l = 0; l < 26; l++) {
                    dit[i][k][l] = 0xffffff;
                }
            }
        }
        dit[0][ww[j][0] - 'A'][0] = check(ww[j][0] - 'A', 0);
        dit[0][0][ww[j][0] - 'A'] = check(ww[j][0] - 'A', 0);
        if (ww[j].length() == 1) {
            cout << dit[0][ww[j][0] - 'A'][0] << endl;
            continue;
        }
        for (int i = 1; i < ww[j].length(); i++) {
            for (int k = 0; k < 26; k++) {
                for (int l = 0; l < 26; l++) {
                    if (dit[i - 1][k][l] == 0xffffff)
                        continue;
                    int a = check(ww[j][i] - 'A', k);
                    if (dit[i - 1][k][l] + a < dit[i][ww[j][i] - 'A'][l]){
                        dit[i][ww[j][i] - 'A'][l] = dit[i - 1][k][l] + a;
                    } else{
                        dit[i][ww[j][i] - 'A'][l] = dit[i][ww[j][i] - 'A'][l];
                    }
                    int b = check(ww[j][i] - 'A', l);
                    if (dit[i - 1][k][l] + b < dit[i][k][ww[j][i] - 'A']){
                        dit[i][k][ww[j][i] - 'A'] = dit[i - 1][k][l] + b;
                    } else{
                        dit[i][k][ww[j][i] - 'A'] = dit[i][k][ww[j][i] - 'A'];
                    }
                    if (i == ww[j].length() - 1)
                    {
                        mimi = min(mimi, dit[i][ww[j][i] - 'A'][l]);
                        mimi = min(mimi, dit[i][k][ww[j][i] - 'A']);
                    }
                }
            }
        }
        cout << mimi << "\n";
    }
}