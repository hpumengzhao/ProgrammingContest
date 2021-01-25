#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 2010;
 
int n, m, ans;
char mat[MAX_N][MAX_N],reg[MAX_N][MAX_N];
int height[MAX_N][MAX_N], sta[MAX_N], L[MAX_N],R[MAX_N];
 
//height[i][j]:第i行第j列元素往上最长的连续1长度
//维护单调非递减栈
int solve(int row)
{
    int ans=0;
    int top = 0, cur;
    height[row][m + 1] = 0;
    for (int j = 1; j <= m + 1; ++j) {
        while (1) {
            cur = sta[top];
            if (height[row][cur] <= height[row][j]) break;
            R[cur] = j;
            --top;
        }
        L[j] = cur;
        sta[++top] = j;
    }
    for (int j = 1; j <= m; ++j) {
        if(mat[row][j] == '0') continue;
        int len = R[j] - L[j] - 1;
        ans = max(ans, height[row][j] * len);
    //  printf("height[%d][%d] = %d len = %d\n", row, j, height[row][j], len);
    }
    return ans;
}
int solve2(int row)
{
    int ans=0;
    int top = 0, cur;
    height[row][n + 1] = 0;
    for (int j = 1; j <= n + 1; ++j) {
        while (1) {
            cur = sta[top];
            if (height[row][cur] <= height[row][j]) break;
            R[cur] = j;
            --top;
        }
        L[j] = cur;
        sta[++top] = j;
    }
    for (int j = 1; j <= n; ++j) {
        if(reg[row][j] == '0') continue;
        int len = R[j] - L[j] - 1;
        ans = max(ans, height[row][j] * len);
    //  printf("height[%d][%d] = %d len = %d\n", row, j, height[row][j], len);
    }
    return ans;
}
 
 
int main()
{       scanf("%d %d",&n,&m);
        vector<int> GG,KK;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin>>mat[i][j];
                reg[j][i]=mat[i][j];
            }
        }
        memset (height, 0, sizeof(height));
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (mat[i][j] == '1') {
                    height[i][j] = 1;
                    while (mat[++i][j] == '1') {
                        height[i][j] = height[i - 1][j] + 1;
                    }
                    --i;
                }
            }
        }
        ans = 0;
        for (int i = 1; i <= n; ++i) { ans=solve(i); GG.push_back(ans);}
        sort(GG.begin(),GG.end(),greater<int>());
        memset (height, 0, sizeof(height));
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= m; ++i) {
                if (reg[i][j] == '1') {
                    height[i][j] = 1;
                    while (reg[++i][j] == '1') {
                        height[i][j] = height[i - 1][j] + 1;
                    }
                    --i;
                }
            }
        }
        ans = 0;
        for (int i = 1; i <= m; ++i) { ans=solve2(i); KK.push_back(ans);}
        sort(KK.begin(), KK.end(),greater<int>());
        printf("%d\n", max(GG[1],KK[1]));
    return 0;
}
