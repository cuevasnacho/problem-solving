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

bool is_prime(ll n) {
    if(n==1) return false;
    for(ll i=2; i*i<=n; ++i) 
        if(n%i==0) return false;
    return true;
} /* O(sqrt(n)) */

vector<ll> find_d(ll n) {
    vector<ll> ans;
    for(ll i=2; i*i<=n; ++i)
        if(n%i==0) {
            ans.pb(i);
            if(i!=n/i)ans.pb(n/i);
        }
    return ans;
} /* O(sqrt(n)) */

vector<ii> ftion(ll n) {    // puede ser map
    vector<ii> ans;
    for(ll i=2; i*i<=n; ++i)
        if(n%i==0) {
            res.pb({i,0});
            while(n%i==0) {
                n/=i;
                res.back().snd++;
            }
        }
    if(n>1) ans.pb({n,1});
    return ans;
} /* O(sqrt(n)) */

/* Otra forma mas eficiente es hacer la criba e ir guardando
   el primo mas chico que lo divide, entonces la busqueda
   de cada factor es O(1) */

const int MAXN = 1e5+7;
bool sieve[MAXN];
ll min_p[MAXN];

/* Para factorizar muchos numeros */
/* Es posible factorizar 1e6 numeros de hasta 1e6 */

void sieve_init() {
    fore(i,2,MAXN) if(!sieve[i]) {
        int j=i;
        while(j<MAXN) { // optimizacion posible, comenzar cada primo desde i*i
                        // logra O(log(log(n))) casi O(n)
            if(!sieve[j]) {
                sieve[j]=1;
                min_p[j]=i;
            }
            j+=i;
        }
    }
}

vector<ll> ftion(ll n) {
    vector<ll> ans;
    while(n!=1) {
        ans.pb(min_p[n]);
        n/=min_p[n];
    }
    return ans;
}

/* Calcular mcd con gcd en c++ */
ll mcd(ll x, ll y) {
    if(x==y) return x;
    if(x>y) return mcd(x%y,y);
    else return mcd(x,y%x);
} /* O(log(max(x,y))) */

/* Calcular mcm con lcm */
ll mcm(ll x, ll y) {
    return (x*y)/mcd(x,y);
} /* O(log(max(x,y))) */

/* Si tengo una factorizacion en primos de un numero n,
   puedo contar la cantidad de divisores de n haciendo
   el producto de cada exponente de cada primo mas 1.
   (e1+1)(e2+1)...(ek+1) */

/* Cantidad de factores p primos en n! */
ll legendres(ll n, ll p) {
    ll ans=0, k=p;
    while(n/k!=0) {
        ans+=n/k;
        k=(k<=n/p)?k*p:n+1;
    }
    return ans;
}
