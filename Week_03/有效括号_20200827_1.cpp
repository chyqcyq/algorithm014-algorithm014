///将所有答案遍历打出
class Solution {
public:
    vector<string> generateParenthesis(int n) {		
		string tmpS;
		Recurison(0, 2*n, tmpS);
		return strVec;
    }

	void Recurison(int level, int maxLevel, string &s) {
		//终结条件
		if(level >= maxLevel) {
			cout << "tmS = " << s << endl;      
			return ;
		}
		//逻辑处理

		//递归下层
		Recurison(level+1, maxLevel, s + "(");
		Recurison(level+1, maxLevel, s + ")");
		//处理当前层
	}
private:
	vector<string> strVec;
};

///增加判断条件
class Solution {
public:
    vector<string> generateParenthesis(int n) {		
		string tmpS;
		int leftSize = 0;
		int rightSize = 0;

		Recurison(n, tmpS, leftSize, rightSize);
		return strVec;
    }

	void Recurison(int n, string &s, int leftSize, int rightSize) {
		//终结条件
		if((leftSize == n) && (rightSize == n)) {
			strVec.push_back(s);
			//cout << "tmS = " << s << endl;      
			return ;
		}
		//逻辑处理

		//递归下层		
		if(leftSize < n) {
			string tmpS = s + "(";
			Recurison(n, tmpS, leftSize+1, rightSize);
		}
		if((leftSize > rightSize) && (rightSize < n)) {		
			string tmpS = s + ")";
			Recurison(n, tmpS, leftSize, rightSize+1);
		}
		//处理当前层
	} 
private:
	vector<string> strVec;
};