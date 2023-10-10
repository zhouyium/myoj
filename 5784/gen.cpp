//5784
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif	
    int seed = time(NULL);
    if (argc>1) {
        //ÓÐ²ÎÊý
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
	
	ll maxx=1e5;
	ll minx=1e5;
	ll T = rand()%(maxx-minx+1)+minx;
	cout<<T<<"\n";
	maxx=1e9;
	minx=9e8;
	while (T--) {
		ll a=rand()%(maxx-minx+1)+minx;
		cout<<a<<"\n";
	}

    return 0;
}
