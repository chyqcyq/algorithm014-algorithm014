///方法一：暴力无脑
///处理好入参后，直接循环乘
/// 时间复杂度O(n)；结果就是时间超限

class Solution {
public:
    double myPow(double x, int n) {
		double result = 1.0;

		x = (n > 0) ? (x) : (double)(1/x);
		n = (n>0) ? n : (n*-1);

		for(int i = 0; i < n; i++) {
			result *= x;
		}

		return result;
    }
};

///方法二 递归法
///利用快速幂的特性，x^n次方可分解为x^(n/2)的平方。以此类推可以分解成x^0次的平方，这个值是确定的，可作为终极条件
///所以适用于递归方法；而后就是递归中的一些常见处理了。

class Solution {
public:
	double reurisonMul(long long n, double val) {
		/// 终极条件
		if(n == 0) {
			return 1.0;
		}
		///本层逻辑处理
		
		///向下递归
		double tmpVal = reurisonMul(n/2, val);
		///状态清扫
		tmpVal = (n%2 == 0) ? (tmpVal*tmpVal) : (tmpVal*tmpVal*val);
		return tmpVal;
	}

    double myPow(double x, int n) {
		double result = 1.0;
        long long tmpN = n;

		x = (n > 0) ? (x) : (double)(1/x);
		tmpN = (tmpN>0) ? tmpN : (tmpN*-1);
		
		result = reurisonMul(tmpN, x);
		
		return result;
    }
};

///方法二 迭代法
