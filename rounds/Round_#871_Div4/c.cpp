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
	while(t--) {
		int n; cin>>n;
		vector<int> one;
		vector<int> two;
		vector<int> both;

		fore(i,0,n) {
			int m; cin>>m;
			string s; cin>>s;
			if(s[0]=='1' && s[1]=='1') both.pb(m);
			else if(s[0]=='1') one.pb(m);
			else if(s[1]=='1') two.pb(m);

		}
		sort(ALL(both));
		sort(ALL(one));
		sort(ALL(two));

		int mn=INT_MAX;
		if(both.size()>0) mn=both[0];
		if(SZ(one)>0 && SZ(two)>0) mn=min(mn,one[0]+two[0]);

		if(mn!=INT_MAX)
			cout<<mn<<'\n';
		else
			cout<<-1<<'\n';
	}

	return 0;
}
