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

const int MAXN = 105;
const int MAXW = 1e5+10;
int n,w;
ll dp[MAXN][MAXW];
ii a[MAXN];

ll f(ll x, ll t) {
	if(x==0) return (t-a[x].fst<0)?0:a[x].snd;
	if(dp[x][t]>=0)
		return dp[x][t];
	if(t-a[x].fst<0) dp[x][t]=f(x-1,t);
	else dp[x][t]=max(f(x-1,t-a[x].fst)+a[x].snd,f(x-1,t));
	return dp[x][t];
}

int main(){FIN;
	mset(dp,-1);
	cin>>n>>w;
	fore(i,0,n) cin>>a[i].fst>>a[i].snd;
	n--;

	ll ans = f(n,w);
	cout<<ans;

	return 0;
}
