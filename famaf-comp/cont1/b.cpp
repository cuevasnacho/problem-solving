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
		int n; cin>>n;
		bool pos=true;
		string s1,s2; cin>>s1>>s2;
		fore(i,0,n) {
			if(s1[i]=='G')
				s1[i]='B';
			if(s2[i]=='G')
				s2[i]='B';	
		}
		fore(i,0,n) {
			if(s1[i]!=s2[i]) {
				pos=false;
				break;
			}
		}
		if(pos) 
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}