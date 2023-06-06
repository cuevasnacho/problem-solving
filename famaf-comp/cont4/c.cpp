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
int n;
ll dp[MAXN];
ll a[MAXN];

ll f(ll x) {
	if(x>n) return 0;
	if(dp[x]>=0)
		return dp[x];
	dp[x]=f(x+a[x])+a[x];
	return dp[x];
}

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		mset(dp,-1);
		cin>>n;
		fore(i,0,n) cin>>a[i];
		n--;

		ll ans=0;
		fore(i,0,n+1) ans=max(ans,f(i));
		cout<<ans<<'\n';
	}
	return 0;
}
