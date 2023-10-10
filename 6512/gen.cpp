//6512: 成绩排名（score）
//http://47.110.135.197/problem.php?id=6512
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
    LL maxx = 10000;//1000位
    LL minx = 10000;
    LL n = rand()%(maxx-minx+1)+minx;
    cout<<n<<"\n";
    
	maxx=100;
	minx=0;
    for (int i=1; i<=n; i++) {
		a[i] = rand()%(maxx-minx+1)+minx;
		cout<<a[i]<<" ";
	}
	cout<<"\n";

	maxx=n;
	minx=1;
    LL m = rand()%(maxx-minx+1)+minx;
    cout<<a[m]<<"\n";

    return 0;
}
