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

const int MAXN = 1e5+10;
int n,m;
ll dp[MAXN];
vector<int> g[MAXN];

ll f(ll x) {
	if(dp[x]>0)
		return dp[x];
	if(g[x].empty())
		dp[x]=0;
	for(auto v:g[x]) {
		dp[x]=max(f(v)+1,dp[x]);
	}
	return dp[x];
}

int main(){FIN;
	mset(dp,-1);
	cin>>n>>m;
	fore(i,0,m) {
		int u,v; cin>>u>>v; u--; v--;
		g[u].pb(v);
	}
	ll mx=0;
	fore(i,0,n) mx=max(mx,f(i));

	cout<<mx;

	return 0;
}
