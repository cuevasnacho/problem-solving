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
	int n,m; cin>>n>>m;
	vector<int> a (m);
	fore(i,0,m) {
		cin>>a[i];
	}
	int q[n+1]; // cantidad de c num
	mset(q,0);

	set<int> s; // para saber si puedo imp 1
	fore(i,0,m) {
		s.insert(a[i]);
		++q[a[i]];
		if(SZ(s)==n) {
			cout<<'1';
			s.clear();
			fore(j,1,n+1) {
				--q[j];
				if(q[j])
					s.insert(j);
			}
		} else {
			cout<<'0';
		}
	}
	cout<<'\n';

	return 0;
}