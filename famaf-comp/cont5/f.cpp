#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define fored(i,a,b) for(int i=a,ggdem=b;i>=ggdem;--i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<ii> ftion(ll n) {
    vector<ii> ans;
    for(ll i=2; i*i<=n; ++i)
        if(n%i==0) {
            ans.pb({i,0});
            while(n%i==0) {
                n/=i;
                ans.back().snd++;
            }
        }
    if(n>1) ans.pb({n,1});
    return ans;
} /* O(sqrt(n)) */

ll legendres(ll n, ll p) {
    ll ans=0, k=p;
    while(n/k!=0) {
        ans+=n/k;
        k=(k<=n/p)?k*p:n+1;
    }
    return ans;
}

int main(){
	ll n,b; cin>>n>>b;

    vector<ii> fb = ftion(b);
    vector<ll> bb;
    fore(i,0,SZ(fb)) {
        ll l=legendres(n,fb[i].fst);
        bb.pb(l);
    }

    ll mini=1e18;
    fore(i,0,SZ(fb)) {
        mini=min(mini,bb[i]/fb[i].snd);
    }

    cout<<mini<<'\n';

	return 0;
}
