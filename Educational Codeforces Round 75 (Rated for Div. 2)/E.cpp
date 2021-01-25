#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+100;
pair<int,int> a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].first>>a[i].second;
        }
        sort(a+1,a+n+1);
        long long ans=0;
        int cnt=0;//[i+1,n]已经收买了cnt人
        priority_queue<int> q;
        for(int i=n;i>=1;i--){//选出必须买的
            q.push(-a[i].second);
            int have=i-1;//假设前i-1全买了
            while(have+cnt<a[i].first){
                ans-=q.top();
                q.pop();
                cnt++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
