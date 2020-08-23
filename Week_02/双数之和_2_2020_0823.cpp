class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> numsVec;

		//保存数组数值与下标
		//题目说明了每种输入只会有一个答案，这个就排除了key-value中key重复的问题
		//key为数组值，value对应了数组下标
		map<int, int> mapNums;	
		for(int i = 0; i < nums.size(); i++) {
			mapNums.insert(make_pair(nums[i], i));
		}

		//cout << "mapNums.size = " << mapNums.size() << endl;

		for(int i = 0; i < nums.size(); i++) {
			///找数组某个值是否对应其他位置有相同的值和为target
			int element =  target - nums[i];
			map<int, int>::iterator iter;
			iter = mapNums.find(element);
			if(iter != mapNums.end() && mapNums[element] != i) {				
				//目标找到且非自身
				numsVec.push_back(i);
				numsVec.push_back(mapNums[element]);
				return numsVec;
			}
		}
		return numsVec;
    }
};
