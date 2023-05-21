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

ll a[MAXN];
ll cpy[MAXN];

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		fore(i,0,n) cin>>cpy[i];
		ll l=0,r=1e9;
		while(l<=r) {
			fore(i,0,n) a[i]=cpy[i];
			ll k=(l+r)/2;
			fored(i,n-1,2) {
				ll d=max(0ll,a[i]-k);
				d=min(d,cpy[i]);
				d/=3;
				a[i-1]+=d;
				a[i-2]+=2ll*d;
				a[i]-=d;
			}
			bool can=1;
			fore(i,0,n) if(a[i]<k) can=0;
			if(can) l=k+1;
			else r=k-1;
		}
		cout<<r<<'\n';
	}

	return 0;
}