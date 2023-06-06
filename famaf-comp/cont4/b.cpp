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

const int MAXN = 305;
int n;
ll a[MAXN];

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		cin>>n;
		fore(i,0,n) cin>>a[i];
		int p=0,q=n-1;
		while(p<q) {
			cout<<a[p]<<' '<<a[q]<<' ';
			p++; q--;
		}
		if(p==q) cout<<a[p];
		cout<<'\n';
	}

	return 0;
}
