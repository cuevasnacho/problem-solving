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
	int n; cin>>n;
	vector<pair<int,int>> a (n+1);
	a[0].fst=0;
	a[0].snd=0;
	fore(i,1,n+1) {
		cin>>a[i].fst;
		cin>>a[i].snd;
	}
	sort(ALL(a));
	
	bool guess=false;
	fore(i,0,n) {
		if(a[i].snd>a[i+1].snd) {
			guess=true;
			break;
		}
	}
	
	if(guess)
		cout<<"Happy Alex\n";
	else
		cout<<"Poor Alex\n";

	return 0;
}