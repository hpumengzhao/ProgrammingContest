#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int ,int> pii;
const int INF = 0x3f3f3f3f;
const int N = 5e6+10;
const int M = 5e6+10;
  
struct EDGE{
    int next;
    int to;
    int w;
}edge[M];
  
int n,m,k,s,e,cnt = 1;
int head[N],dis[N];
bool inq[N];
  
void add(int u, int v, int w){
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].w  = w;
    head[u] = cnt++;
}
  
struct NODE{
    int id,dist;
}q,p;
bool operator < (NODE a, NODE b){
    return a.dist > b.dist;
}
void Dijkstra(){
    memset(dis, INF, sizeof dis);
    memset(inq, 0, sizeof inq);
    priority_queue<NODE> que;
    p.id = s; p.dist = 0;
    dis[s] = 0; que.push(p);
    while(!que.empty()){
        q = que.top(); que.pop();
        if(inq[q.id])   continue;
        inq[q.id] = true;
        for(int i=head[q.id]; ~i; i=edge[i].next){
            int u = edge[i].to;
            if(dis[u] > q.dist + edge[i].w){
                dis[u] = q.dist + edge[i].w;
                p.id = u;
                p.dist = dis[u];
                que.push(p);
            }
        }
    }
    int ans = INF;
    for(int i=0; i<=k; ++i)  ans = min(ans, dis[e + i*n]);
    printf("%d\n", ans);
}
int main(int argc, char const *argv[])
{
    int u, v, w;
    memset(head, -1, sizeof head);
    scanf("%d %d %d %d %d",&n, &m, &s, &e, &k);
    for(int i=1;i<=m;++i){
        scanf("%d %d %d",&u, &v, &w);
        for(int j=0; j<=k; ++j){
            add(u + j*n, v + j*n, w);
            add(v + j*n, u + j*n, w);
            if(j != k){
                add(u + j*n, v + (j+1)*n, 0);
                add(v + j*n, u + (j+1)*n, 0);
            }
        }
    }
    Dijkstra();
    return 0;
}
