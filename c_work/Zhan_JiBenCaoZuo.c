//
// Created by wxz18 on 2019/4/25.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *top;//ջ��
    int *base;//ջ��
    int stackSize;//���ռ�
} sqs;

void Init(sqs *s)//��ʼ��ջ
{
    s->base = (int *) malloc(100 * sizeof(int));
    s->top = s->base;//��ʼջ����ջ���غ�
    s->stackSize = 100;//ջ���������
}

void RuZhan(sqs *s, int e)//��ջ
{
    if (s->top - s->base >= s->stackSize) {
        s->base = (int *) realloc(s->base, (s->stackSize + 10) * sizeof(int));//��������һ�γ���Ϊs->stack+10�Ŀռ䣬����ԭ�������ݸ��ƹ�ȥ
        s->top = s->base + s->stackSize;//����ջ��
        s->stackSize = s->stackSize + 10;//����ջ���������
    }
    *(s->top) = e;
    s->top++;
}

//��ջ
void ChuZhan(sqs *s) {
    if (s->top == s->base)//ջΪ��ջ
        return;
    while (s->top - 1 != s->base)
        printf("%d ", *--(s->top));
    printf("%d\n", *(--s->top));
}

//���ջ(���¸�ֵʱ��ֱ�Ӹ���ԭ����Ԫ��)
void QingKongZhan(sqs *s) {
    s->top = s->base;
}

//����ջ
void XiaoHuiZhan(sqs *s) {
    int i, len;
    len = s->stackSize;//len=ջ�ĳ���
    for (i = 0; i < len; i++) {
        free(s->base);//�ͷ�ջ��
        s->base++;//ջ����ջ�������ƶ�
    }
    s->base = s->top = NULL;
    s->stackSize = 0;
}

//��ջ�ĵ�ǰ����(�����������,���������s->stack)
void RongLiang(sqs *s) {
    printf("��ǰջ������Ϊ%d\n", s->top - s->base);
}