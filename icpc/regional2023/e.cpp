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

int solve(int K, int E, int R) {
  if(E!=K && K!=R && E!=R) {
    return 0;
  }
  if(E>=5 && R>=5) {
    return 0;
  }
  if(E==0) {
    if(R==K && K<3)
      return 1;
    else
      return 0;
  }
  if(R==0) {
    if(E==K && K<3)
      return 1;
    else
      return 0;
  }

  if(K==R) {
    R=E;
    E=K;
  } else if(E==R) {
    R=K;
    K=E;
  }
  if(E==K && K==R) {
    if(E==1 || E==4) {
      return 2;
    } else {
      return 3;
    }
  }
  // E==K, R!=E
  if(R>E) {
    if(E<=2) {
      return 1;
    } else {
      return 0;
    }
  } else if(E<5) {
    if(E==2) {
      return 2;
    } else if(E==3) {
      return R;
    } else {
      return R%2;
    }
  } else {
    return 0;
  }
}

int main(){FIN;
  int N,K,E;cin>>N>>K>>E;
  int R=N-K-E;

  int result = solve(K,E,R);

  cout<<result<<"\n";
  
  return 0;
}