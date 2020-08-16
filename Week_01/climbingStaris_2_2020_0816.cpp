//思想：
/// 中间变量不关注，因此优化中间变量过程
/// 
/// 
//时间复杂度：
//空间复杂度：

class Solution {
public:
    int climbStairs(int n) {
		//cout << "n = " << n << endl;
		if((0 == n) || (1 == n)) {
			return 1;
		}

		int step0 = 1;
		int step1 = 1;
        int steps = step0+step1;
		for (int i = 2; i <= n; i++) {
			steps = step0 + step1;
			step0 = step1;
			step1 = steps;
		}		
		return steps;
    }
};