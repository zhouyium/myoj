//5816
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("02.in", "w", stdout);
    
    int T=5;
    cout<<T<<"\n";
    while (T--) {
	    //生成n,m
	    ll maxx = 10;//1000位
	    ll minx = 10;
	    ll n = rand()%(maxx-minx+1)+minx;
	    cout<<n<<"\n";
	    maxx=100;
		minx=100;
	    for (ll i=1; i<=n; i++) {
	    	ll x=rand()%(maxx-minx+1)+minx;
	    	cout<<x<<" ";
		}
		cout<<"\n";    	
	}

    return 0;
}

