/// 用例"(())((())()()(*)(*()(())())())()()((()())((()))(*"无法通过，还在找原因
/// 死磕了一晚上

class Solution {
public:
    bool checkValidString(string s) {
		istringstream tmpStr(s);
		stack<char> stackTmp;
		stack<char> star;

		char tmpCh;
		int starcnt = 0;
		bool ret = false;

		while(tmpStr >> tmpCh) {
			if(tmpCh == '(') {
				stackTmp.push(tmpCh);
			}
			else if (tmpCh == '*'){
				star.push(tmpCh);
			}
			else {
				if((stackTmp.size() == 0)  && (star.size() == 0)) {
					return false;
				}
				else if((stackTmp.size() == 0)  && (star.size() != 0)) {
					cout << "star pop " << endl;
					star.pop();
					continue;
				}
				else if(stackTmp.size() != 0) {
					char tmpCh1 = stackTmp.top();
					cout << "stackTmp.size() = " << stackTmp.size() << " ";
					cout << "input = " << tmpCh << " stack = " << tmpCh1 <<endl;
					if(tmpCh1 == '(') {
						stackTmp.pop();
						continue;
					}
					else {
						if (star.size() != 0) {
							star.pop();
							continue;
						}
						else {
							cout << "1 return " << endl;
							return false;
						}
					}
				}				
			}
		}

		cout  << "stackTmp.size()" << stackTmp.size() <<endl;
		cout  << "star.size()" << star.size() <<endl;
		if((stackTmp.size() == 0) || (star.size() >= stackTmp.size())) {
			ret = true;
		}

		return ret;
    }
};