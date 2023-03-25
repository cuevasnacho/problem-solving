#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int N,H,W;

int main(){FIN;
  cin>>N>>H>>W;
  fore(i,0,N) {
    char f,s;cin>>f>>s;
    if(f=='Y') {
      --H; ++W;
      cout<<"Y ";
    } else {
      if(!W) {
        --H; ++W;
        cout<<"Y ";
      } else {
        cout<<"N ";
      }
    }
    if(s=='Y') {
      --W; ++H;
      cout<<"Y\n";
    } else {
      if(!H) {
        --W; ++H;
        cout<<"Y\n";
      } else {
        cout<<"N\n";
      }
    }
  }
  
  return 0;
}