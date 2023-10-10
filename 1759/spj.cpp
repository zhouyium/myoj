//1759: Sherlock and his girlfriend
//http://47.110.135.197/problem.php?id=1759
#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1e5+10;
LL n,k,stdk,usr[N];
bool not_prime[N],f;

void sai() {
	//1e5
	not_prime[0]=not_prime[1]=true;
	for (LL i=2; i*i<=1e5; i++) {
		if (false==not_prime[i]) {
			for (LL j=i*i; j<=1e5; j+=i) {
				not_prime[j]=true;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	sai();
	//测试输入
    FILE * f_in=fopen(argv[1],"r"); 
    //测试输出
    FILE * f_out=fopen(argv[2],"r");
    //用户输出
    FILE * f_user=fopen(argv[3],"r");
    int ret=0;//AC=0, WA=1
    
    fscanf(f_in, "%lld", &n);
    fscanf(f_out, "%lld", &stdk);
    fscanf(f_user, "%lld", &k);
	if (k!=stdk)
	{
		return 1;
	}
	else
	{
		for (LL i=2;i<=n+1;i++) {
			fscanf(f_user, "%lld", &usr[i]);
		}
		for (LL i=2;i<=n+1&&!f;i++)
		{
			if (not_prime[i]) continue;
			for (int j=(i<<1);j<=n+1&&!f;j+=i)
			{
				not_prime[j]=true;
				if (usr[i]==usr[j]) f=true;
			}
		}
		if (f) return 2;
		else return 0;
	}
	return 0;
}
