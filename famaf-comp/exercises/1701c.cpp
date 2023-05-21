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
#define MAX 200004

int a[MAX], c[MAX];
int pos[MAX];

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		int n,m; cin>>n>>m;
		fore(i,1,n+1)
			c[i]=0;
		fore(i,0,min(MAX,((m+1)/n)*2))
			pos[i]=0;
		fore(i,0,m) {
			cin>>a[i];
			++c[a[i]];
		}
		int p=1, q=((m+1)/n)*2; // cota superior
		while (true) {
			int k=(p+q)/2; // hacer binary search
			int tks=0,e;
			pos[k]=2;
			fore(j,1,n+1) {
				e=min(c[j],k);
				e+=(k-e)/2;
				tks+=e;
				if(tks>=m) {
					pos[k]=1; // dice si se puede en tiempo k
					break;
				}
			}
			if(!(q-p)) {
				if(pos[q]==2)
					cout<<q+1<<'\n';
				else
					cout<<q<<'\n';
				break;
			} else if (pos[k]==1) {
				q=(q==k)?k-1:k;
			} else {
				p=(p==k)?k+1:k;
			}
		}
	}
}