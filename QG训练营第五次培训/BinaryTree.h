#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED


typedef char TElemType;     // 假设二叉树结点的元素类型为字符


typedef struct BiTNode {
    TElemType      data;     // 数据域
    struct BiTNode  *lchild,*rchild;  // 左、右孩子指针
} BiTNode, *BiTree;   // 二叉链表

typedef enum Status{
	SUCCESS,
	ERROR
}Status;


/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : 构造空二叉树T
 *  @param       : 二叉树根结点T
 */
Status InitBiTree(BiTree *T);
void DoInitBiTree(BiTree *T);


/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : 摧毁二叉树T
 *  @param       : 二叉树根结点T
 */
Status DestroyBiTree(BiTree *T);
void DoDestroyBiTree(BiTree *T);


/**
 *  @name        : Status CreateBiTree(BiTree T, char* definition);
 *  @description : 构造二叉树T
 *  @param       : 二叉树根结点T, 二叉树先序遍历字符串definition
 */
Status CreateBiTree(BiTree *T, char* definition);
void DoCreateBiTree(BiTree *T);

//
//
//

void Traverse(BiTree T, Status foo(BiTree T, Status (*visit)(TElemType e)));		//测试遍历树的函数 

/**
 *  @name        : Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : 先序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
Status PrePreOrderTraverse(BiTree T, Status (*visit)(TElemType e));		//先序遍历二叉树T（非递归）
Status visit(TElemType e);


/**
 *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));	
 *  @description : 中序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));	
Status CirInOrderTraverse(BiTree T, Status (*visit)(TElemType e));	//中序遍历非递归版
/**
 *  @name        : Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)));
 *  @description : 后序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e));


/**
 *  @name        : Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : 层序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));


/**
 *  @name        : int Value(BiTree T);
 *  @description : 对构造出的前缀表达式二叉树求值
 *  @param       : 二叉树根结点T
 *  @note        : 可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
 *                 可根据需要自行增加操作.
 */
int Value(BiTree *T); 
Status Enter(char *s);		//读取前缀表达式并转换成先序遍历可以使用的结构 
void Calcultator(void);



//其它函数

void ShowMenu(void);
void GetNumber(int *n); 









#endif // BINARYTREE_H_INCLUDED
