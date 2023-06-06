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

bool isRegular(string s) {
	int open=0;
	fore(i,0,s.length()) {
		if(s[i]=='(')
			open++;
		else {
			open--;
			if(open<0) return 0;
		}
	}
	return open==0;
}

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		int n;cin>>n;
		string s;cin>>s;
		
		int ctr=0;
		fore(i,0,n) {
			if(s[i]=='(') ++ctr;
			else --ctr;
		}
		if(!ctr) {
			if(s[0]==')') reverse(ALL(s));
			if(isRegular(s)) {
				cout<<1<<'\n';
				fore(i,0,n) cout<<1<<' ';
			} else {
				cout<<2<<'\n';
				fore(i,0,n) {
					if(s[i]=='(') cout<<1<<' ';
					else cout<<2<<' ';
				}
			}
		} else {
			cout<<-1;
		}
		cout<<'\n';
	}

	return 0;
}
