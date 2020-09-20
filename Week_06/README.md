学习笔记

__2020/09/01 /09/19 周六 心情：傻逼了__ 
## 状态：  
各种破事，太忙，好难。  
## 总结  
* 分治+回溯+递归+动态规划；  
** 递归模板：
	```C++
	void recurison(int level, int param) {
		//终止条件
		if(level > MAX_LEVEL) {
			return;
		}
		
		//处理当前层逻辑
		
		//下探至下一层
		recurison(level+1, param);
		
		//恢复返回层的状态
	}
	```  
** 	分治模板  
	```C++
	int divid_conquer(Problem *problem, int params) {
		//最终子问题
		if(problem == NULL) {
			return result;
		}
		//分解子问题
		subProblems = split_problem(prolem, data);
		subResult1 = divid_conquer(subProblems[0], p1);
		subResult2 = divid_conquer(subProblems[1], p1);
		subResult3 = divid_conquer(subProblems[2], p1);
		...
		//合并所有返回结果
		
	}
	```  
	
* 要有如下的思维    
** 人肉递归低效，容易出错； 
** 找到最近相似办法，将其拆解成可重复解决的问题；  
** 善用数学归纳法，抵制人肉递归的诱惑；  	
** 本质寻找重复性->计算机指令集  
* 动态规划（Dynamic programming）
** 与分治最不同的是，动态规划是分治+最优子结构，不需要保存所有状态，只需要保存最优状态，淘汰次优状态。譬如菲波那切数列的另一种复杂度更低的写法；即动态规划与递归没有最本质的区别，就看有无最优的子结构；  
** 共性：找到重复子问题；  
** 差异性，最优子结构，中途可以淘汰次优解；  
* 动态规划关键点  
** 最优子结构；  
** 存储中间状态；  
** 递推公式（状态转移方程或者DP方程），算是最难的部分。  



