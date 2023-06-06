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

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n) cin>>a[i];
		sort(ALL(a));
		if(a[0]<0) cout<<a[0]<<'\n';
		else if(a[0]==0) {
			if(a[n-1]==0) cout<<0<<'\n';
			else cout<<a[n-1]<<'\n';
		}
		else cout<<a[n-1]<<'\n';
	}

	return 0;
}
