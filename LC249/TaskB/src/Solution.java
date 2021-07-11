import java.util.HashMap;
import java.util.Map;

class Solution {
    public int countPalindromicSubsequence(String s) {
        int ans=0;
        int n=s.length();
        Map<String,Boolean> mp = new HashMap<String,Boolean>();
        Boolean[][] pre = new Boolean[n][26];
        Boolean[][] suf = new Boolean[n][26];
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                pre[i][j]=false;
                suf[i][j]=false;
            }
        }
        pre[0][s.charAt(0)-'a']=true;
        for(int i=1;i<n;i++){
            for(int j=0;j<26;j++){
                pre[i][j]|=pre[i-1][j];
            }
            pre[i][s.charAt(i)-'a']=true;
        }
        suf[n-1][s.charAt(n-1)-'a']=true;
        for(int i=n-2;i>=0;--i){
            for(int j=0;j<26;j++){
                suf[i][j]|=suf[i+1][j];
            }
            suf[i][s.charAt(i)-'a']=true;
        }
        for(int i=1;i<n-1;i++){
            for(int j=0;j<26;j++){
                char c = (char)('a'+j);
                if(pre[i-1][c-'a']==false||suf[i+1][c-'a']==false){
                    continue;
                }
                StringBuilder tmp=new StringBuilder();
                tmp.append(c).append(s.charAt(i)).append(c);
                if(mp.containsKey(tmp.toString())){
                    continue;
                }
                else{
                    mp.put(tmp.toString(),true);
                    ans++;
                }
            }
        }
        return ans;
    }
}
