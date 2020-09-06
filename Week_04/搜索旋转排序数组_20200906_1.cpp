//有了二分查找的模板，看起来解题思路不困难
//但是在实际解题中，一些细节和边界导致用例不通过。
//以下的解法，实际上是先找到完全有序的左半边或者右半边，然后在有序的半边套用二分查找套路进行查找
//实际上耗时还是有些冗余，可以进一步优化
//时间复杂度：O(log n) 因为是二分查找，每次都能排除一半
//空间复杂度：O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
		int index = -1;		
		int left = 0;
		int right = nums.size()-1;
		while(left <= right) {
			int mid = left+((right-left)/2);
			cout << " left = " << left;
			cout << " right = " << right;
			cout << " mid = " << mid << endl;
			if(target == nums[mid]) {
				index = mid;
				return index;	
			}
			if(nums[left] <= nums[mid]) {
				//左半边有序
				if((target >= nums[left]) && (target < nums[mid]) ) {
					//target在有序序列左半部分
					right = mid - 1; 					
				}
				else {
					left = mid + 1;
				}				
			}
			else {
				//右半边有序
				if((target > nums[mid]) && (target <= nums[right]) ) {
					//target在有序的右半边内
					left = mid + 1; 					
				}
				else {
					right = mid - 1;
				}				
			}
		}
		return index;
    }
};