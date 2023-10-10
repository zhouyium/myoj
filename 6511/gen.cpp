//6511: 老周的礼物
//http://47.110.135.197/problem.php?id=6511
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+10;
LL a[N];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    //生成n,x,y
    LL maxx = 2e5;//1000位
    LL minx = 2e5;
    LL n = rand()%(maxx-minx+1)+minx;
	maxx=n;
	minx=n/10*9;
    LL m = rand()%(maxx-minx+1)+minx;
    cout<<n<<" "<<m<<"\n";
    
	maxx=1000;
	minx=100;
    for (int i=1; i<=n; i++) {
		LL t = rand()%(maxx-minx+1)+minx;
		cout<<t<<" ";
	}
	cout<<"\n";

    return 0;
}
