#include <iostream>

using namespace std;

short my_arr[3000000], L[2000000], R[2000000];

void printi(int num)
{
    int i = num, t, a = 0;
    char cx, tmp[3];
    while (i != 0) {
        t = i % 10;
        i = i / 10;
        tmp[a] = t + '0';
        a++;
    }
    for (i = a - 1; i >= 0; i--) {
        cx = tmp[i];
        putchar(cx);
    }
}

void Merge(int st, int mid, int ee) {
    int LS = mid - st + 1, RS = ee - mid, u = 0, v = 0, a = 0, b = 0, c = st;;
    for (int i = st; i <= mid; i++) {
        L[u] = my_arr[i];
        u++;
    } for (int j = mid + 1; j <= ee; j++) {
        R[v] = my_arr[j];
        v++;
    } while (a < LS && b < RS) {
        if (L[a] <= R[b]) {
            my_arr[c] = L[a];
            a++;
        }
        else {
            my_arr[c] = R[b];
            b++;
        }
        c++;
    }
    for (int ll = a; ll < LS; ll++) {
        my_arr[c] = L[ll];
        c++;
    }
    for (int rr = b; rr < RS; rr++) {
        my_arr[c] = R[rr];
        c++;
    }
}

void MergeSort(int st, int ee) {
    int size = ee - st + 1, mid;
    if (size > 1) {
        mid = (st + ee) / 2;
        MergeSort(st, mid);
        MergeSort(mid + 1, ee);
        Merge(st, mid, ee);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            cin >> my_arr[i];
        }
        MergeSort(0, n - 1);
        for (int i = 0; i < n - 1; i++) {
            printi(my_arr[i]);
            putchar(' ');
        }
        printi(my_arr[n - 1]);
        putchar('\n');
    }
    return 0;
}