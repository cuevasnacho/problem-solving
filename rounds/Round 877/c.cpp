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

const int MAXN = 1e3+5;

int a[MAXN][MAXN];

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		int n,m; cin>>n>>m;
		int p=1;
		if(m%2==0) {
			fore(i,0,n) {
				fore(j,0,m) {
					cout<<p<<' ';
					p++;
				}
				cout<<'\n';
			}
		} else {
			int k=1;
			fore(i,0,n/2) {
				fore(j,1,m+1) {
					cout<<m*k+j<<' ';
				}
				k+=2;
				cout<<'\n';
			}
			k=0;
			fore(i,0,n/2+(n%2)) {
				fore(j,1,m+1) {
					cout<<m*k+j<<' ';
				}
				k+=2;
				cout<<'\n';
			}
		}
		cout<<'\n';
	}

	return 0;
}
