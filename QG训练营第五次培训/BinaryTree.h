#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED


typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�


typedef struct BiTNode {
    TElemType      data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode, *BiTree;   // ��������

typedef enum Status{
	SUCCESS,
	ERROR
}Status;


/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : ����ն�����T
 *  @param       : �����������T
 */
Status InitBiTree(BiTree *T);
void DoInitBiTree(BiTree *T);


/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : �ݻٶ�����T
 *  @param       : �����������T
 */
Status DestroyBiTree(BiTree *T);
void DoDestroyBiTree(BiTree *T);


/**
 *  @name        : Status CreateBiTree(BiTree T, char* definition);
 *  @description : ���������T
 *  @param       : �����������T, ��������������ַ���definition
 */
Status CreateBiTree(BiTree *T, char* definition);
void DoCreateBiTree(BiTree *T);

//
//
//

void Traverse(BiTree T, Status foo(BiTree T, Status (*visit)(TElemType e)));		//���Ա������ĺ��� 

/**
 *  @name        : Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
Status PrePreOrderTraverse(BiTree T, Status (*visit)(TElemType e));		//�������������T���ǵݹ飩
Status visit(TElemType e);


/**
 *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));	
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));	
Status CirInOrderTraverse(BiTree T, Status (*visit)(TElemType e));	//��������ǵݹ��
/**
 *  @name        : Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e));


/**
 *  @name        : Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));


/**
 *  @name        : int Value(BiTree T);
 *  @description : �Թ������ǰ׺���ʽ��������ֵ
 *  @param       : �����������T
 *  @note        : ���ڽ��ṹ�������ø�Tagֵ��־������������������������
 *                 �ɸ�����Ҫ�������Ӳ���.
 */
int Value(BiTree *T); 
Status Enter(char *s);		//��ȡǰ׺���ʽ��ת���������������ʹ�õĽṹ 
void Calcultator(void);



//��������

void ShowMenu(void);
void GetNumber(int *n); 









#endif // BINARYTREE_H_INCLUDED
