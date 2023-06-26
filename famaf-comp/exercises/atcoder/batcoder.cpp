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

#define INF 0
#define oper max
#define NEUT INF

struct STree { // segment tree for min over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e){
		if(s+1==e){st[k]=0;return;}
		int m=(s+e)/2;
		init(2*k,s,m);init(2*k+1,m,e);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(){init(1,0,n);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main(){FIN;
    int n,m; cin>>n>>m;
    vector<ii> a(m);
    fore(i,0,m) {
        int x,y; cin>>x>>y;
        a[i]={x,-y};
    }
    sort(a.begin(),a.end());
    fore(i,0,m) a[i].snd*=-1;

    STree rmq(n); rmq.init();
    fored(i,m-1,0) {
        int maxi=rmq.query(a[i].snd,n);
        rmq.upd(a[i].snd-1,maxi+1);
    }
    cout<<rmq.query(0,n)<<'\n';

	return 0;
}
