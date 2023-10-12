//4330: §3 2 【例2-3】围圈报数
//http://47.110.135.197/problem.php?id=4330
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e5+10;

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("00.in", "w", stdout);
    LL maxx = 1e3;
    LL minx = 1;
    LL T = 1;
	//cout<<n<<"\n";
	
	for (LL i=1; i<=T; i++)	{
		//数字 N
		minx=1000;
		maxx=1000;
		LL n = rand()%(maxx-minx+1)+minx;
		minx=1;
		maxx=8;
		LL m = rand()%(maxx-minx+1)+minx;
		cout<<m<<" "<<n<<"\n";
	}
	
    return 0;
}
