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
typedef pair<int,int> ii;

const int MAXN = 2*1e5+10;

int n,m;
vector<int> g[MAXN];
bool vis[MAXN];

int ctr;
bool cc;

void dfs(int n) {
	if(g[n].size()!=2) cc=0;
	ctr++;
	for (int vecino : g[n]) {
		if(!vis[vecino]) {
			vis[vecino]=1;
			dfs(vecino);
		}
	}
}

int main(){FIN;
	cin>>n>>m;
	fore(i,0,m) {
		int u,v; cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}

	int ans=0;
	fore(i,0,n) {
		ctr=1; cc=1;
		if(!vis[i]) dfs(i);
		if(ctr>=3 && cc) ans++;
	}

	cout<<ans;

	return 0;
}
