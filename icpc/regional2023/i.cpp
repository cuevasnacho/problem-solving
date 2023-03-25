#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int R,C;
int m[102][102];
vector<int> adj[10001];
bool visited[100001];

void make_adj() {
  fore(i,1,R+1) {
    fore(j,1,C+1) {
      int e=m[i][j];
      if(m[i-1][j]>e) {adj[e].pb(m[i-1][j]);}
      if(m[i+1][j]>e) {adj[e].pb(m[i+1][j]);}
      if(m[i][j-1]>e) {adj[e].pb(m[i][j-1]);}
      if(m[i][j+1]>e) {adj[e].pb(m[i][j+1]);}
    }
  }
}

int solve(int node) {
  priority_queue<int,vector<int>,greater<int>> q;
  int size=adj[node].size(), curr_n=node, ctr=0;
  fore(i,0,size) {
    q.push(adj[node][i]);
  }
  while(!q.empty()) {
    curr_n=q.top();
    while(q.top()==curr_n && q.size()>0)
      q.pop();
    visited[curr_n]=true;
    size=adj[curr_n].size();
    fore(i,0,size) {
      if(adj[curr_n][i]>curr_n)
        q.push(adj[curr_n][i]);
    }
    ++ctr;
  }
  return ctr;
}

int main(){FIN;
  cin>>R>>C;
  int mx=0, pos;
  fore(i,0,R+2) {
    fore(j,0,C+2) {
      if(i==0 || i==R+1 || j==0 || j==C+1) {
        m[i][j]=-1;
      } else {
        cin>>m[i][j];
      }
    }
  }
  make_adj();
  fore(i,1,R*C+1) {
    if(!visited[i]) {
      pos = solve(i);
      mx = max(mx,pos);
    }
  }

  cout<<mx+1<<"\n";

  return 0;
}