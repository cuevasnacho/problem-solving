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

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		int n,l,r; cin>>n>>l>>r;
		vector<int> a(n);
		fore(i,0,n) cin>>a[i];
		sort(ALL(a));

		// A = #pares i+j<=r y B = #pares i+j<=l-1
		// A = #pares i<=r-j y B = #pares i<=l-j-1
		int sum=0;
		fore(i,0,n-1) {
			int p=i+1,q=n-1;
			int k=0, pairs;
			while(p<=q) {
				k=(p+q)/2;
				if(a[i]+a[k]<r)
					p=k+1;
				else if(a[i]+a[k]>r)
					q=k-1;
				else
					break;
			}
			pairs=q-i;
			cout<<pairs<<" ";
			p=i+1,q=n-1;
			while(p<=q) {
				k=(p+q)/2;
				if(a[i]+a[k]<l-1)
					p=k+1;
				else if(a[i]+a[k]>l-1)
					q=k-1;
				else
					break;
			}
			cout<<k-i<<" ";
			pairs-=k-i;
			sum+=pairs;
		}
		cout<<sum<<'\n';
	}

	return 0;
}