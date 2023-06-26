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

int main(){FIN;
	int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        ll ctr2=0,ctr3=0;
        while(n%3==0) {
            n/=3;
            ctr3++;
        }
        while(n%2==0) {
            n/=2;
            ctr2++;
        }
        if(n>1 || ctr3<ctr2) cout<<-1<<'\n';
        else cout<<2*ctr3-ctr2<<'\n';
    }

	return 0;
}
