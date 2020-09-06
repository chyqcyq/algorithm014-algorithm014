//方法一：暴力破解法
//最开始未通过全部测试用例，在20元找零有两种找零方式，此方法优先选择找3张5元，导致用例失败；
//如果20元找零优先使用10元加1张5元的方式，则用例通过
//时间复杂度：O(n)
//空间复杂度：O(1)
bool lemonadeChange(vector<int>& bills) {
	int ret = true;
	map<int, int> mMap;		
	for(int i = 0; i< bills.size(); i++) {
		int money = bills[i];			
		map<int, int>::iterator it = mMap.find(money);			
		int cnt = 0;			
		(it != mMap.end()) ? (cnt = it->second) : (cnt = 0);
		int fiveCnt = mMap[5];
		int tenCnt = mMap[10];
		//cout << "fiveCnt = " << fiveCnt << ", tenCnt = " << tenCnt << endl;
		switch(money) {
		case 5:							
			break;
		case 10:						
			if(fiveCnt < 1) {
				//cout << "return  false 1" << endl;	
				return false;
			}
			else {
				mMap[5] -= 1;
			}
			break;
		case 20:
			if ((tenCnt>=1)&&(fiveCnt>=1)) {
				mMap[10] -= 1;
				mMap[5] -= 1;
			}
			else if(fiveCnt>=3) {
				mMap[5] -= 3;
			}			
			else {
				//cout << "return false 2;" << endl;
				return false;
			}
			break;
		default:
			break;
		}									
		mMap[money] += 1;
	}
	return ret;
}