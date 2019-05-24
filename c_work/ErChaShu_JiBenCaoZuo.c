//
// Created by wxz18 on 2019/5/15.
// ����һ�ö��������Ա��ʵ�ֶ����������»���������
// 1.���������й���һ�ö��������ʾ�Ķ�����T��
// 2.����ö��������б������������򡢺����Լ���α������ֱ�������ı������У�
// 3.������������/�����Ŀ/Ҷ�����Ŀ��
// 4.��������ÿ������������������λ�á���ѡ����
// [����Ҫ��]
// �Ӽ��̽������루���򣩣��Զ���������Ϊ�洢�ṹ������������������������������
// [��������]
// �����룺ABC���DE��G���F���棨���Ч��ʾ�ո��ַ���
// ��������Ϊ
// ����ABCDEGF
// ����CBEGDFA
// ����CGEFDBA
// ����ABCDEFG

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ���������ݽṹ����
typedef struct BiTNode {
    char data;
    struct BiTNode *lChild;
    struct BiTNode *rChild;
} BiTNode, *BiTree;

// �������Ľ���--��������ʽ����--����
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

// �������  ������
void XianXUBianLi(BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%c ", T->data);
    XianXUBianLi(T->lChild);
    XianXUBianLi(T->rChild);
}

// ������� �����
void ZhongXuBianLi(BiTree T) {
    if (T == NULL) {
        return;
    }
    ZhongXuBianLi(T->lChild);
    printf("%c ", T->data);
    ZhongXuBianLi(T->rChild);
}

// ������� ���Ҹ�
void HouXuBianLi(BiTree T) {
    if (T == NULL) {
        return;
    }
    HouXuBianLi(T->lChild);
    HouXuBianLi(T->rChild);
    printf("%c ", T->data);
}

// �����
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

// �ڵ���
int NodeCount(BiTree T) {
    if (T == NULL) {
        return 0;
    } else {
        return NodeCount(T->lChild) + NodeCount(T->rChild) + 1;
    }
}

// Ҷ�ӽڵ���
int YeZiNodeCount(BiTree T) {}

int main() {
    printf("���Զ�����\n");
    BiTree T;
    T = (BiTree) malloc(sizeof(BiTNode));

    printf("�����������������ʽ�����������ֵ(�ս��Ϊ#):\n");
    CreateBiTree(&T);
    printf("\n");

    printf("����ʽ���������\n");
    XianXUBianLi(T);
    printf("\n");

    printf("����ʽ���������\n");
    ZhongXuBianLi(T);
    printf("\n");

    printf("����ʽ���������\n");
    HouXuBianLi(T);
    printf("\n");

    printf("���Ϊ��\n");
    printf("%d\n", Depth(T));

    printf("�ڵ���Ϊ��\n");
    printf("%d\n", NodeCount(T));

    return 0;
}