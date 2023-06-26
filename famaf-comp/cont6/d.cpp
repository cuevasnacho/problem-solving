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

#define INF 1e6
#define oper min
#define NEUT INF

bool checkp(int n) {
    if(n==0) return 0;
    int ctr=0;
    while(!(n&1)) {
        ctr++;
        n=n>>1;
    }
    return ctr%2;
}

struct STree { // segment tree for min over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		if(checkp(e-s)) st[k]=st[2*k]|st[2*k+1];
        else st[k]=st[2*k]^st[2*k+1];
	}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
        if(checkp(e-s)) st[k]=st[2*k]|st[2*k+1];
        else st[k]=st[2*k]^st[2*k+1];
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
        if(checkp(e-s)) return query(2*k,s,m,a,b)|query(2*k+1,m,e,a,b);
        else return query(2*k,s,m,a,b)^query(2*k+1,m,e,a,b);
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main(){FIN;
    int n,m; cin>>n>>m;
    int rg = 1<<n;
    int a[1<<n];
    fore(i,0,rg) cin>>a[i];
    STree rmq(rg); rmq.init(a);
    while(m--) {
        int p,b; cin>>p>>b;
        rmq.upd(p-1,b);
        cout<<rmq.query(0,rg)<<'\n';
    }

	return 0;
}
