给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

注意：两结点之间的路径长度是以它们之间边的数目表示。

/* 求每个节点左子树和右子树高度值和，然后取最大者（每个节点都可能成为最短路径的根节点） */
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
    int res;
    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        res = max(res, 1+left_height+right_height);
        return 1+max(left_height, right_height);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        res = 0;
        height(root);
        return res-1;
    }
};