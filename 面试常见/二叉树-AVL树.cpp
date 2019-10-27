#include <bits/stdc++.h>

using namespace std;
typedef int ElemType;

struct AvlNode{
    ElemType element;
    AvlNode *left;
    AvlNode *right;
    int height;

    AvlNode(const ElemType &theElement)
        : element(theElement), left(NULL), right(NULL), height(0){}
};

inline int height(AvlNode *t)
{
    return nullptr == t ? -1 : t->height;
}

/**
* left可以理解为左边多
* 右旋（左子树比右子树高2，并且新插入的元素在左子树的左边）
* 此时以左子树（k1）为轴，它的根（k2）进行右旋
* 可以理解为它的根在它的右边，所以右旋（在右边旋转）
*       k2                      k1
*      /  \                    /  \
*     k1   C      -------     A    k2
*    /  \                   /     / \
*   A    B                 X     B   C
*  /
* X    X可以忽略理解，X是要插入的值
* X可能中A的左边，也可以在A的右边。例子中假设在左边。
*/
void rotateWithLeftChild(AvlNode *&k2)
{
    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;  //记住+1
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

/**
* 左旋（右子树比左子树高2，并且新插入的元素在右子树的右边）
* 此时以右子树(k1)为轴，它的根(k2)进行左旋
* 可以理解为它的根在它的左边，所以左旋（在左边旋转）
* 可以直接用上面右旋的逆向思维
*      K2                           K1
*     /  \                         /  \
*    C    k1         -----        K2   B
*         / \                    /  \   \
*        A   B                  C    A   X
*             \
*              X   //忽略看
* X可能在C的左边，也可以在C的右边。例子中假设在右边。
**/
void rotateWithRightChild(AvlNode *&k2)
{
    AvlNode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(k2->height, height(k1->right)) + 1;
    k2 = k1;
}


/**
* 左右双旋（左子树K1比右子树D高2，并且新插入的元素在左子树K1的右边K2）
* 第一步：对左子树k1进行一次左旋(轴为k2) 传入参数为k1
* 第二步：对整个树k3进行一次右旋（轴为k2）传入参数为k3
*       k3                k3              k2
*      /  \              /  \            /  \
*     k1   B    ----    k2   B  ----    k1   k3
*    / \               / \             /     / \
*   A   k2            k1  X           A     X   B
*        \           /
*        X          A
* X可能在K2的左边，也可以在K2的右边。例子中假设在右边。
*/
void doubleWithLeftChild(AvlNode *&k3)
{
    rotateWithRightChild(k3->left); //左旋
    rotateWithLeftChild(k3);
}

/**
* 右左双旋（右子树K1比左子树A高2，并且新插入的元素在右子树K1的左边K2）
* 第一步：对右子树k1进行一次右旋（轴为k2）传入参数K1
* 第二步：对整个树k3进行一次左旋（轴为k2）传入参数K3
*      k3              k3                 k2
*     /  \            /  \               /  \
*    A    k1   ----  A    k2     ----  k3    k1
*        / \             /  \         /  \     \
*       K2  B           X    k1      A    X     B
*      /                       \
*     X                         B
* X可能中K2的左边，也可以在K2的右边。例子中假设在左边。
*/
void doubleWithRightChild(AvlNode *&k3)
{
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}

/*
*         单旋    左     双旋         单旋    右     双旋
*         k2            k2          K2            k2
*        /  \          /  \        /  \          /  \
*       k1   C        k1   C      C    k1       C    k1
*      /  \    ----  / \     ----      / \ ----     / \
*     A    B        A   B             A   B        A   B
*    /                   \                \       /
*   X                    X                X      X
*  左右旋区别在于K1和C位置
*  单双旋区别在于X是A还是B的子树
*/
void balance(AvlNode *&k2)
{
    if(k2 == NULL)
        return;

    if(height(k2->left) - height(k2->right) == 2) // 插入后如果节点的左子树比右子树高2（此时t为k2，会到回几次）
    {
        AvlNode *k1 = k2->left;
        if(height(k1->left) >= height(k1->right))                //判断k1的左子树高还是右子树高
            rotateWithLeftChild(k2);
        else
            doubleWithLeftChild(k2);
    }
    else if(height(k2->right) - height(k2->left) == 2)
    {
        AvlNode *k1 = k2->right;
        if(height(k1->right) >= height(k1->left))
            rotateWithRightChild(k2);
        else
            doubleWithRightChild(k2);
    }
    else
        ;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
}
/* 插入 */
void insert(AvlNode *&k2, const ElemType x)
{
    if(k2 == NULL)
        k2 = new AvlNode(x);
    else if(x < k2->element)           //这里判断出K1为左子树还是右子树
        insert(k2->left, x);
    else if(x > k2->element)
        insert(k2->right, x);
    else
        ;       //等于就不用插入
    balance(k2);
}

/* 删除 */
void remove(AvlNode *&k2, const ElemType x)
{
    if(k2 == NULL)
        return;
    else if(x < k2->element)
        remove(k2->left, x);
    else if(x > k2->element)
        remove(k2->right, x);
    else if(k2->left != NULL && k2->right != NULL)
    {
        AvlNode *t = k2->right;

        while(t->left != NULL)      //找到右子树最小的值，这个值比左子树大，又比右子树小
            t = t->left;
        k2->element = t->element;   //把当前点换成右子树最小值
        remove(k2->right, k2->element); //删除右子树中的最小值
    }
    else    //有一个不为null的情况时，由于平衡的原因，不管是哪个，左右子树中只可能有一个有数，并且只有一个子树
    {
        AvlNode *oldNode = k2;
        k2 = (k2->left != NULL) ? k2->left : k2->right; //让k2指向子树，所以要删除k2
        delete oldNode;
    }
    balance(k2);
}

/* 查找 */
bool contains(const AvlNode *t, const ElemType x)
{
    if(t == NULL)
        return false;
    else if(x < t->element)
        return contains(t->left, x);
    else if(x > t->element)
        return contains(t->right, x);
    else
        return true;
}

/* 中序打印子树 */
void inOrder(AvlNode *t)
{
    if(t != nullptr)
    {
        inOrder(t->left);
        cout << t->element << " ";
        inOrder(t->right);
    }
}

/* 中序遍历，非递归 */
void inOrder2(AvlNode *t)
{
    stack<AvlNode *> s;
    AvlNode *p =t;
    while (p != NULL || !s.empty())
    {
        while(p != NULL)
        {                   //前序遍历cout << p->element << " ";放在这里
            s.push(p);
            p = p->left;
        }
        if(!s.empty())      //这里是if
        {
            p = s.top();    //先弹栈，把值给p，让p输出数据
            cout << p->element << " ";
            s.pop();
            p = p->right;
        }
    }
}

/* 前序打印子树 */
void preOrder(AvlNode *t)
{
    if(t != nullptr)
    {
        cout << t->element << " ";
        preOrder(t->left);
        preOrder(t->right);
    }
}
/*前序遍历，非递归 */
void preOrder1(AvlNode *t)
{
    AvlNode *p=t;
    stack<AvlNode*> s;
    while(p != nullptr || !s.empty())
    {
        while(p != nullptr)
        {
            s.push(p);
            cout << p->element << " ";
            p = p->left;
        }
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            p=p->right;
        }
    }
}

