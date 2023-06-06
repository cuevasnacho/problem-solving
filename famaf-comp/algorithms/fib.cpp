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

const int MAXN = 1005;

ll dp[MAXN];

ll f(ll n) {
	ll &res=dp[n];
	if(res!=-1)
		return res;
	if(n<=1)
		res=n;
	else
		res=f(n-1)+f(n-2);
	return res;
}

int main(){FIN;
	mset(dp,-1);
	int n; cin>>n;
	cout<<f(n);

	return 0;
}
