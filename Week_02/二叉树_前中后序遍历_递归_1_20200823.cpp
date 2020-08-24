using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode * right;
	TreeNode(int x):val(x),left(NULL),right (NULL) {
	}
};

//二叉树的遍历（递归方法）
//对于递归考虑的方法：
//1、考虑递归的入参和返回值；
//2、考虑递归的终止条件；
//3、确定单层递归的处理逻辑

class CBinaryTree {
public:
	//前序
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) {
			return retVec;
		}
		retVec.push_back(root->val); //根
		preorderTraversal(root->left); //左
		preorderTraversal(root->right);//右
		return retVec;
    }
	//中序
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) {
			return retVec;
		}
		inorderTraversal(root->left); //左
		retVec.push_back(root->val); //根
		inorderTraversal(root->right);//右
		return retVec;
    }
	//后序
    vector<int> postorderTraversal(TreeNode* root) {		
        if(root == NULL) {
			return retVec;
		}
		postorderTraversal(root->left); //左
		postorderTraversal(root->right);//右
		retVec.push_back(root->val); //根
		return retVec;
    }

private:
	vector<int> retVec;
};