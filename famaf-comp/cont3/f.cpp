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

const int MAXN = 2000;
const int MAXC = 1e6+6;

int n;
int x[MAXC], y[MAXC], val[MAXN][MAXN];
ll c[MAXN], k[MAXN];

int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
vector<pair<ll,pair<int,int> > > es; // edges (cost,(u,v))
ll kruskal(){  // assumes graph is connected
	sort(es.begin(),es.end());uf_init();
	ll r=0;
	fore(i,0,es.size()){
		int x=es[i].snd.fst,y=es[i].snd.snd;
		if(uf_join(x,y))r+=es[i].fst; // (x,y,c) belongs to mst
	}
	return r; // total cost
}

int main(){FIN;
	cin>>n;
	fore(i,0,n) cin>>x[i]>>y[i];
	fore(i,0,n) cin>>c[i];
	fore(i,0,n) cin>>k[i];

	fore(i,0,n)fore(j,0,n) {
		val[i][j]=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
	}

	ll min_c=1e12;
	fore(i,0,n) min_c=min(min_c,c[i]);



	return 0;
}
