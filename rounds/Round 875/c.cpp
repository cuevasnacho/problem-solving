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

const int MAXN = 2*1e5+6;

int dp[MAXN], id[MAXN];
vector<ii> g[MAXN];

void dfs(int x) {
	for(ii r:g[x]) {
		if(!dp[r.fst]) {
			dp[r.fst]=dp[x]+(r.snd<=id[x]);
			id[r.fst]=r.snd;
			dfs(r.fst);
		}
	}
}

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		fore(i,1,n) {
			int u,v; cin>>u>>v;
			g[u].pb({v,i});
			g[v].pb({u,i});
		}
		dp[1]=1;
		dfs(1);

		int mx=0;
		fore(i,1,n+1) mx=max(mx,dp[i]);

		cout<<mx<<'\n';

		fore(i,1,n+1) dp[i]=0;
		fore(i,1,n+1) id[i]=0;
		fore(i,1,n+1) g[i].clear();
	}

	return 0;
}
