


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {		
		vector<int> vectorTmp;
		vector<vector<int>> vectorResult;
		if(NULL == root) return vectorResult;

		queue<TreeNode *> queueNode;
		queueNode.push(root);

		while (!queueNode.empty()){
			int queueSize = queueNode.size();
			for(int i = 1; i<=queueSize; i++) {
				TreeNode *tmpNode = queueNode.front();
				queueNode.pop();
				vectorTmp.push_back(tmpNode->val);				
				if(NULL != tmpNode->left) queueNode.push(tmpNode->left);
				if(NULL != tmpNode->right) queueNode.push(tmpNode->right);
			}
			vectorResult.push_back(vectorTmp);
			vectorTmp.clear();			
		}
		return vectorResult;
    }
};