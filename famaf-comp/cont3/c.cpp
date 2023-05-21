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

const int MAXN = 2001;

vector<int> g[MAXN];
int d[MAXN];
bool vis[MAXN];

int main(){FIN;
	int n,ans=0; cin>>n;
	for (int i=0,e;i<n;++i) {
		cin>>e;
		if(e==-1)
		g[0].pb(i+1);
		else
		g[e].pb(i+1);
	}

	queue<int> q;
	q.push(0);
	vis[0] = true;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int u : g[v]) {
			if(!vis[u]) {
				vis[u] = true;
				q.push(u);
				d[u] = d[v]+1;
				ans=max(d[u],ans);
			}
		}
	}

	cout<<ans<<endl;

	return 0;
}