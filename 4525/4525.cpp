#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;

struct REN {
	LL year;
	LL month;
	LL day;
} a;

//判断x是否是闰年 
bool check(LL x) {
	if ((x%400==0)||(x%4==0&&x%100!=0)) {
		return 1;
	}
	return 0;
}

//打表，每月有几天 
LL days[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 

int main() {	
	cin>>a.year>>a.month>>a.day;
	
	LL ans=0; 
	//按平年计算有几天
	for (LL i=1; i<a.month; i++) {
		ans+=days[i];
	}
	//本月的天数
	ans+=a.day; 
	
	//闰年超过2月，补上一天 
	if (check(a.year)==true && a.month>2) {
		ans++;
	}
	
	cout<<ans<<"\n";
		
	return 0;
}

