#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef int ElemType;

struct BinaryNode
{
    ElemType element;        //当前结点的值
    BinaryNode *left;        //左结点引用
    BinaryNode *right;       //右结点引用

    BinaryNode(const ElemType &theElement)
        : element(theElement), left(NULL), right(NULL){}
};

/* 插入 */
void insert(BinaryNode *&t, const ElemType x)
{
    if(t == NULL)
        t = new BinaryNode(x);
    else if(x < t->element)
        insert(t->left, x);
    else if(x > t->element)
        insert(t->right, x);
    else
        ;       //等于的情况，不用插入
}

/* 中序遍历（有序），递归 */
void inOder(const BinaryNode *t)
{
    if(t){
        inOder(t->left);
        cout << t->element <<",";  //前中后序遍历，看当前结点相对于左右结点的位置，即这句话的位置
        inOder(t->right);
    }
}

/* 查找 */
bool contains(const BinaryNode *t, const ElemType x)
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

/* 删除 */
void remove(BinaryNode *&t, const ElemType x)
{
    if(t == NULL)
        return;
    if(x < t->element)
        remove(t->left, x);
    else if(x > t->element)
        remove(t->right, x);
    else if(t->left != NULL && t->right != NULL)
    {
        BinaryNode *ri = t->right;

        while(ri->left != NULL)
            ri = ri->left;
        t->element = ri->element;
        remove(t->right, t->element);
    }
    else
    {
        BinaryNode *oldNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete oldNode;
    }
}

int main()
{
    vector<int>a = {1,3,2,4,7,6,8,5};
    BinaryNode *t = new BinaryNode(1);
    for(auto it = a.begin(); it != a.end(); it++)
    {
        insert(t, *it);
    }

    if(contains(t, 3))
        cout << "true" << endl;
    remove(t, 3);
    inOder(t);
}
