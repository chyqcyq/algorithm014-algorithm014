///方法一：没有思想，暴力方法，统计频次

class Solution {
public:
    bool isAnagram(string s, string t) {
		bool ret = true;
		int val1[127] = {0};
		int val2[127] = {0};

		for(int i = 0; i<s.length(); i++) {
			char tmpCh = s[i];			
			val1[(int)tmpCh]++;
		}

		for(int i = 0; i<t.length(); i++) {
			char tmpCh = t[i];
			val2[(int)tmpCh]++;
		}

		for(int i = 0; i<127; i++) {
			if(val1[i] != val2[i]) {
				ret  = false;
				break;
			}
		}

		return ret;
    }
};

///方法二，利用已有接口进行sort

class Solution {
public:
    bool isAnagram(string s, string t) {
		bool ret = true;

		sort(s.begin(),s.end());
		cout << s << endl;
		sort(t.begin(),t.end());
		cout << t << endl;
		
		if(0 != s.compare(t)) ret = false;
		else ret = true;

		return ret;
    }
};

/// 方法三，利用哈希表，没想到就是方法一的思想，不过用了哈希的思想而已
/// 哈希即利用散列函数（此处为ASCII码），将值存放在内存中。

class Solution {
public:
    bool isAnagram(string s, string t) {
		if(s.length() != t.length()) {
			return false;
		}
		bool ret = true;

		int cnt[26] = {0};		

		for(int i=0; i<s.length(); i++) {
			cnt[(int)s[i]- 'a']++;
			cnt[(int)t[i]- 'a']--;
		}		
		cout << endl;
		for(int i=0; i<26; i++) {
			if(cnt[i] != 0) {
				ret = false;
				break;
			}
		}


		return ret;
    }
};

