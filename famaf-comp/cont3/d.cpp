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
int n, mn=1e5;
string s[MAXN];
ii cas[4] = {{0,1},{1,0},{-1,0},{0,-1}};

bool vis[MAXN][MAXN];
vector<ii> beg;

bool valid(int i, int j) {
	return i<n && j<n && i>=0 && j>=0 && s[i][j]=='0';
}

void dfs1(int x, int y) {
	vis[x][y]=1;
	beg.pb({x,y});
	for (ii p:cas) {
		int i=p.fst+x, j=p.snd+y;
		if(valid(i,j) & !vis[i][j]) {
			dfs1(i,j);
		}
	}
}

void dfs2(int x, int y) {
	vis[x][y]=1;
	fore(k,0,beg.size()) {
		int formulita=(beg[k].first-x)*(beg[k].first-x)+(beg[k].snd-y)*(beg[k].snd-y);
		mn=min(mn,formulita);
	}
	for (ii p:cas) {
		int i=p.fst+x, j=p.snd+y;
		if(valid(i,j) & !vis[i][j]) {
			dfs2(i,j);
		}
	}
}

int main(){FIN;
	cin>>n;
	int r1,c1,r2,c2;
	cin>>r1>>c1>>r2>>c2;
	r1--;c1--;r2--;c2--;
	fore(i,0,n) cin>>s[i];

	dfs1(r1,c1);
	if(vis[r2][c2])
		cout<<0;
	else {
		dfs2(r2,c2);
		cout<<mn<<'\n';
	}

	return 0;
}
