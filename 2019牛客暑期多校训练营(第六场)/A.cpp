#include<bits/stdc++.h>
 
using namespace std;
char s[3000];
int main(){
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--){
        char t[30];
        int kind[26];
        scanf("%s%s",s,t);int l=strlen(s);
        for(int i=0;i<26;i++){
            if(t[i]=='d') kind[i]=1;
            if(t[i]=='w') kind[i]=2;
            if(t[i]=='h') kind[i]=3;
            //cout<<i<<' '<<kind[i]<<endl;
        }
        int h,d,w;h=d=w=0;
        for(int i=0;i<l;i++){
            //cout<<s[i]-'a'<<' '<<kind[s[i]-'a']<<endl;
            if(kind[s[i]-'a']==1) d++;
            if(kind[s[i]-'a']==2) w++;
            if(kind[s[i]-'a']==3) h++;
        }
        if(h*4>=l){
            printf("Case #%d: Harmful\n",cas++);continue;
        }
        if(h*10<=l){
            printf("Case #%d: Recyclable\n",cas++);continue;
        }
        if(d>=2*w){
            printf("Case #%d: Dry\n",cas++);continue;
        }
        printf("Case #%d: Wet\n",cas++);
    }
    return 0;
}
