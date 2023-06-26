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

bool is_prime(ll n) {
    if(n==1) return false;
    for(ll i=2; i*i<=n; ++i) 
        if(n%i==0) return false;
    return true;
} /* O(sqrt(n)) */

int main(){FIN;
	int t; cin>>t;
    while(t--) {
        ll a,b; cin>>a>>b;
        if(abs(a-b)!=1) {
            cout<<"NO\n";
        } else {
            a+=b;
            if(is_prime(a)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }

	return 0;
}
