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

const int MAXN = 2*1e5+7;

int query[MAXN];

int main(){FIN;
	int n,q; cin>>n>>q;
	string s; cin>>s;
	fore(i,0,n) cin>>query[i];

	set<int> ab_nl;	// abiertos no ligados
	set<int> ce_nl;	// cerrados no ligados
	vector<int> ligados (n,0);

	fore(i,0,n) {
		if(s[i]=='(') {
			ab_nl.insert(i);
		} else {
			if(ab_nl.size()) {
				int h=*(ab_nl.lower_bound(i));
				ligados[i]=h;
				ligados[h]=i;
				ab_nl.erase(h);
			} else {
				ce_nl.insert(i);
			}
		}
	}

	fore(i,0,q) {
		int k=query[i]-1;
		if(s[i]=='(') {
			s[i]=')';
			int p=ligados[i];
			if(ab_nl.size() && ab_nl.lower_bound(1)!=ab_nl.end()) {
				int y=*(ab_nl.lower_bound(1));
				if(y<i){
					ligados[i]=y;
					ligados[y]=i;
					ab_nl.erase(y);
				}
				else {
					ce_nl.insert(i);
					ligados[i]=0;
				}
			} else {
				ce_nl.insert(i);
				ligados[i]=0;
			}

			if(ab_nl.size() && ab_nl.lower_bound(1)!=ab_nl.end()) {
				int y=*(ab_nl.lower_bound(1));
				if(y<p) {
					ligados[p]=y;
					ligados[y]=p;
					ab_nl.erase(y);
				}
				else {
					ce_nl.insert(p);
					ligados[p]=0;
				}
			} else {
				ce_nl.insert(p);
				ligados[p]=0;
			}
		}
		else {
			s[i]='(';
			int p=ligados[i];
			if(ce_nl.size() && ce_nl.lower_bound(i)!=ce_nl.end()) {
				int y=*(ce_nl.lower_bound(i));
				ligados[i]=y;
				ligados[y]=i;
				ce_nl.erase(y);
			} else {
				ab_nl.insert(i);
			}

			if(ce_nl.size() && ce_nl.lower_bound(p)!=ce_nl.end()) {
				int y=*(ce_nl.lower_bound(p));
				ligados[p]=y;
				ligados[y]=p;
				ce_nl.erase(y);
			} else {
				ab_nl.insert(p);
			}
		}

		
	}

	return 0;
}
