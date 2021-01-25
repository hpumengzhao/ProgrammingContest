#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int V[100001];
priority_queue< pair<int,int> > q;
int C[100001];
int main()
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>C[i];
	}
	for(int i=1;i<=n;i++)
	{
		q.push(make_pair(-C[i],i+d));
		while(!q.empty())
		{
			if(q.top().second>i)
			{
				V[i]=q.top().first;
				V[i]*=-1; 
				break;
			}
			else
				q.pop(); 
		}	
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=V[i];
	}
	cout<<ans<<endl;
	return 0;
}
