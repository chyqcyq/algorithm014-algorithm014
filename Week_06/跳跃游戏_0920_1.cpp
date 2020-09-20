class Solution {
public:
    int jump(vector<int>& nums) {
		int end = 0; //每次跳跃的边界
		int maxP = 0; //跳跃的最远位置
		int steps = 0; //步数
		for(int i = 0; i < nums.size()-1; i++) {
			//每一步都选能跳最远的,边界就是能跳最远的
			//cout << "end = " << end << ",maxP = " << maxP << ",nums[" << i << "] = " << nums[i] << endl;
			maxP = max(maxP, nums[i]+i);			
			if(i == end) {
				end = maxP;
				++steps;
			}
		}
		return steps;
    }
};