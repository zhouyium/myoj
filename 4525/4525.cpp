#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;

struct REN {
	LL year;
	LL month;
	LL day;
} a;

//�ж�x�Ƿ������� 
bool check(LL x) {
	if ((x%400==0)||(x%4==0&&x%100!=0)) {
		return 1;
	}
	return 0;
}

//���ÿ���м��� 
LL days[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 

int main() {	
	cin>>a.year>>a.month>>a.day;
	
	LL ans=0; 
	//��ƽ������м���
	for (LL i=1; i<a.month; i++) {
		ans+=days[i];
	}
	//���µ�����
	ans+=a.day; 
	
	//���곬��2�£�����һ�� 
	if (check(a.year)==true && a.month>2) {
		ans++;
	}
	
	cout<<ans<<"\n";
		
	return 0;
}

