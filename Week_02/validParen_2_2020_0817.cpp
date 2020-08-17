class Solution {
public:
    bool checkValidString(string s) {
		istringstream tmpStr(s);
		stack<int> left;
		stack<int> star;

		char tmpCh;
		int starcnt = 0;
		bool ret = false;
		int index = 0;

		while(tmpStr >> tmpCh) {
			if(tmpCh == '(') {
				left.push(index);
			}
			else if (tmpCh == '*'){
				star.push(index);
			}
			else {
				if(left.size() > 0) left.pop();
 				else if(star.size() > 0) star.pop();
				else return false;
			}
			index++;
		}

		if(left.size() > star.size()) return false;

		while(!left.empty()) {
			//cout << "left = " << left.top()  << ", star = " << star.top() << endl;
			if(left.top() > star.top()) return false;
			else {
				left.pop();
				star.pop();
			}
		}
		return true;
    }
};