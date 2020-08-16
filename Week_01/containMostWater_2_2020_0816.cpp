//思想：
/// 对数组进行夹逼方式获取，升维数降低时间复杂度
/// 此处有个编译问题，方法一在VS2012得到的结果是42，力扣的结果是49。应该是++和--操作的编译器不同导致。
/// 所以应该避免使用这种过于简洁的写法。
//时间复杂度：
//空间复杂度:

class Solution {
	int maxVal;
public:
    int maxArea(vector<int>& height) {
     
//		cout << "height.size() = " << height.size() << endl;		
		for(uint i = 0, j = height.size()-1; i < j; ) {
			//cout << "height[" << i << "]=" << height[i] << " height[" << j << "]=" << height[j] << endl;
/*方法一 力扣与VS2012最终结果不同*/
			int areaSize = (height[i]>height[j]) ? ((j-i)*height[j--]) : ((j-i)*height[i++]);
/*方法二一致*/			
#if 0
			 int minheight = (height[i]<height[j]) ? (height[i++]) : (height[j--]);
			 int areaSize = (j-i+1) * minheight;
#endif
/*方法三一致*/
#if 0
			int areaSize = 0;
			if(height[i]>height[j]) {
				areaSize = (j-i)*height[j];
				--j;
			}
			else {
				areaSize = (j-i)*height[i];
				++i;
			}			
#endif
			 maxVal = max(maxVal, areaSize);
			//cout << "maxVal=" << maxVal << " areaSize=" << areaSize << endl <<"*********************"<<endl;
			//cout << "i=" << i << " j=" << j << endl;
		}
		return maxVal;
    }
};  