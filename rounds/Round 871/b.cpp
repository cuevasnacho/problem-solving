#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int a[100];

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		fore(i,0,n) cin>>a[i];

		int mx=0, ctr=0;
		fore(i,0,n) {
			if(!a[i]) ++ctr;
			else {
				mx=max(mx,ctr);
				ctr=0;
			}
		}
		mx=max(mx,ctr);
		cout<<mx<<'\n';
	}

	return 0;
}
