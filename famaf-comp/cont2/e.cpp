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
		vector<ii> a(n);
		fore(i,0,n) {
			cin>>a[i].snd;
			cin>>a[i].fst;
		}
		int l=1,r=n;
		while(l<=r) {
			int k=(l+r)/2;
			int ctr=0;
			bool can=0;
			fore(i,0,n) if(!can) {
				if(a[i].fst>=ctr && a[i].snd>=k-ctr-1) {
					ctr++;
				}
				if(ctr>=k) can=1;
			}
			if(can) l=k+1;
			else r=k-1;
		}
		cout<<r<<'\n';
	}

	return 0;
}