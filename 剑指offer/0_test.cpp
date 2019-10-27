/*
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
 *
 * 要的是双向链表https://pic4.zhimg.com/80/v2-dfed873e672f0cb9aa0f6cd729fc19df_hd.jpg
 *             https://blog.csdn.net/willduan1/article/details/53349990
 *             https://zhuanlan.zhihu.com/p/39025518
 * 由于二叉树的中序遍历具有可以实现递增的功能，同时二叉树的每一个节点都有两个指针，
 * 左指针和右指针，因此我们可以用这些特点将二叉树转换成一个双向链表，每次在递归遍历
 * 的时候设置一个pre，记录中序遍历时当前节点的前节点，然后"将当前节点的左指针指向pre节点"，
 * 然后如果pre节点不为空则"将pre的右节点指向当前节点"，由此就形成了一个双向链表的前后指针。
 * 每次递归重复这两步，则可以形成一个完整的双向链表。
 *      3
 *     /
 *    2
 *   /
 *  1
 *  \
 *   2
 *    \
 *     3
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {}
};

TreeNode* Convert(TreeNode* pRootOfTree)
{
	if(pRootOfTree == nullptr)
		return nullptr;
	stack<TreeNode*> s;
	TreeNode* p = pRootOfTree;
	TreeNode* pre = nullptr;
	while(p != nullptr || !s.empty())
	{
		while(p != nullptr)
		{
			s.push(p);
			p = p->left;
		}
		if(!s.empty())
		{
			p = s.top();
			s.pop();
			if(pre != nullptr)
			{
				p->left = pre;
				pre->right = p;
			}
			else
				pRootOfTree = p;
			pre = p;
			p = p->right;
		}
	}
	return pRootOfTree;
}