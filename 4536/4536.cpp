#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main()//这些就不讲了。
{
	freopen("6.in", "r", stdin);
	long long n,i,j,t=1,ans=0;//n是10^6，a数组是10^9所以用long long。
	cin>>n;//输入n。
	for(i=0;i<n;i++)
	{
		cin>>a[i];//输入a数组。
	}
	for(j=0;j<n;j++)
	{
			if(a[j+1]>a[j])
			{
				t++;//如果比前一个大，t++。
				if(t>ans)
				ans=t;//把最大的连续上升天数放在ans里。
			}
			else
			t=1;//否则t又变成1。
	}
	cout<<ans<<"\n";//输出答案ans。
	return 0;//好习惯。
}
