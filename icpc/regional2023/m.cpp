#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define fored(i,a,b) for(int i=a-1,ggdem=b;i>=ggdem;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int R,C; bool pos=false;
int path[1001][102];

bitset<100> nut;
bitset<100> rows[1000];

vector<int> adj[100000];
bool visited[100000];

void process_n(string n) {
  fore(i,0,C) {
    if(n[i]=='1')
      nut[i]=1;
    else
      nut[i]=0;
  }
}

void process_r(string s, int i) {
  fore(j,0,C) {
    if(s[j]=='1')
      rows[i][j]=1;
    else
      rows[i][j]=0;
  }
}

void dfs(int s) {
  if (visited[s]) return;
    visited[s] = true;
  if(s>=(R-1)*C) {
    pos=true;
    return;
  }
  for (auto u: adj[s]) {
    dfs(u);
  }
}

void create_adj() {
  fore(i,1,R) {
    fore(j,1,C+1) {
      int k=(i-1)*C+j-1;
      if(path[i][j]) {
        if(path[i][j-1]) {if(j!=1) {adj[k].pb((i-1)*C+j-2);}
                          else {adj[k].pb(i*C-1);}}
        if(path[i][j+1]) {if(j!=C) {adj[k].pb((i-1)*C+j);}
                          else {adj[k].pb((i-1)*C);}}
        if(path[i-1][j]) {adj[k].pb((i-2)*C+j-1);}
        if(path[i+1][j]) {adj[k].pb(i*C+j-1);}
      }
    }
  }
}

void pos_moves() {
  fore(i,0,R) {
    fore(j,0,C) {
      bool can=true;
      fore(k,0,C) {
        if(nut[(k+j)%C] && rows[i][k]) {
          can=false;
          break;
        }
      }
      path[i+1][j+1]=can;
    }
  }
  fore(i,0,R) {
    path[i][0]=path[i][C];
    path[i][C+1]=path[i][1];
  }
}

int main(){FIN;
  cin>>R>>C;
  string n; cin>>n;

  fore(i,0,R) {
    string s; cin>>s;
    process_r(s, i);
  }

  fore(p,0,2) {
    mset(visited,0);
    mset(path,0);
    process_n(n);
    pos_moves();
    create_adj();
    fore(i,0,C) {
      if(path[1][i+1])
        dfs(i);
      if(pos) break;
    }
    if(pos) break;

    fore(i,0,100000)
      adj[i].clear();
    reverse(n.begin(),n.end());
  }

  if(pos)
    cout<<"Y\n";
  else
    cout<<"N\n";

  return 0;
}