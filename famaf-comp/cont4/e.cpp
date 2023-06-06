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
string s;
string hard = "hard";
ll dp[MAXN][4];
ll a[MAXN];

ll f(ll x, ll c) {
	if(x>n && c<4) return 0;
	if(c>=4) return 1e18;
	if(dp[x][c]>=0)
		return dp[x][c];
	if(s[x]!=hard[c])
		dp[x][c]=f(x+1,c);
	else
		dp[x][c]=min(f(x+1,c)+a[x],f(x+1,c+1));
	return dp[x][c];
}

int main(){FIN;
	mset(dp,-1);
	cin>>n>>s;
	fore(i,0,n) cin>>a[i];
	n--;

	ll ans = f(0,0);
	cout<<ans;

	return 0;
}
