class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j==n-1){
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                }
                else{
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
                }
            }
        }
        int min_=INT_MAX;
        for(int i=0;i<n;i++){
            min_=min(min_,dp[n-1][i]);
        }
        return min_;
    }
};