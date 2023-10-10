//http://47.110.135.197/problem.php?id=6470
//6470: 暴富的老周
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e5+10;
int a[N];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("08.in", "w", stdout);
    
    //生成n,x,y
    LL maxx = 200;//1000位
    LL minx = 200;
    LL n = rand()%(maxx-minx+1)+minx;
	maxx=n;
	minx=1;
    LL x = rand()%(maxx-minx+1)+minx;
	maxx=n;
	minx=1;
    LL y = rand()%(maxx-minx+1)+minx;
    cout<<n<<" "<<n*(n-1)/2<<1<<" "<<200<<"\n";
    
	maxx=1e6;
	minx=100;
    for (int i=1; i<=n; i++) {
		LL t = rand()%(maxx-minx+1)+minx;
		cout<<t<<" ";
	}
	cout<<"\n";
	
	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			cout<<i<<" "<<j<<"\n";
		}
	}

    return 0;
}
