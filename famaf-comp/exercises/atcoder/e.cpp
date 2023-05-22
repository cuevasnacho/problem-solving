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
const int MAXV = 1e5+10;
ll n,w;
ll dp[MAXN][MAXV];
ii a[MAXN];

ll f(ll x, ll v) {
	if(v<0) return 1e18;
	if(x>n && v>0) return 1e18;
	if(x>n && v==0) return 0;
	if(dp[x][v]>=0)
		return dp[x][v];
	dp[x][v]=min(f(x+1,v),f(x+1,v-a[x].snd)+a[x].fst);
	return dp[x][v];
}

int main(){FIN;
	mset(dp,-1);
	cin>>n>>w;
	fore(i,0,n) cin>>a[i].fst>>a[i].snd;
	n--;

	for(int i=1e5; i>=0; --i) {
		if(f(0,i)<=w) {
			cout<<i;
			break;
		}
	}

	return 0;
}
