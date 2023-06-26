#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(uint i=a,ggdem=b;i<ggdem;++i)
#define fored(i,a,b) for(int i=a,ggdem=b;i>=ggdem;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned int uint;

const uint MAXN = 3*1e5+7;
const uint MAXA = 15000007;

uint a[MAXN];
bool sieve[MAXA];
uint min_p[MAXA];
uint primes[MAXA];

void sieve_init(uint n) {
    fore(i,2,n+1) if(!sieve[i]) {
        sieve[i]=1;
        min_p[i]=i;
        uint j=(i<(n+1)/i)?i*i:n+1;
        while(j<n+1) {
            if(!sieve[j]) {
                sieve[j]=1;
                min_p[j]=i;
            }
            j+=i;
        }
    }
}

void ftion(uint n) {
    uint dsr=0;
    while(n!=1) {
        if(min_p[n]!=dsr) {
            dsr=min_p[n];
            primes[dsr]++;
        }
        n/=min_p[n];
    }
}

int main(){
	uint n; cin>>n;
    fore(i,0,n) cin>>a[i];
    
    bool equal=true;
    fore(i,0,n-1) if(a[i]!=a[i+1]) {equal=false; break;}

    if(!equal) {
        sieve_init(MAXA);
        uint md=__gcd(a[0],a[1]);
        fore(i,2,n) md=__gcd(md,a[i]);
        fore(i,0,n) a[i]/=md;
        fore(i,0,n) ftion(a[i]);

        uint maxi=0;
        fore(i,2,MAXA) maxi=max(maxi,primes[i]);
        cout<<n-maxi<<'\n';
    } else cout<<-1<<'\n';

	return 0;
}