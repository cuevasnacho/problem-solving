#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define fored(i,a,b) for(int i=a,ggdem=b;i>=ggdem;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

#define N 4
#define M 6

vector<int> g[N];
bool visited[N];

void graphCons() {
    g[0].pb(1);
    g[0].pb(2);
    g[0].pb(3);
    g[1].pb(0);
    g[1].pb(3);
    g[2].pb(0);
    g[2].pb(3);
    g[3].pb(0);
    g[3].pb(1);
    g[3].pb(2);
}

void dfs(int n) {
    for (int vecino : g[n]) {
        if(!visited[vecino]) {
            visited[vecino] = true;
            cout<<vecino<<" ";
            dfs(vecino);
        }
    }
}

int main(){FIN;
    graphCons();
    visited[1]=true;
    dfs(1);

	return 0;
}