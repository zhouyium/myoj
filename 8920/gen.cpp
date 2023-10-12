//8920: 方格路径（一）
//http://47.110.135.197/problem.php?id=8920
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=1e3+10;
char a[N][N];

LL ran(LL l=1,LL r=1e3) {
	if (l>r) {
		swap(l,r);
	}
	return rand()%(r-l+1)+l;
}

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    LL T = 1;
	//cout<<T<<"\n";
	
	while (T--)	{
		//n
		LL n = ran(1e3,1e3);
		LL m = ran(1e3,1e3);
		cout<<n<<" "<<m<<"\n";
		//ai
		for(LL i=1;i<=n;i++){
			for(LL j=1;j<=m;j++){
				LL x = ran(1,1e2);
				if(i==1&&j==1){
					cout<<'.';
				}else if(x>=5){
					cout<<".";
				}else{
					cout<<"#";
				}
			}
			cout<<'\n';
		}
	}
	
    return 0;
}
