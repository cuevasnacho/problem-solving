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

const int MAXN = 1e3+24;
const int MOD = 1e9+7;
int n,m;
ll dp[MAXN][MAXN];
char g[MAXN][MAXN];
vector<ii> mov = {{0,1},{1,0},{-1,0},{0,-1}};

bool valid(int x, int y) {
	return x>=0 && x<n && y>=0 && y<m && g[x][y]=='.';
}

ll f(int x, int y) {
	if(!valid(x,y)) return -1e12;
	if(dp[x][y]>=0)
		return dp[x][y];
	if(x==n && y==m)
		return 1;
	dp[x][y]=0;
	for(auto i:mov) {
		int p=i.fst,q=i.snd;
		if(valid(p,q))
			dp[x][y]+=f(p,q)%MOD;
	}
	return dp[x][y];
}

int main(){FIN;
	mset(dp,-1);
	cin>>n>>m;
	fore(i,0,n)fore(j,0,m) cin>>g[i][j];
	n--; m--;

	ll ans = f(0,0);
	cout<<ans;

	return 0;
}
