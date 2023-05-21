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

const int MAXN = 1024;

int p[MAXN];

int main(){FIN;
	int n; cin>>n;
	fore(i,0,n-1) cin>>p[i];
	vector<int> g[n];
	
	bool can=1;
	fore(i,0,n-1) g[p[i]-1].pb(i+1);
	fore(i,0,n) {
		if(g[i].size()>0) {
			int ctr=0;
			for(int child:g[i]) {
				if(g[child].size()==0) ++ctr;
			}
			if(ctr<3) {
				can=0; break;
			}
		}
	}

	if(can)cout<<"Yes";
	else cout<<"No";

	return 0;
}
