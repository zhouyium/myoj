//4528: 杨辉三角形
//http://47.110.135.197/problem.php?id=4528

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
	LL f[101][101]={};
	f[1][1]=1;
	for(LL i=2;i<=100;i++){
		for(LL j=1;j<=i;j++){
			if(j==1||i==j){
				f[i][j]=1;
			}
			f[i][j]=f[i-1][j]+f[i-1][j-1];
		}
	}
	
	int n=20;
	for(int i=1;i<=100;i++){
		char in[16];
		sprintf(in, "%02d.in", i);
		freopen(in, "w", stdout);
		cout<<i<<"\n";
		fclose(stdout);
		
		sprintf(in, "%02d.out", i);
		freopen(in, "w", stdout);
		for(LL j=1;j<=i;j++){
			for(LL k=1;k<=j;k++){
				cout<<f[j][k]<<" ";
			}
			cout<<"\n";
		}
		fclose(stdin);
	}

	
	return 0;
}
