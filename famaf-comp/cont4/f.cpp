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
typedef pair<ll,ll> ii;

const int MAXN = 1e5+10;
int n;
ll dp[MAXN][2];
ll l[MAXN], r[MAXN];
vector<ll> g[MAXN];
bool vis[MAXN];

ll ans=0;

ll f(int x, int d) {
	if(vis[x]) return 0;
	if(dp[x][d]>=0) return dp[x][d];
	vis[x]=1; dp[x][d]=0;
	for(int v:g[x]) {
		dp[x][d]=max(f(v,0)+abs(l[x]-r[v]),f(v,1)+abs(l[x]-r[v]));
	}
	return dp[x][d];
}

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		mset(dp,-1);
		cin>>n;
		fore(i,0,n) cin>>l[i]>>r[i];
		fore(i,0,n-1) {
			int u,v; cin>>u>>v; u--; v--;
			g[u].pb(v);
			g[v].pb(u);
		}

		cout<<f(0,0)<<'\n';
		fore(i,0,n) vis[i]=0;
		cout<<f(0,1)<<'\n';
		fore(i,0,n) g[i].clear();
	}

	return 0;
}
