#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;
const int MAXN = 1e6+6;
ll fact[MAXN];

/* Exponenciacion Binaria */
ll elevar(ll b, ll e) {
    if(e==0)
        return 1;
    else if(e%2==0) {
        ll x = elevar(b,e/2);
        return x*x%MOD;
    }
    else {
        ll x = elevar(b,(e-1)/2);
        x = x*x%MOD;
        return x*b%MOD;
    }
}

/* Factorial */
void f() {
    fact[0]=1;
    fore(i,0,MAXN)
        fact[i]=fact[i-1]*i%MOD;
}

/* Combinatoria */
ll comb(ll n, ll k) {
    return fact[n]*(elevar(fact[k]*fact[n-k]%MOD,MOD-2))%MOD;
}

ll ceil(ll x, ll y) {
    return (x+y-1)/y;
}
