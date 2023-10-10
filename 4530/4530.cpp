#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+10;
const int MAXM=1e3+10;
int a[MAXN][MAXM];
int main(){
	int n;
	cin>>n;
	int cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=cnt;
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<setw(3)<<a[i][j];
		}
		cout<<"\n";
	}
	return 0;
}
