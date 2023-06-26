#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

const int MAXN = 2*1e5+7;
const int MOD = 1e9+7;

ll fact[MAXN];

void f() {
    fact[0]=1;
    fore(i,1,MAXN)
        fact[i]=(fact[i-1]*i)%MOD;
}

int main(){
    int t; cin>>t;
    f();
    while(t--) {
        ll n; cin>>n;
        ll ans = (fact[2*n-1]*n)%MOD;

        cout<<ans<<'\n';
    }

	return 0;
}
