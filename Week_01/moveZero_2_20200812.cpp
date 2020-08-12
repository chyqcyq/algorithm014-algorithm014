//思想：
/// 借助两个index，前指找到非零，并将非零值拷贝到后指指向的数组前端位置；
/// 最后将后指到末尾的值清零即可
//时间复杂度：
//空间复杂度:

class Solution {
public:
    void moveZeroes(vector<int>& nums) {			
		int ZeroCnt = 0;
		for (int i = 0; i < nums.size(); i++) {
			if(nums[i] != 0) {
				nums[ZeroCnt++] = nums[i];
			}
		}

		for (int i = ZeroCnt; i < nums.size(); i++) {
			nums[i] = 0;
		}
	}
};  