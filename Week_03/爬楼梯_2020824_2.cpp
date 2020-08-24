
///常规傻递归法；超出时间限制
///此处在思考第3级台阶时，要把这种重复抽象出来，还是略微有些困难
///在3级台阶时，此时要么是处于1，要么是处于2，所以上来走法就两种，处于1，说明剩余2级台阶，套用f(2)；处于2，说明剩余1级台阶，则套用f(1)，即f(3) = f(2) + f(1)；
///在4级台阶时，处于 2 || 3级（因为一次只能上1或者2）；则对应f(4) = f(3) + f(2)
///根据数据归纳法，处于n阶时，f(n) = f(n-1) + f(n-2);
class Solution {
public:
	Solution():steps(0){}
    int climbStairs(int n) {
		//结束条件
		if(n <= 2) {
			//cout << "end n = " << n << endl;
			return n;
		}		
		//处理步骤
		//cout << "before n = " << n << " steps = " << steps << endl;
		steps = climbStairs(n-1) + climbStairs(n-2);
		//cout << "after  n = " << n << " steps = " << steps << endl;
		//返回处理
		return steps;
    }
private:
	int steps;
};

