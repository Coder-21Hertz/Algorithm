#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef int ElemType;

#define BLACK 1
#define RED 0

struct RBNode{
    ElemType element;
    bool color;
    RBNode *left;
    RBNode *right;
    RBNode *parent;

    RBNode(const ElemType &theElement = 0)
        : element(theElement), color(RED), left(NULL), right(NULL), parent(NULL){}

    RBNode *grandparent(){
        if(parent == NULL)
            return NULL;
        return parent->parent;
    }
    RBNode *uncle(){
        if(grandparent() == NULL)
            return NULL;
        if(parent == grandparent()->right)
            return grandparent()->left;
        else
            return grandparent()->right;
    }
    RBNode *brother(){
        if(parent->left == this)
            return parent->right;
        else
            return parent->left;
    }
};
RBNode *root, *NIL;
/*
 * 对红黑树的节点(x)进行左旋转
 *
 * 左旋示意图(对节点x进行左旋)：
 *      gp                              gp
 *     /                               /
 *    pa                              X
 *   /  \      --(左旋)-->           / \
 *  A    X                         pa  C
 *     /  \                      /  \
 *    so   C                    A   so
 *
 */
void leftRotate(RBNode *x)
{
    if(x->parent == NULL)
    {
        root = x;
        return;
    }
    RBNode *gp = x->grandparent();
    RBNode *pa = x->parent;
    RBNode *so = x->left;

    pa->right = so;
    if(so != NIL)
        so->parent = pa;
    x->left = pa;
    pa->parent = x;

    if(root == pa)
        root = x;
    x->parent = gp;

    if(gp != NULL){
        if(gp->left == pa)
            gp->left = x;
        else
            gp->right = x;
    }
}

/*
 * 对红黑树的节点(y)进行右旋转
 *
 * 右旋示意图(对节点y进行左旋)：
 *            gp                               gp
 *           /                                /
 *          pa                               x
 *         /  \      --(右旋)-->            /  \
 *        x   B                           A    pa
 *       / \                                  / \
 *      A  so                                so  B
 *
 */
void rightRotate(RBNode *x)
{
    if(x->parent == NULL)
    {
        root = x;
        return;
    }
    RBNode *gp = x->grandparent();
    RBNode *pa = x->parent;
    RBNode *so = x->right;

    pa->left = so;
    if(so != NIL)
        so->parent = pa;
    x->right = pa;
    pa->parent = x;
    if(root == pa)
        root = x;
    x->parent = gp;

    if(gp != NULL){
        if(gp->left == pa)
            gp->left = x;
        else
            gp->right = x;
    }
}
// void insert_case2(RBNode *n);
// void insert_case3(RBNode *n);
// void insert_case4(RBNode *n);
// void insert_case5(RBNode *n);

// void insert_case1(RBNode *n)
// {
//     if(n->parent == NULL)
//         n->color = BLACK;
//     else
//         insert_case2(n);
// }
// void insert_case2(RBNode *n)
// {
//     if(n->parent->color == BLACK)
//         return;
//     else        //n->parent->color == RED,gp一定是BLACK
//         insert_case3(n);
// }
// void insert_case3(RBNode *n)
// {
//     if(n->uncle() != NULL && n->uncle()->color == RED)
//     {
//         n->parent->color = BLACK;
//         n->uncle()->color = BLACK;
//         n->grandparent()->color = RED;
//         insert_case1(n->grandparent());
//     }
//     else
//         insert_case4(n);
// }
// void insert_case4(RBNode *n)
// {
//     if(n == n->parent->right && n->parent);
// }


void insert_case(RBNode *p);
void insert(RBNode *p, int data){
    if(p->element >= data){
        if(p->left != NIL)
            insert(p->left, data);
        else {
            RBNode *tmp = new RBNode();
            tmp->element = data;
            tmp->left = tmp->right = NIL;
            tmp->parent = p;
            p->left = tmp;
            insert_case (tmp);
        }
    } else {
        if(p->right != NIL)
            insert(p->right, data);
        else {
            RBNode *tmp = new RBNode();
            tmp->element = data;
            tmp->left = tmp->right = NIL;
            tmp->parent = p;
            p->right = tmp;
            insert_case (tmp);
        }
    }
}

void insert_case(RBNode *p){
    if(p->parent == NULL){
        root = p;
        p->color = BLACK;
        return;
    }
    if(p->parent->color == RED){
        if(p->uncle()->color == RED) {
            p->parent->color = p->uncle()->color = BLACK;
            p->grandparent()->color = RED;
            insert_case(p->grandparent());
        } else {
            if(p->parent->right == p && p->grandparent()->left == p->parent) {
                leftRotate (p);
                rightRotate (p);
                p->color = BLACK;
                p->left->color = p->right->color = RED;
            } else if(p->parent->left == p && p->grandparent()->right == p->parent) {
                rightRotate (p);
                leftRotate (p);
                p->color = BLACK;
                p->left->color = p->right->color = RED;
            } else if(p->parent->left == p && p->grandparent()->left == p->parent) {
                p->parent->color = BLACK;
                p->grandparent()->color = RED;
                rightRotate(p->parent);
            } else if(p->parent->right == p && p->grandparent()->right == p->parent) {
                p->parent->color = BLACK;
                p->grandparent()->color = RED;
                leftRotate(p->parent);
            }
        }
    }
}

/* 前序打印子树 */
void preOrder(RBNode *t)
{
    if(t != nullptr)
    {
        cout << t->element << ",";
        preOrder(t->left);
        preOrder(t->right);
    }
}

int main()
{
    vector<int>a = {1,3,2,4,7,6,8,5};
    RBNode *t = new RBNode(1);
    for(auto it = a.begin(); it != a.end(); it++)
    {
        insert(t, *it);
    }
    insert(t, 10);
    preOrder(t);
    cout << endl;
    cout << endl;
}