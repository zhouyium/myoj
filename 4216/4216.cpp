#include <stdio.h>
#define N 1010
struct schedule
{
	int begin;     //��ʼʱ�� 
	int end;       //����ʱ�� 
}meet[N],t;

int main()
{
	int i,j,n,ans=1,record;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d%d",&meet[i].begin,&meet[i].end);
	
	for(i=0;i<n-1;i++)
	{ 
		for(j=i+1;j<n;j++)
		{ 
		    if(meet[i].end > meet[j].end)
		    {
		      	t=meet[i];
		      	meet[i]=meet[j];
		      	meet[j]=t;
		    }
		}
	}
	
	record=meet[0].end;              //��һ������ʱ�� 
	for(i=1;i<n;i++)
	{
		if(meet[i].begin >= record)  //��ʼʱ�䲻��ͻ 
		{
			ans++;
			record=meet[i].end;      //���½���ʱ��
		}
	}
	printf("%d\n",ans);
	return 0;
}
