//思想：
/// 使用归纳法，可知第三步的操作为前两步之和。
/// 
/// 
//时间复杂度：

class Solution {
	int steps;
public:
    int climbStairs(int n) {
		int *dp = new int[n+1] ;
		//cout << "n = " << n << endl;

		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
		}

		steps = dp[n];

		if(NULL != dp) {
			delete [] dp;
		}		
		return steps;
    }
};