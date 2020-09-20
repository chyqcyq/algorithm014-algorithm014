//本地编译器用例可以得到正确值，力扣的值错误，原因暂未找到。
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		int retVal;
		set <pair<int, int>> obSet;
		for(int i = 0; i < obstacles.size(); i++) {
			obSet.insert(make_pair(obstacles[i][0], obstacles[i][1]));
		}
		//dx dy合起来分别对应于一个环形
		//向上1步 x+0，y+1
		//向右1步 x+1, y+0
		//向下1步 x-0, y-1
		//向左1步 x-1, y-0
		int dx[4] = {0, 1, 0,  -1};
		int dy[4] = {1, 0, -1, 0};
		int x = 0, y = 0, di = 0;
		for(int i = 0; i<commands.size();i++) {			
			if(commands[i] == -1) {
				//当前方向向右则只需要数组加1即可
				//譬如向上方向加1变向右；向右方向加1变向下；以此类推
				di = (di+1) % 4;
			}
			else if(commands[i] == -2) {
				//同理，如果是要向左，则需要加3
				di = (di+3) % 4;
			}
			else {
				//向前前进commands[i]步
				for(int j = 0; j < commands[i]; j++) {
					//没有障碍物的情况下，下一步的坐标
					int nx = x + dx[di];
					int ny = y + dy[di];
					if(obSet.find(make_pair(nx, ny)) == obSet.end()) {
						//当前步数障碍物
						x = nx;
						y = ny;
						retVal = max(retVal, (x*x + y*y));
					}
					else {
						//当前已经碰到障碍物了，可以直接跳过接下来的步数；
						break;
					}
				}
			}
		}
		return retVal;
    }
};