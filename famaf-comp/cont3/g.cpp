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

int n,m

int main(){FIN;
	cin>>n>>m;
	fore(i,0,m) {
		int u,v,w; cin>>u>>v>>w;
		u--;v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}

	return 0;
}
