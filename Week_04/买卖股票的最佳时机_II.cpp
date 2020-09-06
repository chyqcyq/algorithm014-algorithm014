//使用贪心算法,每次只要前一天比后一天价格更高，就把它记录为利润
//时间复杂度：O(n)
//空间复杂度：O(1)
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxP = 0;		
		for(int i = 1; i < prices.size(); i++) {
			if(prices[i] > prices[i-1]) {
				maxP += (prices[i] - prices[i-1]);
			}
		}
		return maxP;
	}
};