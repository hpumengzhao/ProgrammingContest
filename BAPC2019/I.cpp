///#include<bits/stdc++.h>
///#include<unordered_map>
///#include<unordered_set>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<bitset>
#include<set>
#include<stack>
#include<map>
#include<list>
#include<new>
#include<vector>
#define MT(a,b) memset(a,b,sizeof(a));
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double pai=acos(-1.0);
const double E=2.718281828459;
 
int n,m;
int maxn;   ///最大团的点数
int dp[105];    ///dp[i]表示从i到n中的最大团的节点数。
int maps[105][105];  ///邻接矩阵
int que[105][105];
vector<int>ans,q;   ///ans答案   q临时答案
int dfs(int up,int step)    ///up表示集合点的数量，step第几层DFS
{
    if(up==0)
    {
        if(step>maxn)       ///剪枝3
        {
            maxn=step;
            ans=q;
            return 1;
        }
        return 0;
    }
    for(int i=1;i<=up;i++)
    {
        int s=que[step][i];
        if(step+n-s+1<=maxn||step+dp[s]<=maxn)///剪枝1和2
            return 0;
        int cnt=0;
        for(int j=i+1;j<=up;j++)///找结点比
        {
            if(maps[s][que[step][j]])
                que[step+1][++cnt]=que[step][j];
        }
        q.push_back(s);
        if(dfs(cnt,step+1))
            return 1;
        q.pop_back();
    }
    return 0;
}
 
int main()
{
    int t;
    int s,e;
        maxn=0;
        fill(maps[0],maps[0]+sizeof(maps)/sizeof(int),1);
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d",&s,&e);
            maps[e][s]=maps[s][e]=0;///建立补图
        }
        for(int i=n;i>=1;i--)
        {
            q.clear();
            q.push_back(i);
            int up=0;
            for(int j=i+1;j<=n;j++)
                if(maps[i][j])
                    que[1][++up]=j;
            dfs(up,1);
            dp[i]=maxn;
        }
        printf("%d\n",maxn);
    return 0;
}