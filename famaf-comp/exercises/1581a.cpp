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

const int MOD = 1e9+7;
const int MAXN = 2*1e5+5;

ll fact[MAXN];

void f() {
	fact[0]=1;
	fore(i,1,MAXN) fact[i]=(fact[i-1]*i)%MOD;
}

int main(){FIN;
	int t; cin>>t;
	f();
	while(t--) {
		int n; cin>>n;
		cout<<fact[2*n]<<'\n';
	}

	return 0;
}
