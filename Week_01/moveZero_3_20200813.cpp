//思想：
/// 借助两个index，前指找到非零，并将非零值拷贝到后指指向的数组前端位置；
/// 直接交换
//时间复杂度：
//空间复杂度:

class Solution {
public:
    void moveZeroes(vector<int>& nums) {					
		int tmpVal;
		for (int pre = 0, i = 0; i < nums.size(); i++) {
			if(nums[i] != 0) {
				//tmpVal = nums[pre];
				//nums[pre++] = nums[i];
				//nums[i] = tmpVal;
				swap(nums[pre++], nums[i]);
			}
		}
	}
}; 