#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+100;
ll vis[N];
struct node{
	ll start,pos;
};
char s[N];
ll a[N];
ll n;
ll cal(ll x){
	return (x*x+1)%n;
}
ll bfs(){
	for(ll i=0;i<n;i++) vis[i]=0;
	queue<node>que,mid;
	queue<ll>flag;
	ll cur=0,num=0;
	for(ll i=0;i<n;i++) cur=max(cur,a[i]);
	for(ll i=0;i<n;i++) if(a[i]==cur) {
		que.push({i,i});
		num++;
	}
	if(num==1) return que.front().start;
	ll times=0;
	while(!que.empty()){
		if(num!=que.size()) num=que.size(),times=0;
		else if(times>=100000) break;
		else times++;
		
		cur=0;
		while(!que.empty()){
			node x=que.front();
			mid.push(x);
			que.pop();
			cur=max(cur,a[cal(x.pos)]);
		}
		while(!mid.empty()){
			if(mid.size()+que.size()==1){
				if(mid.size()==1) return mid.front().start;
				else return que.front().start;
			}
			node x=mid.front();
			mid.pop();
			if(a[cal(x.pos)]==cur && !vis[cal(x.pos)]){
				flag.push(cal(x.pos));
				vis[cal(x.pos)]=1;
				x.pos=cal(x.pos);
				que.push(x);
			}
		}
		while(!flag.empty()){
			vis[flag.front()]=0;
			flag.pop();
		}
	}
	return que.front().start;
}
int main(){
	ll T;
	scanf("%lld",&T);
	for(ll t=1;t<=T;t++){
		scanf("%lld",&n);
		scanf("%s",s);
		for(ll i=0;i<n;i++) a[i]=s[i]-'0';
		printf("Case #%d: ",t);
		
		ll ans=bfs();
		for(ll i=0;i<n;i++){
			printf("%c",s[ans]);
			ans=cal(ans);
		}
		printf("\n");
	}
	return 0;
}
