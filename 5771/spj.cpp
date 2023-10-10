#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_prime(int x) {
	if (x<=1) {
		return false;
	}
	for (int i=2; i*i<=x; i++) {
		if (x%i==0) {
			return false;
		}
	}
	return true;
} 

int main(int argc, char *args[]) {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	FILE *f_in=fopen(args[1], "r");//测试输入
	FILE *f_out=fopen(args[2], "r");//测试输出
	FILE *f_user=fopen(args[3], "r");//用户输出
	int ret=0;//AC
	int n,a,b;
	fscanf(f_in, "%d", &n);
	fscanf(f_user, "%d %d", &a, &b);
	if (a+b!=n||is_prime(a)||is_prime(b)) {
		ret=1;
	}
	fclose(f_in);
	fclose(f_out);
	fclose(f_user);
	return ret;
}

