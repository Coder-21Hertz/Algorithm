/*
 * 给定一个二叉树，原地将它展开为链表。
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/submissions/
 *        1       1
 *      /  \       \
 *     2   5        2
 *   / \    \       \
 *  3   4   6        3
 *                    \
 *                     4
 *                      \
 *                      5
 *                       \
 *                        6
 *        1                                  1                    1
 *      /  \  把右子树先搭到左子树最右边        /   在移动回右子树       \     依次类推
 *     2   5   --------------------->      2   ------------->      2    .......
 *   / \    \                            /  \                    /  \
 *  3   4   6                           3    4                  3    4
 *                                            \                       \
 *                                             5                       5
 *                                              \                       \
 *                                               6                       6
 */

#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        while(root != nullptr)
        {
            if(root->left != nullptr)
            {
                auto most_right = root->left;
                while(most_right->right != nullptr)
                    most_right = most_right->right;     //移动到最右结点
                most_right->right = root->right;        //把root的右子树移动到most的右子树
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;     //因为已经全部移到右子树，所以，下一次直接指向右子树
        }
    }
};


