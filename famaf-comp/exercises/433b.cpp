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

int main(){FIN;
	int n; cin>>n;
	vector<ll> v (n+1);
	vector<ll> t1 (n+1);
	fore(i,1,n+1) {
		cin>>v[i];
	}
	
	t1[0] = 0;
	fore(i,1,n+1) {
		t1[i] = v[i] + t1[i-1];
	}
	sort(ALL(v));
	fore(i,1,n+1) {
		v[i] = v[i] + v[i-1];
	}
	int m; cin>>m;
	int t,l,r;
	fore(i,0,m) {
		cin>>t>>l>>r;
		if (t==1) {
			cout<<t1[r]-t1[l-1]<<'\n';
		} else {
			cout<<v[r]-v[l-1]<<'\n';
		}
	}

	return 0;
}