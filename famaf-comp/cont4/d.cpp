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

const int MAXN = 4*1e4+10;
const ll MOD = 1e9+7;
int n;
ll dp[MAXN];

ll f(ll x) {
	if(dp[x]>0)
		return dp[x];
	dp[x]=1;
	fore(i,1,(x+1)/2) {
		dp[x]+=(f(x-i)*f(i))%MOD;
	}
	if(!(x%2))
		dp[x]+=(f(x/2)*2)%MOD;
	return dp[x]%MOD;
}

int main(){FIN;
	dp[1]=1;
	int t; cin>>t;
	while(t--) {
		cin>>n;

		ll ans = f(n);
		cout<<ans<<'\n';
	}

	return 0;
}
