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

bool visited[1002][1002];
int m[1002][1002];

ll solve(int x, int y) {
	ll a=0,b=0,c=0,d=0;
	if(m[x+1][y]>0 && !visited[x+1][y]) {
		visited[x+1][y]=1;
		a = m[x+1][y] + solve(x+1,y);
	}
	if(m[x-1][y]>0 && !visited[x-1][y]) {
		visited[x-1][y]=1;
		b = m[x-1][y] + solve(x-1,y);
	}
	if(m[x][y+1]>0 && !visited[x][y+1]) {
		visited[x][y+1]=1;
		c = m[x][y+1] + solve(x,y+1);
	}
	if(m[x][y-1]>0 && !visited[x][y-1]) {
		visited[x][y-1]=1;
		d = m[x][y-1] + solve(x,y-1);
	}
	return (ll)a+b+c+d;
}

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		int n,r;cin>>n>>r;
		fore(i,0,n+2) {
			fore(j,0,r+2) {
				visited[i][j]=0;
				m[i][j]=0;
			}
		}

		ll mx=0;
		fore(i,1,n+1) {
			fore(j,1,r+1) {
				cin>>m[i][j];
			}
		}
		fore(i,1,n+1) {
			fore(j,1,r+1) {
				if(m[i][j]>0 && !visited[i][j]) {
					visited[i][j]=1;
					ll ans = m[i][j]+solve(i,j);
					mx=(mx>ans)?mx:ans;
				}
			}
		}
		cout<<mx<<'\n';
	}

	return 0;
}
