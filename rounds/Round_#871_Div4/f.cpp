#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		int n,m; cin>>n>>m;
		vector<int> adj[n];
		fore(i,0,m) {
			int u,v; cin>>u>>v;
			--u;--v;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		pair<int,int> x = {0,0};
		pair<int,int> y = {0,0};
		fore(i,0,n) {
			int sz=adj[i].size();
			if(sz>1) {
				if(!x.fst) {
					x.fst=sz;
					x.snd++;
				} else if(x.fst==sz) {
					x.snd++;
				} else {
					if(!y.fst)
						y.fst=sz;
					y.snd++;
				}
			}
		}
		if(!y.fst) {
			y.fst=x.fst;
			y.snd=x.snd-1;
			x.snd=1;
		}
		if(x.snd==1) {
			cout<<x.fst<<' '<<y.fst-1<<'\n';
		}
		else {
			cout<<y.fst<<' '<<x.fst-1<<'\n';
		}
	}

	return 0;
}
