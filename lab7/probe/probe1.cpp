#include "probelib.h"
#include <cstdio>

int n;

int bi_search (int st, int en)
{
    int median;
    if (st == en){
        return st;
    }
    median = (en+st)/2;
    if (probe_check(st,median)){
        return bi_search(st, median);
    } else{
        return bi_search(median+1, en);
    }
}

int main()
{
    int ans;
    n = probe_init();
    probe_answer(bi_search(0, n-1));
}