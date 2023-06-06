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

const int MAXN = 2*1e5+7;

int a[MAXN];

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		fore(i,0,n) cin>>a[i];

		int p=0,u=0,d=0;
		fore(i,0,n) {
			if(a[i]==1) p=i;
			else if(a[i]==n) u=i;
			else if(a[i]==2) d=i;
		}

		if((u>p && u<d) || (u<p && u>d)) cout<<p+1<<' '<<p+1;
		else if((p>u && p<d) || (p<u && p>d)) cout<<p+1<<' '<<u+1;
		else cout<<d+1<<' '<<u+1;
		cout<<'\n';
	}

	return 0;
}
