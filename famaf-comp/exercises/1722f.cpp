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

const int MAXN = 50;

int n,m;
string s[MAXN];
bool visited[MAXN][MAXN];

bool valid(int i, int j) {
	return i>=0 && i<n && j>=0 && j<m;
}

int main(){FIN;
	int t; cin>>t;
	while(t--) {
		cin>>n>>m;
		fore(i,0,n)cin>>s[i];
		fore(i,0,n)fore(j,0,m) {
			if(!visited[i][j] && s[i][j]=='*') {
				
			}
		}
	}

	return 0;
}
