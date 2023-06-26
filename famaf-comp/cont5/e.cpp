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

const int MOD = 1e9+7;
const int MAXN = 1e6+7;

ll fact[MAXN];

ll elevar(ll b, ll e) {
    if(e==0)
        return 1;
    else if(e%2==0) {
        ll x = elevar(b,e/2);
        return (x*x)%MOD;
    }
    else {
        ll x = elevar(b,(e-1)/2);
        x = (x*x)%MOD;
        return (x*b)%MOD;
    }
}

void f(int n) {
    fact[0]=1;
    fore(i,1,n+1)
        fact[i]=(fact[i-1]*i)%MOD;
}

ll comb(ll n, ll k) {
    return fact[n]*(elevar((fact[k]*fact[n-k])%MOD,MOD-2))%MOD;
}

bool is_good(int n, int a, int b) {
	bool is=true;
	while(is && n!=0) {
		int k=n%10;
		if(k==a || k==b) n/=10;
		else is=false;
	}
	return is;
}

int main(){FIN;
	int a,b,n; cin>>a>>b>>n;
	f(n);
	ll ans=0;
	fore(i,0,n+1) {
		if(is_good(i*a+(n-i)*b,a,b)) {
			ans=(ans+comb(n,i))%MOD;
		}
	}

	cout<<ans<<'\n';

	return 0;
}
