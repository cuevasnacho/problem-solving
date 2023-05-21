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

const int MAXN = 3005;
ll dp[MAXN][MAXN];
string s,t;

ll f(ll x, ll y) {
	if(dp[x][y]>=0)
		return dp[x][y];
	if(x==SZ(s) || y==SZ(t)) {
		dp[x][y]=0; return 0;
	}
	dp[x][y]=max(max(f(x+1,y),f(x,y+1)),f(x+1,y+1)+(s[x]==t[y]));
	return dp[x][y];
}

int main(){
	mset(dp,-1);
	cin>>s>>t;
	ll ans = f(0,0);
	ll p=0,q=0;
	while(ans) {
		if(f(p,q+1)==ans) q++;
		else if(f(p+1,q)==ans) p++;
		else {
			if(s[p]==t[q]) {
				cout<<s[p];
				ans--;
			}
			p++; q++;
		}
	}

	return 0;
}
