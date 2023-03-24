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
typedef __int128 i128;

int R,C; bool pos=false;
int path[1001][100];
i128 rows[1000];
vector<int> adj[100000];
vector<int> adj2[100000];
bool visited[100000];

bool nut_fits(i128 nut, i128 row) {
  return ((nut&row)==0);
}

i128 move_nut(i128 nut) {
  if(((1<<(C-1))&nut)!=0) {
    nut=nut^(1<<(C-1));
    nut=nut<<1;
    nut=nut|1;
    return nut;
  } else {
    return (nut<<1);
  }
}

i128 process_row(string s) {
  i128 row=0;
  fore(i,0,C-1) {
    if(s[i]=='1')
      row=row|1;
    row=row<<1;
  }
  if(s[C-1]=='1')
      row=row|1;
  return row;
}

i128 rotated_nut(string s) {
  i128 row=0;
  fored(i,C,1) {
    if(s[i]=='1')
      row=row|1;
    row=row<<1;
  }
  if(s[0]=='1')
      row=row|1;
  return row;
}

int pmod(int x, int n) {
  return ((x%n)+n)%n;
}

void create_adj(int a) {
  if(a) {
    fore(i,1,R) {
      fore(j,0,C) {
        if(path[i][j]) {
          if(path[i-1][j]) {adj[(i-1)*C+j].pb((i-2)*C+j);}
          if(path[i+1][j]) {adj[(i-1)*C+j].pb(i*C+j);}
          if(path[i][(j+1)%C]) {
            if(j!=C-1) {adj[(i-1)*C+j].pb((i-1)*C+j+1);}
            else {adj[(i-1)*C+j].pb((i-1)*C);}
          }
          if(path[i][pmod((j-1),C)]) {
            if(j!=0) {adj[(i-1)*C+j].pb((i-1)*C+j-1);}
            else {adj[(i-1)*C+j].pb(i*C-1);}
          }
        }
      }
    }
  } else {
    fore(i,1,R) {
      fore(j,0,C) {
        if(path[i][j]) {
          if(path[i-1][j]) {adj2[(i-1)*C+j].pb((i-2)*C+j);}
          if(path[i+1][j]) {adj2[(i-1)*C+j].pb(i*C+j);}
          if(path[i][(j+1)%C]) {
            if(j!=C-1) {adj2[(i-1)*C+j].pb((i-1)*C+j+1);}
            else {adj2[(i-1)*C+j].pb((i-1)*C);}
          }
          if(path[i][pmod((j-1),C)]) {
            if(j!=0) {adj2[(i-1)*C+j].pb((i-1)*C+j-1);}
            else {adj2[(i-1)*C+j].pb(i*C-1);}
          }
        }
      }
    }
  }
}

void dfs(int s, int a) {
  if (visited[s]) return;
    visited[s] = true;
  if(s>=(R-1)*C) {
    pos=true;
    return;
  }
  if(a)
    for (auto u: adj[s]) {
      dfs(u,a);
    }
  else
    for (auto u: adj2[s]) {
      dfs(u,a);
    }
}

void solve(i128 nut, int a) {
  fore(i,1,R+1) {
    fore(j,0,C) {
      if(nut_fits(nut,rows[i-1]))
        path[i][j]=1;
      nut=move_nut(nut);
    }
  }
  create_adj(a);
  fore(i,0,C) {
    mset(visited,0);
    dfs(i,a);
    if(pos) break;
  }
}

int main(){FIN;
  cin>>R>>C;
  string n; cin>>n;
  i128 nut=process_row(n);
  i128 rnut=rotated_nut(n);

  rows[0]=0;
  fore(i,0,R) {
    string s; cin>>s;
    rows[i]=process_row(s);
  }
  solve(nut,1);
  if(!pos) {
    memset(path,0,sizeof(path));
    memset(visited,0,sizeof(visited));
    solve(rnut,0);
  }

  if(pos)
    cout<<"Y\n";
  else
    cout<<"N\n";

  return 0;
}