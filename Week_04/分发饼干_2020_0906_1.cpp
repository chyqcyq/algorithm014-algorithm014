//方法一：暴力法
//先将小孩食量和饼干大小从小到大排序
//然后用两个循环将饼干分配给小孩，由于开始认为饼干可分割，实际上不可，造成用例不通过。
//譬如size为3的饼干分配给食量为2的小孩，不会多出size为1的饼干给下一个小孩儿；
//时间复杂化度：O(n^4)，排序各n，分配又有两轮n，因此是4次方
//空间复杂度：O(1)，只需要记录当前剩余饼干index即可。
int findContentChildren(vector<int>& g, vector<int>& s) {
	int num = 0;
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int jeqZero = 0;
	for(int i=0; i<g.size(); i++) {
		for(int j = jeqZero; j<s.size(); j++) {
			if(s[j] >= g[i]) {
				//饼干数量能满足食量
				//更新饼干数量
				//s[j] -= g[i];
				s[j] = 0;
				jeqZero = j;
				num = i+1;
				cout << "i = " << i << ",j = " << j << endl;
				break;
			}
		}			
	}
	return num;
}