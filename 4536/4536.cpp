#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main()//��Щ�Ͳ����ˡ�
{
	freopen("6.in", "r", stdin);
	long long n,i,j,t=1,ans=0;//n��10^6��a������10^9������long long��
	cin>>n;//����n��
	for(i=0;i<n;i++)
	{
		cin>>a[i];//����a���顣
	}
	for(j=0;j<n;j++)
	{
			if(a[j+1]>a[j])
			{
				t++;//�����ǰһ����t++��
				if(t>ans)
				ans=t;//����������������������ans�
			}
			else
			t=1;//����t�ֱ��1��
	}
	cout<<ans<<"\n";//�����ans��
	return 0;//��ϰ�ߡ�
}
