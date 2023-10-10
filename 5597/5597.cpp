//5597: 网格（grid）
//http://47.110.135.197/problem.php?id=5597
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;
const LL MO=1e9+7;

//calc square
LL square(LL a, LL b) {
	//a*b
	if (a==1||b==1) {
		return ((a%MO)*(b%MO))%MO;
	}
	return (((a%MO)*(b%MO))%MO+square(a-1,b-1))%MO;
}

//calc rectangle
LL rectangle(LL row,LL col) {
	return (((row*(row+1)/2)%MO)*((col*(col+1)/2)%MO))%MO;
}

//calc rectangle
LL rectangle1(LL a) {
	if (a==1) {
		return 1;
	}
	return ((a%MO)+rectangle1(a-1))%MO;
}


int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n,m;
	cin>>n>>m;
	
	LL tot1=square(n,m);//正方形 
	LL tot2=rectangle1(n)*rectangle1(m);//(n,m);
	cout<<tot1<<" "<<(tot2-tot1)%MO<<"\n";

	return 0;
}

