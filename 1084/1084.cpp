#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1e1+10; 


//����ֵ ������(�������) ������
//prime 
//17 2 3 4 5 6 ... 16
//23 sqrt(23) 2,3,4
//1,000,000,009
bool prime(LL x) {
	for (LL i=2; i<x; i++) {
		if (x%i==0) {
			return false;
		}
	}
	return true;
}

int main() {
	cout<<prime(1e9+7)<<"\n";
	LL n;
	cin>>n;
	
	//ͳ��2~n���м�������
	LL cnt=0;
	for (LL i=2; i<=n; i++) {
		if (prime(i)==true) {
			cnt++;
		}
	}
	cout<<cnt<<"\n"; 

	return 0;
}
 
