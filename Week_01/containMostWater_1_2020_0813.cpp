//思想：
/// 暴力穷举，没有思想；结果是49/50条超出时间限制；
/// 待后续学习新思想再改进
//时间复杂度：
//空间复杂度:
class Solution {
public:
    int maxArea(vector<int>& height) {
     
		int maxVal = 0;
		for(uint i = 0; i < height.size(); i++) {
			for(uint j = i+1; j < height.size(); j++) {
				//cout << "min(" << height[i] << "," << height[j] << ")=" << min(height[i], height[j]) << endl;
				//cout << "(" << j << "-" << i << ")=" << j-i << endl;				
				int areaSize = min(height[i], height[j]) * (j-i);
				//cout << "aeraSize"  << "=" << areaSize << endl;
				//cout << "before maxVal"  << "=" << maxVal << endl;
				if(maxVal < areaSize) {
					maxVal = areaSize;
				}
				//cout << "after maxVal"  << "=" << maxVal << endl;
				//cout << "**********************************" << endl;
			}
		}
		return maxVal;
    }
};  