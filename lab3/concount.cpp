#include <iostream>
#include <vector>
#include <list>

using namespace std;

#define MAX_N 100000

int n,m;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input()
{
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    deg[i] = 0;
  }
  for(int i=0; i<m; i++) {
    int u,v;
    cin >> u >> v;
    u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}

bool seen[MAX_N] = {false};

void bfs(int s)
{
  list<int> Q;

  Q.push_back(s);
  seen[s] = true;

    while(!Q.empty()) {
        int u = Q.front();  
        Q.pop_front();    
        for(int d=0; d<deg[u]; d++) {
            int v = adj[u][d];
            if(!seen[v]) {
	            Q.push_back(v);
                seen[v] = true;
            }
        }
  }
}

int main(){
    read_input();
    int ans = 0;
    for (int i = 0; i<n; i++)
    {
        if (!seen[i])
        {
            bfs(i);
            ans ++;
        }
    }   
    cout << ans << endl;
    return 0;
}