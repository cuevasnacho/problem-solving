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
	int f=0;
	fore(i,0,n) {
		if(f) {
			cout<<"I love ";
			f=0;
		} else {
			cout<<"I hate ";
			f=1;
		}
		if (n>1 && i!=n-1)
			cout<<"that ";
	}
	cout<<"it\n";

	return 0;
}