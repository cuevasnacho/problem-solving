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
int n,m,k;
ll dp[MAXN];
ll x[MAXN];
vector<pair<ll,ll>> l[MAXN];

ll from(ll i, ll j) {
	return i*m+j;
}

ii to(ll res) {
	return {res/m,res%m};
}

ll f(ll i, ll j) {
	if(i==n-1) return (abs(j-abs(m-1)))*x[i];
	ll &r = dp[from(i,j)];
	if(r>=0) return r;
	r=1e18;
	fore(c,0,m) {
		int ic=from(i,c);
		for(ii u:l[ic]) {
			ii p=to(u.fst);
			r=min(f(p.fst,p.snd)-u.snd+abs(j-c)*x[i],r);
		}
	}
	return r;
}

int main(){FIN;
	mset(dp,-1);
	int t; cin>>t;
	while(t--) {
		cin>>n>>m>>k;
		fore(i,0,n) cin>>x[i];
		fore(i,0,k) {
			ll a,b,c,d,w; cin>>a>>b>>c>>d>>w;
			a--; b--; c--; d--;
			l[from(a,b)].pb({from(c,d),w});
		}
		ll ans=f(0,0);
		if(ans<1e16)
			cout<<ans<<'\n';
		else
			cout<<"NO ESCAPE\n";

		fore(i,0,n*m) dp[i]=-1;
		fore(i,0,n*m) l[i].clear();
	}

	return 0;
}
