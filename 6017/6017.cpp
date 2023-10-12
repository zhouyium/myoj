#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e2+10;
LL stk[N],top=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++){
		LL x;
		cin>>x;
		while(stk[top]>x && top+1>1){
			top--;
		}
		stk[++top]=x;
		for (LL i=1; i<=top; i++){
			cout<<stk[i]<<' ';
		}
		cout<<"\n";
	}
	return 0;
}