/*后序遍历，递归版*/
void PostOrder1(AvlNode* root)
{
    if(root==nullptr)
        return;
    PostOrder1(root->left);
    PostOrder1(root->right);
    cout << root->element << " ";
}
/*
 * 后序遍历，非递归版
 * 需要判断上次访问的节点是位于左子树，还是右子树。
 * 若是位于左子树，则需跳过根节点，先进入右子树，再回头访问根节点；若是位于右子树，则直接访问根节点。
 */
void PostOrder(AvlNode* root)
{
    stack<AvlNode*> s;
    AvlNode* p=root;
    AvlNode* last = nullptr;   //上次访问的结点
    while(p != nullptr || !s.empty())
    {
        while(p != nullptr)
        {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        /* 判断右结点是否为null或者是上次访问的结点*/
        if(p->right == nullptr || p->right == last)
        {
            cout << p->element << " ";
            s.pop();
            last = p;   //记录上次访问的结点
            p = nullptr;    //输出了当前结点，可以说明子树的所有结点已经访问过了，自然就不用在遍历当前结点的左子树了
        }
        else
        {
            p = p->right;   //右结点没有访问过
        }
    }
}
void floorOrder(AvlNode* root)
{
    if(root == nullptr)
        return;
    queue<AvlNode*> s;
    s.push(root);
    while(!s.empty())
    {
        root = s.front();
        cout << root->element << " ";
        s.pop();
        if(root->left) s.push(root->left);
        if(root->right) s.push(root->right);
    }
}

int main()
{
    vector<int>a = {1,3,2,4,7,6,8,5,20,0};
    AvlNode *t = new AvlNode(1);
    for(auto it = a.begin(); it != a.end(); it++)
    {
        insert(t, *it);
    }


    inOrder2(t);
    cout << endl;
    preOrder(t);
    cout << endl;
    preOrder1(t);
    cout << endl;
    PostOrder(t);
    cout << endl;
    PostOrder1(t);
    cout << endl;
    floorOrder(t);
}
