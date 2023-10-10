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
    
    freopen("09.in", "w", stdout);
    
    int T=100;
    printf("%d\n", T);
    while (T--) {
	    //生成n,m
	    ll maxx = 2000;//1000位
	    ll minx = 2000;
	    ll n = rand()%(maxx-minx+1)+minx;
	    printf("%lld\n", n);
	
		//生成m个名字 
	    maxx = n/9;//1000位
	    minx = n/10;
	    ll m = rand()%(maxx-minx+1)+minx;
		for (ll i=1; i<=m; i++) {
			int len=rand()%10+5;
			for (int j=1; j<len; j++) {
				char ch=rand()%26+'a';
				name[i].push_back(ch);
			}
		}
		
		//输出n次 
	    maxx = m;//1000位
	    minx = 1;
		for (ll i=1; i<=n; i++) {
			ll t = rand()%(maxx-minx+1)+minx;
			cout<<name[t]<<"\n";
		}
		
		//
		for (int i=1; i<=m; i++) {
			name[i].clear();
		}
	}
    
    return 0;
}
