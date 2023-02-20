#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

pair <int, pair<int ,int> > my_map[100001] ; 
int node[100001] ;

int n, m, i, MST = 0;

int parent(int x) {
    while (node[x] != x ) {
        node[x] = node[node[x]]; 
        x = node[x];
    }
    return x ;
}

void unionFind(int x,int y) {
    int a = parent(x); 
    int b = parent(y); 
    node[a] = node[b]; 
}

void kruskal() {
    for (i=0;i<m;i++) {
        int u,v,w;
        u = my_map[i].second.first;
        v = my_map[i].second.second;
        w = my_map[i].first; 
        if (parent(u) != parent(v)) {
            MST += w ; 
            unionFind(u,v) ; 
        }
    }
}

int main() {
    int u, v, w, i;
    cin >> n >> m;
    for (i=0;i<m;i++){
        cin >> u >> v >> w;
        my_map[i] = make_pair(w,make_pair(u,v));
    }
    sort(my_map,my_map+m);

    for (i=1;i<=n;i++) {
        node[i] = i ;
    }
    kruskal(); 
    cout << MST << endl; 
}