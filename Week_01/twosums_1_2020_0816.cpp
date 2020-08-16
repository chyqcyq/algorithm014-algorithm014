//思想：
/// 暴力破解，没有思想
/// 
//时间复杂度：
//空间复杂度：

class Solution {
	int steps;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> resultNums;

		for (int i = 0; i < nums.size(); i++) {			
			for(int j = i+1; j < nums.size(); j++) {
				if(nums[i] + nums[j] == target) {
					resultNums.push_back(i);
					resultNums.push_back(j);
					return resultNums;
				}
			}
		}
		return resultNums;
    }
};