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

const int MAXN = 64;
int n;
string s[MAXN];
ii cas[4] = {{0,1},{1,0},{-1,0},{0,-1}};

vector<pair<int,int> > g[MAXN];  // u->[(v,cost)]
ll dist[MAXN];
void dijkstra(int x){
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<ll,int> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst; ll c=g[x][i].snd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
	}
}

bool valid(ii p) {
	return p.fst<n && p.snd<n && p.fst>=0 && p.snd>=0;
}

void parse() {
	fore(i,0,n)fore(j,0,n) if(s[i][j]=='0') {
		fore(k,0,4) if(valid(cas[k])) {
			if(s[i][j]=='0')
		}
	}
}

int main(){FIN;
	cin>>n;
	ii r1,r2;
	cin>>r1.fst>>r1.snd>>r2.fst>>r2.snd;

	fore(i,0,n) cin>>s[i];

	return 0;
}
