#include <bits/stdc++.h>
using namespace std;
#define v vector<int>
#define p pair<int, int>
#define vi vector<p>
#define vvi vector<v>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) built_in_popcount(x)
const int N = 1e5 + 2 , MOD = 1e9 + 7;
v adj[N];
bool vis[N];
signed main(){
    for(int i=0;i<N;i++){
        vis[i]=0;
    }
    int n ,m;
    cin>>n>>m;
    int x,y;
    rep(i,0,m){
     int x,y;
     cin>>x>>y;
     adj[x].push_back(y);
      adj[y].push_back(x);

 }
  queue <int> q;
  q.push(1);
  vis[1]= true;
  while(!q.empty()){
      int node = q.front();
      q.pop();
      cout<< node <<endl;
      vector <int> :: iterator it;
     for(it = adj[node].begin();it!= adj[node].end();it++){
         if(!vis[*it]){
             vis[*it]=1;
             q.push(*it);
         }
     } 
  }
    return 0;
}
