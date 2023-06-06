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

#define N 10
#define M 4

int a[] = {1, 1, 4, 4, 5, 5, 7, 8, 9, 10};

int main(){FIN;
	int l=0, r=N-1;
	while(l<=r) {
		int k=(l+r)/2;
		if(a[k]>M) r=k-1; 	// si existe M, con > devuelve el indice del
		else l=k+1;			// ultimo M, con >= el anterior al primer M
	}
	cout<<r<<'\n';

	return 0;
}