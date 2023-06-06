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

int solve(int n, int m) {
	if(n==m) {
		return 1;
	} else {
		if(!(n%3) && (n>=m)) {
			return max(solve(n/3,m),solve((2*n)/3,m));
		} else {
			return 0;
		}
	}
}

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		int n,m; cin>>n>>m;
		int can;
		can=solve(n,m);
		if(can)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}
