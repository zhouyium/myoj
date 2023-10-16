//4155: 吃糖果
//http://47.110.135.197/problem.php?id=4155

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=2e6+10;

string s="0123456789. -$!_-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

LL ran(LL l=1,LL r=1e3) {
	if (l>r) {
		swap(l,r);
	}
	return rand()%(r-l+1)+l;
}

int main(int argc, char *argv[]) {
	LL f[21]={};
	f[1]=1;
	f[2]=2;
	for(LL i=3;i<=20;i++){
		f[i]=f[i-1]+f[i-2];
	}

	int n=20;
	for(int i=1;i<n;i++){
		char in[16];
		sprintf(in, "%02d.in", i);
		freopen(in, "w", stdout);
		cout<<i<<"\n";
		fclose(stdout);

		sprintf(in, "%02d.out", i);
		freopen(in, "w", stdout);
		cout<<f[i]<<"\n";
		fclose(stdin);
	}

	return 0;
}
