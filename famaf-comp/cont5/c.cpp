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

vector<ll> find_d(ll n) {
    vector<ll> ans;
    ans.pb(n);
    for(ll i=2; i*i<=n; ++i)
        if(n%i==0) {
            ans.pb(i);
            if(i!=n/i)ans.pb(n/i);
        }
    return ans;
} /* O(sqrt(n)) */

int main(){FIN;
	int n; cin>>n;
    vector<int> d(n);
    fore(i,0,n) cin>>d[i];

    sort(d.rbegin(),d.rend());

    int x=d[0],y;
    vector<ll> xdiv = find_d(x);

    sort(xdiv.rbegin(),xdiv.rend());

    fore(i,1,SZ(d)) {
        if(d[i]!=xdiv[i]) {
            y=d[i];
            break;
        }
    }

    cout<<x<<' '<<y<<'\n';

	return 0;
}
