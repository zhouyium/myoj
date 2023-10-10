//6584: You can Solve a Geometry Problem too
//http://47.110.135.197/problem.php?id=6584

#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1e5+10;
struct POINT {
	double x;
	double y;
} a[N], b[N];
 
double direct(const POINT &i,const POINT &j,const POINT &k)     //计算叉积
{
	return (k.x-i.x)*(j.y-i.y)-(j.x-i.x)*(k.y-i.y);
}
 
int onsegment(const POINT &a,const POINT &b,const POINT &c)   //共线时，判断点是否落在线段上   
{
	double minx=min(a.x,b.x);
	double maxx=max(a.x,b.x);
	double miny=min(a.y,b.y);
	double maxy=max(a.y,b.y);
	return c.x>=minx&&c.x<=maxx&&c.y>=miny&&c.y<=maxy;
}
bool check(const POINT &p1,const POINT &q1,const POINT &p2,const POINT &q2) {
	double d1=direct(p2,q2,p1);        
	double d2=direct(p2,q2,q1);
	double d3=direct(p1,q1,p2);
	double d4=direct(p1,q1,q2);
	if(d1*d2<0&&d3*d4<0)
		return true;
	else if(d1==0&&onsegment(p2,q2,p1))
		return true;
	else if(d2==0&&onsegment(p2,q2,q1))
		return true;
	else if(d3==0&&onsegment(p1,q1,p2))
		return true;
	else if(d4==0&&onsegment(p1,q1,q2))
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL n;
	while (cin>>n) {
		if (n==0) {
			break;
		}
		
		for (LL i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>b[i].x>>b[i].y;
		}
		
		LL res=0;
		for (LL i=1; i<=n; i++) {
			for (LL j=i+1; j<=n; j++) {
				if (check(a[i],b[i],a[j],b[j])) {
					res++;
				}
			}
		}
		cout<<res<<"\n";
	}

	return 0;
}
