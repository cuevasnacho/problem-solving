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
	int n,q; cin>>n>>q;
	string s; cin>>s;
	vector<int> v (n+1);
	v[0]=0;
	fore(i,0,n) {
		v[i+1]=s[i]-'a'+1+v[i];
	}

	fore(i,0,q) {
		int l,r; cin>>l>>r;
		cout<<v[r]-v[l-1]<<'\n';
	}

	return 0;
}