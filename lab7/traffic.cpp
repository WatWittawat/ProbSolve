#include "traffic.h"
#include <cmath>
#include <cstdio>

int main()
{
    int n, k, x, y, z, j, tmp1 = 0, tmp2 = 0;
    traffic_init(&n, &k);
    x = 1;
    z = 1;
    y = n;
    j = n;
    for (int i = 1; i <= n; i++) {
        if (traffic_query(i, 1, i, n) > n - 1) {
            tmp1 = 1;
            x = i;
            y = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (traffic_query(1, i, n, i) > n - 1) {
            tmp2 = 1;
            z = i;
            j = i;
            break;
        }
    }
    if (tmp1) {
        int low = n;
        int high = 1;
        while (true) {
            int mid = (low + high) / 2;
            if (traffic_query(x, mid - 1, x, mid) == 2) {
                traffic_report(x, mid - 1, x, mid, 0, 0, 0, 0);
            }
            else if (traffic_query(x, mid, x, mid + 1) == 2) {
                traffic_report(x, mid, x, mid + 1, 0, 0, 0, 0);
            }
            else if (traffic_query(x, low, x, mid) > abs(low - mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
    }
    else {
        int low = n;
        int high = 1;
        while (true) {
            int mid = (low + high) / 2;
            if (traffic_query(mid - 1, z, mid, z) == 2) {
                traffic_report(mid - 1, z, mid, z, 0, 0, 0, 0);
            }
            else if (traffic_query(mid, z, mid + 1, z) == 2) {
                traffic_report(mid, z, mid + 1, z, 0, 0, 0, 0);
            }
            else if (traffic_query(low, z, mid, z) > abs(low - mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
    }
    return 0;
}