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
typedef pair<ll,ll> ii;

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vector<set<ll>> a (n);
		vector<int> sum (n,0);
		fore(i,0,n) {
			ll p,q; cin>>p>>q; p--;
			a[p].insert(q);
		}

		ll ans=0, x=0;
		fore(i,0,n) {
			while(a[i].size()) {
				auto p = *(a[i].rbegin());
				a[i].erase(p);
				ans+=p;
				x++;
				sum[i]++;
				if(i+1<=x) {
					break;
				}
			}
			x-=sum[i];
		}

		cout<<ans<<'\n';
	}

	return 0;
}
