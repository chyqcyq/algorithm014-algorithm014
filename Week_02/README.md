学习笔记

__2020/08/17 周一 （23:50~23:52） 心情：些许焦虑__
## 总结
今天学习完了第一周的课程，柱形图的最大矩形以及滑动窗口最大值听明白了，没有实践编码，后期需要补上。Link List的环形链表内容没有看也没有实践，要补上。把昨天没弄明白的有效括号弄明白了并编码成功，算是小小的战役胜利。
## 感想  
时间还是要挤。晚上睡觉时间要保证。早上才能早些起。

***

__2020/08/18 周二 （23:24~23:30） 心情：无奈__
## 总结
看完了哈希课程，讲的都是一些基本概念，值以哈希函数（散列函数）的形式，存在一个哈希表中。若是哈希的表size不够大，则产生了哈希碰撞（冲突），于是在此哈希值内拉一个链表进行存储。讲了如何去查看java的哈希set与哈希map。由于哈希map为key-Value形式，key不能重复，value可重复。因此哈希set实际上是将值存放在map的key上，保证不重复。而哈希map则要相对复杂些，重点看懂get与put的代码（看样子还是得学习下java的常用语法，应该不难）。
## 感想
今天10:30下班，几乎没有时间学习。有些失落和无奈。早点休息，明天早起继续。

***

__2020/08/19 周三 （23:58~23:59） 心情：紧迫感__
## 总结
* 完成了昨日未完成的有效的字母异位词编写；
* 做题四件套  
    1.反复确认题干；  
    2.尽可能想到多的解决方案并从中找到最优解（时间&&空间复杂度）；  
    3.确认编写代码；  
    4.最后测试代码；  
* 树、二叉树、二叉搜索树  
	1.数与图的区别，但形成了环，便是图，而不能称之为树；  
	2.树分为根节点以及左右子节点；  
	3.树的遍历；  
		* 前序：根-左-右  
		* 中序：左-根-右  
		* 后序：左-右-根  
	```C++
	//树的实现
	struct NodeTree {
		int val;
		NodeTree* left;
		NodeTree* right;
		NodeTree(int x):val(x), left(NULL), right(NULL) {
		}
	};
	```
## 感想
时间不够。

***

__2020/08/22 周六 （23:58~23:59） 心情：紧迫感__
## 总结
* 复习链表并实践  
	···C++
	//节点的定义
	struct ListNode {
		int val;
		ListNode *pNext;
		ListNode(){}
		ListNode(int x, ListNode *nextNode):val(x), pNext(nextNode){}
	};

	//链表节点的定义与接口
	class linkList {
	public:
		//默认构造函数
		linkList(){
			firstNode = NULL;
			listSize = 0;
		}
		//拷贝构造函数
		linkList(const linkList &theList){
			this->listSize = theList.listSize;
			if(theList.listSize == 0) {
				firstNode = NULL;
				return ;
			}
			
			//源链表节点的头结点
			ListNode *srcNode = theList.firstNode;
			//本链表头结点使用源节点头结点值
			firstNode = new ListNode(srcNode->val);

			//本链表节点头结点
			ListNode *targetNode = firstNode;
			//源链表节点后移一个节点
			srcNode = srcNode->pNext;
			
			while (srcNode->pNext != NULL) {
				//本节点的后一个节点以源节点复制
				targetNode->pNext = new ListNode(srcNode->val);
				//源节点节点后移一个节点
				targetNode = targetNode->pNext;
				//本节点后移一个节点
				srcNode = srcNode->pNext;
			}
			targetNode->pNext = NULL;
		}

		~linkList(){
			while(firstNode != NULL) {
				ListNode* nextNode = firstNode->pNext;
				delete firstNode;
				firstNode = nextNode;
			}
		}

	public:
		//获得索引为index的val
		int getIndexof(int index) {
			if((index<0) || (index>this->listSize)) {
				return -1;
			}
			ListNode *curNode = firstNode;
			for(int i=0; i<index; i++) {
				curNode = curNode->pNext;
			}
			return curNode->val;
		}
		//在索引为index的位置插入val
		bool insert(int index, int val) {
			bool ret = false;
			if((index<0) || (index>this->listSize)) {
				return ret;
			}

			if(index == 0) {
				//链表头插
				firstNode = new ListNode(val, firstNode);
			}
			else {
				ListNode *curNode = firstNode;
				//"-1"的原因是因为要插入元素位置在index上，所以要在index前一个节点操作
				for(int i=0; i<index-1; i++) {
					curNode = curNode->pNext;
				}
				//节点的构造函数会将当前节点的下一个节点重新分配给新分配出来节点的next指针
				curNode = new ListNode(val, curNode->pNext);
			}
			listSize++;
		}

	private:
		ListNode *firstNode;
		int listSize;
	};		
	···
## 感想
朋友来访，耽误了一些时间。刷题300，任到重远。	


