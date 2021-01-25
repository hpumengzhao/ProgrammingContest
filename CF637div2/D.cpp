#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std;
int pre[2007][20007] ;
int n,c;
string s[2007];
string digit[17]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};
vector<int>ans;
int solve(int i,int k){//cost  change i to k
	int al=0;
	for(int j=0;j<7;++j){
        if(digit[k][j]<s[i][j])
            return -1;
        else{
            int temp=digit[k][j]-s[i][j];
            al+=temp;
        }
	}
	return al;
}
int main()
{
	cin>>n>>c;
	for(int i=1;i<=n;++i)
        cin>>s[i];
    pre[1+n][0]=1;//到i点亮了j个
    int last=0;
    int f=0;
    int vis=0;
	for(int i=n;i;--i){
		for(int j=last;j>=0;--j)
		{
			if(!pre[i+1][j])
                continue;
			for(int k=0;k<10;++k)
			{
		  	 	int temp=solve(i,k);
		  	 	if(temp>=0)
                    pre[i][j+temp]|=pre[i+1][j];
		  	 	last=max(j+temp,last);
		  	}
		}
    }
	for(int i=1;i<=n;++i)
	{
		vis=0;
		for(int j=9;j>=0;--j)
		{
			int temp=solve(i,j);
			if(temp>=0&&temp<=c)
			{	
                if(pre[i+1][c-temp])
				{
                    vis=1;
                    ans.emplace_back(j);
                    c-=temp;
                    break;
                }
			}
		}
		if(vis==0)
            f=1;
	}
	if(f==0)
		for(auto temp:ans)
            cout<<temp;
	else
        cout<<-1;
	return 0;
}
