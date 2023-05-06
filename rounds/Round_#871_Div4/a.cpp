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

int main(){FIN;
	int t; cin>>t;
	string cod = "codeforces";
	while(t--) {
		string s; cin>>s;
		int ctr=0;
		fore(i,0,10) {
			if(s[i]!=cod[i]) ctr++;
		}
		cout<<ctr<<'\n';
	}

	return 0;
}
