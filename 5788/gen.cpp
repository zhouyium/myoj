//5788
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
    
    freopen("06.in", "w", stdout);
    ll maxx = 100;//1000位
    ll minx = 95;
    ll n = rand()%(maxx-minx+1)+minx;
    maxx = 100;//1000位
    minx = 90;
    ll m = rand()%(maxx-minx+1)+minx;
    cout<<n<<" "<<m<<"\n";
    maxx = 10;//1000位
    minx = 0;
    for (int i=1; i<=n; i++) {
    	for (int j=1; j<=m; j++) {
		    ll t = rand()%(maxx-minx+1)+minx;
		    if (t>=8) {
		    	t=1;
			} else {
				t=0;
			}
		    cout<<t<<" ";
		}
		cout<<"\n";
	}

    return 0;
}
