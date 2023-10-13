//8949: DP40 小红取数
//http://47.110.135.197/problem.php?id=8949

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=2e6+10;

string s="abcdefghijklmnopqrstuvwxyz";
string s1="love";

LL ran(LL l=1,LL r=1e3) {
	if (l>r) {
		swap(l,r);
	}
	return rand()%(r-l+1)+l;
}

int main(int argc, char *argv[]) {
	LL sum=0;
	LL cnt=1;
	do {
		sum+=cnt*cnt;
		cout<<"cnt="<<cnt<<",sum="<<sum<<"\n";
		cnt++;
	}while (sum<10000);

	int seed = time(NULL);
	if (argc>1) {
		//有参数
		seed = atoi(argv[1]);
	}
	srand(seed);
	
	freopen("11.in", "w", stdout);
	
	LL T = 1;
	//cout<<T<<"\n";
	
	while (T--)	{
		//n
		LL n = ran(1e3,1e3);
		LL m = ran(9e2,1e3);
		cout<<n<<" "<<m<<"\n";
		//ai
		for(LL i=1;i<=n;i++){
			LL x = ran(9e9,1e10);
			cout<<x<<" ";				
		}
		cout<<"\n";
	}
	
	return 0;
}
