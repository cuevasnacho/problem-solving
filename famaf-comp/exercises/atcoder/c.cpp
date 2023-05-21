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
ll dp[MAXN][3];
ll a[MAXN][3];

ll f(ll x, int t) {
	if(x==n) return a[x][t];
	if(dp[x][t]>=0) return dp[x][t];

	dp[x][t]=max(f(x+1,(t+1)%3)+a[x][t],f(x+1,(t+2)%3)+a[x][t]);
	return dp[x][t];
}

int main(){FIN;
	mset(dp,-1);
	cin>>n;
	fore(i,0,n) cin>>a[i][0]>>a[i][1]>>a[i][2];
	n--;

	ll a1 = f(0,0);
	ll a2 = f(0,1);
	ll a3 = f(0,2);
	cout<<max(max(a1,a2),a3);


	return 0;
}
