//
// Created by wxz18 on 2019/5/15.
// 建立一棵二叉树，试编程实现二叉树的如下基本操作：
// 1.按先序序列构造一棵二叉链表表示的二叉树T；
// 2.对这棵二叉树进行遍历：先序、中序、后序以及层次遍历，分别输出结点的遍历序列；
// 3.求二叉树的深度/结点数目/叶结点数目；
// 4.将二叉树每个结点的左右子树交换位置。（选做）
// [基本要求]
// 从键盘接受输入（先序），以二叉链表作为存储结构，建立二叉树（以先序来建立），
// [测试数据]
// 如输入：ABCффDEфGффFффф（其中ф表示空格字符）
// 则输出结果为
// 先序：ABCDEGF
// 中序：CBEGDFA
// 后序：CGEFDBA
// 层序：ABCDEFG

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 二叉树数据结构定义
typedef struct BiTNode {
    char data;
    struct BiTNode *lChild;
    struct BiTNode *rChild;
} BiTNode, *BiTree;

// 二叉树的建立--按照先序方式建立--插入
void CreateBiTree(BiTree *T) {
    char val;
    scanf("%c", &val);
    if (val == '#') {
        *T = NULL;
    } else {
        *T = (BiTree) malloc(sizeof(BiTNode));
        (*T)->data = val;
        CreateBiTree(&(*T)->lChild);
        CreateBiTree(&(*T)->rChild);
    }
}

// 先序遍历  根左右
void XianXUBianLi(BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%c ", T->data);
    XianXUBianLi(T->lChild);
    XianXUBianLi(T->rChild);
}

// 中序遍历 左根右
void ZhongXuBianLi(BiTree T) {
    if (T == NULL) {
        return;
    }
    ZhongXuBianLi(T->lChild);
    printf("%c ", T->data);
    ZhongXuBianLi(T->rChild);
}

// 后序遍历 左右根
void HouXuBianLi(BiTree T) {
    if (T == NULL) {
        return;
    }
    HouXuBianLi(T->lChild);
    HouXuBianLi(T->rChild);
    printf("%c ", T->data);
}

// 求深度
int Depth(BiTree T) {
    int lDepth, rDepth;
    if (T == NULL) {
        return 0;
    } else {
        lDepth = Depth(T->lChild);
        rDepth = Depth(T->rChild);
        if (lDepth >= rDepth) {
            return (lDepth + 1);
        } else {
            return (rDepth + 1);
        }
    }
}

// 节点数
int NodeCount(BiTree T) {
    if (T == NULL) {
        return 0;
    } else {
        return NodeCount(T->lChild) + NodeCount(T->rChild) + 1;
    }
}

// 叶子节点数
int YeZiNodeCount(BiTree T) {}

int main() {
    printf("测试二叉树\n");
    BiTree T;
    T = (BiTree) malloc(sizeof(BiTNode));

    printf("请给二叉树按照先序方式依次输入结点的值(空结点为#):\n");
    CreateBiTree(&T);
    printf("\n");

    printf("先序方式遍历结果：\n");
    XianXUBianLi(T);
    printf("\n");

    printf("中序方式遍历结果：\n");
    ZhongXuBianLi(T);
    printf("\n");

    printf("后序方式遍历结果：\n");
    HouXuBianLi(T);
    printf("\n");

    printf("深度为：\n");
    printf("%d\n", Depth(T));

    printf("节点数为：\n");
    printf("%d\n", NodeCount(T));

    return 0;
}