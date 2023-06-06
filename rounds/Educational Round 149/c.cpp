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
		string s; cin>>s;
		char c='?';
		if(s[0]==c) {
			cout<<'0';
			c='0';
		} else {
			cout<<s[0];
			c=s[0];
		}
		fore(i,1,s.length()) {
			if(s[i]!='?') c=s[i];
			cout<<c;
		}
		cout<<'\n';
	}

	return 0;
}
