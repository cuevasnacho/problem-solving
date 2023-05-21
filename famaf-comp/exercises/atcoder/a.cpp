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
int n;
ll dp[MAXN];
ll a[MAXN];

ll f(ll x) {
	if(x>n) return 1e9;
	if(x==n) return 0;
	if(dp[x]>=0)
		return dp[x];
	dp[x]=min(f(x+1)+abs(a[x]-a[x+1]),f(x+2)+abs(a[x]-a[x+2]));
	return dp[x];
}

int main(){FIN;
	mset(dp,-1);
	cin>>n;
	fore(i,0,n) cin>>a[i];
	n--;

	ll ans = f(0);
	cout<<ans;

	return 0;
}
