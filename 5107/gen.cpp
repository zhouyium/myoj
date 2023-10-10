#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
string name[MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("05.in", "w", stdout);
    
    int T=4;
    printf("%d\n", T);
    while (T--) {
	    //生成n,m
	    ll maxx = 1e5;//1000位
	    ll minx = 1e5;
	    ll n = rand()%(maxx-minx+1)+minx;
	    maxx = n;//1000位
	    minx = n;
	    ll m = rand()%(maxx-minx+1)+minx;
	    printf("%lld\n", n);
	
	    maxx = 100;//1000位
	    minx = 0;
		for (ll i=1; i<=n; i++) {
			int len=rand()%10+5;
			for (int j=1; j<len; j++) {
				char ch=rand()%26+'a';
				name[i].push_back(ch);
			}
			ll t = rand()%(maxx-minx+1)+minx;
			cout<<name[i];
		    printf(" %lld\n", t);
		}
		
		printf("%lld\n", m);
	    maxx = n;//1000位
	    minx = 1;	
		for (ll i=1; i<=m; i++) {
			ll t = rand()%(maxx-minx+1)+minx;
			cout<<name[t]<<"\n";
		}
		
		//
		for (int i=1; i<=n; i++) {
			name[i].clear();
		}
	}
    
    return 0;
}
