给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> layer;
        vector<vector<int>> res;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        while(!myqueue.empty())
        {
			/* 记录该层的节点数目n，然后依次访问队头元素 */
            int size = myqueue.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* tmp = myqueue.front();
                myqueue.pop();
                layer.push_back(tmp->val);
                if(tmp->left != NULL)    myqueue.push(tmp->left);
                if(tmp->right != NULL)   myqueue.push(tmp->right);
            }
            res.push_back(layer);
            layer.clear();
        }
        return res;
    }
};
/**
 * 递归解法
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    void level(TreeNode* root, int layer)
    {
        if(layer ==  res.size())
            res.push_back({});
        res[layer].push_back(root->val);
        if(root->left)   level(root->left, layer+1);
        if(root->right)  level(root->right, layer+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return res;
        level(root, 0);
        return res;
    }
};