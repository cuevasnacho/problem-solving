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
        int n; cin>>n;
        vector<ll> a(n);
        vector<ll> b(n);
        fore(i,0,n) cin>>a[i];
        fore(i,0,n) cin>>b[i];

        int l=0,r=1e9;
        while(l<=r) {
            int k=(l+r)/2;
            bool can=1;
            ll sum=0;
            fore(i,0,n) {
                if(a[i]>k) sum+=b[i];
                if(sum>k) {
                    can=0;
                    break;
                }
            }
            if(can) r=k-1;
            else l=k+1;
        }
        cout<<r+1<<'\n';
    }

	return 0;
}
