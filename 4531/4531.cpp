#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1e1+10; 
LL a[N][N];

//����Ϊ3

int main() {
	LL n;
	cin>>n;
	//����ѭ�� 
	//i ��
	//j �� 
	LL cnt=1;
	for (LL j=1; j<=n; j++) {//�� 
		for (LL i=1; i<=n; i++) {//�� 
			a[i][j]=cnt;
			cnt++;
		}
	}
	
	//�����Զ�����к��� 
	//set ����
	//width  ��� 
	for (LL i=1; i<=n; i++) {//��
		for (LL j=1; j<=n; j++) {//�� 
			cout<<setw(3)<<a[i][j];
		} 
		cout<<"\n";
	}
	return 0;
}
 
