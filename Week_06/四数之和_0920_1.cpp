class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector< vector<int> > numsOb;
		if(nums.size() < 4) {
			return numsOb;
		}
		sort(nums.begin(), nums.end());
		//cout << "size = " << nums.size() << ",target = " << target << endl;
		
		const int size = nums.size();
		vector< int > numsTmp;
		for(int i = 0; i < size; i++) {
			for(int j = i+1; j < size; j++) {
				for(int k = j+1; k < size; k++) {
					for(int l = k+1; l < size; l++) {
						if(nums[i] + nums[j] + nums[k] + nums[l] == target) {
							//cout << i << "," << j << "," << k << "," << l << endl;
							numsTmp.push_back(nums[i]);
							numsTmp.push_back(nums[j]);
							numsTmp.push_back(nums[k]);
							numsTmp.push_back(nums[l]);
							sort(numsTmp.begin(),numsTmp.end());
							if(!isExist(numsTmp, numsOb)) {								
								numsOb.push_back(numsTmp);
							}
						}
						numsTmp.clear();
					}
				}
			}
		}

		return numsOb;
    }
private:
	bool isExist(vector<int> nums1, vector< vector<int> > numss){
		bool ret = false;
		//cout << "INININ size = " << numss.size() << endl << endl;
		if(numss.size() == 0) {
			return false;
		}
		for(int i = 0; i<numss.size(); i++) {
			vector<int> nums = numss[i];
			if(nums.size() != nums1.size()) {
				continue;
			}
			int j = 0;
			for(j = 0; j<nums.size(); j++) {
				if(nums[j] != nums1[j]){
					break;
				}
			}
			if(j == nums.size()) {
				return true;
			}
		}	
		//cout << "ret = " << (ret ? "true" : "false") << endl;
		return ret;
	}
};