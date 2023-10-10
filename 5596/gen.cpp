//5596: 臭豆腐（tofu）
//http://47.110.135.197/problem.php?id=5596
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=5e1+10;
LL a[N];

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    LL T;
    T=1;
    //cout<<T<<"\n";
    while (T--) {
	    //生成n,x,y
	    LL maxx = 50;
	    LL minx = 50;
	    LL n = rand()%(maxx-minx+1)+minx;
	    cout<<n<<"\n";
	    
		maxx=1e2;
		minx=1;
	    for (LL i=1; i<=n; i++) {
	    	LL a = rand()%(maxx-minx+1)+minx;
			cout<<a<<" ";
		}
		cout<<"\n";
	}

    return 0;
}
