学习笔记

__2020/09/01 /09/02 /09/03 周一/二/三 心情：紧迫感__ (总结放一块儿)
## 总结
* 搜索-遍历  
	+ 每个节点要访问一次  
	+ 每个节点仅仅访问一次  
	+ 对于节点的访问顺序  
		++ 深度优先搜索DFS(depth first search)  
		```C++
		//递归模板
		map<int, int>  visited; // 由于val是int型，所以value是int
		void dfsRec(dfsNode* root) {
			//不再有下层节点
			if(NULL == root) return;
			//已访问
			if(visited.count(root->val)) return;
			visited.insert(pair<int, int>(root->val, 1));
			//处理当前逻辑
			for (uint i = 0; i < root->pChildren.size(); i++) {
				//直接去访问子节点
				dfsRec(root->pChildren[i]);
			}
			//恢复当前层状态
		};
		
		//非递归模板
		void dfsNormal(dfsNode* root) {
			map<int, int> visitedVal;
			if(NULL == root) return;
			//建立初始栈(先进后出)
			stack<dfsNode*> stackNode;
			//根节点推入栈顶
			stackNode.push(root);
			while (!stackNode.empty()) { //栈不为空
				//取出根节点
				dfsNode *node = stackNode.top();
				stackNode.pop();
				//取出节点判断是否已访问
				if(visitedVal.count(node->val)) continue;
				visitedVal.insert(pair<int, int> (node->val, 1));
				for(int i = node->pChildren.size(); i>=0; i--) {
					//将子节点栈顶，由于先进后出，因此将最右子节点最先放
					stackNode.push(node->pChildren[i]);
				}
			}
		}
		```
		++ 广度优先搜索BFS(breadth first search)  
		```C++
		void bfs(dfsNode *root) {
			map<int, int> visitedNode;

			if(NULL == root) return;

			queue<dfsNode *> queueNode;
			queueNode.push(root);

			while(!queueNode.empty()) {
				dfsNode *tmpNode = queueNode.front();
				queueNode.pop();
				if(visitedNode.count(tmpNode->val)) continue;
				visitedNode.insert(pair<int, int> (tmpNode->val, 1));
				for(int i = 0; i<tmpNode->pChildren.size(); i++) {
					queueNode.push(tmpNode->pChildren[i]);
				}
			}
		}
		```
		++ 其他(优先级优先或者从中间搜索等等)  
* 深度优先与广度优先自我总结  
	+ 深度优先搜索是优先向子节点进行搜索，而广度优先搜索则是层次遍历当前层的所有节点；  
	+ 从非递归的代码实现来看，两者均是通过STL容器来实现深度或者广度的节点进行保存与遍历；  
		++ 深度优先搜索是将中间变量暂存在STL容器的栈(stack)内，栈的特点是先进后出，利用栈的这个特性，访问到父节点时，将子节点最右存到栈内（最后出），遍历完所有该层子节点后。下一个循环取最后一次存入栈的容器，此时便会继续深入向下，返回时则会一直返回到根节点继续向下，这个刚好与递归的特性类似，于是就有了递归写法。递归写法的终结条件即是不再存在子节点返回。  
		++ 广度优先搜索则是将中间变量暂存在STL容器的队列(queue)内，队列的特点是先进先出，利用队列的这个特性，访问到父节点时，将下层所有子节点存入queue内，在下次取内容时，则是会按照存入的顺序，层次遍历所有节点。  

***

__2020/09/04 周四 心情：紧迫感__ 
## 总结
* 二分查找的前提
	+ 函数单调性(单调递增或者递减)；  
	+ 存在上下界；  
	+ 能够通过索引访问；  
* 代码模板
	```C++
		int middleSearch(vector<int> nums, int target) {
		int index = -1;
		if(nums.size() > 0) {
			int left  = 0;
			int right = nums.size() - 1;
			while(left <= right) {
				int middle = left + (right - left) / 2;
				cout << "middle = " << middle << endl;
				if(target == nums[middle]) {
					index = middle;
					break;
				}
				else if(target < nums[middle]) {
					right = middle - 1;
				}
				else {
					left = middle +1;
				}
			}			
		}
		return index;
    }
	```
