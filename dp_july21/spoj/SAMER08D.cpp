// Problem Link -https://www.spoj.com/problems/SAMER08D/
/*By Manjot Kaur*/
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1005
int dp[N][N];


int main(void) {
    int k,m,n;
    char s[N], t[N];
    while(true){
      
        scanf("%d",&k);
        if(k==0) break;  
        scanf("%s%s",s,t);
        m = strlen(s);
        n = strlen(t);
        for(int i=0; i<=m; i++) dp[i][0] = 0;
        for(int j=0; j<=n; j++) dp[0][j] = 0;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(s[i-1]==t[j-1]){
                    int c=1;
                    while(i-c-1>=0 and j-c-1>=0 and s[i-c-1]==t[j-c-1]){
                        c++;
                        if(c>=k){
                            dp[i][j] = max(dp[i][j],c+dp[i-c][j-c]);
                        }
                    }
                }
            }
        } 
        printf("%d\n", dp[m][n]);
    }
	
	return 0;
}
