//
// Created by wxz18 on 2019/4/25.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *top;//栈顶
    int *base;//栈底
    int stackSize;//最大空间
} sqs;

void Init(sqs *s)//初始化栈
{
    s->base = (int *) malloc(100 * sizeof(int));
    s->top = s->base;//初始栈顶和栈底重合
    s->stackSize = 100;//栈的最大容量
}

void RuZhan(sqs *s, int e)//入栈
{
    if (s->top - s->base >= s->stackSize) {
        s->base = (int *) realloc(s->base, (s->stackSize + 10) * sizeof(int));//重新申请一段长度为s->stack+10的空间，并将原来的数据复制过去
        s->top = s->base + s->stackSize;//设置栈顶
        s->stackSize = s->stackSize + 10;//设置栈的最大容量
    }
    *(s->top) = e;
    s->top++;
}

//出栈
void ChuZhan(sqs *s) {
    if (s->top == s->base)//栈为空栈
        return;
    while (s->top - 1 != s->base)
        printf("%d ", *--(s->top));
    printf("%d\n", *(--s->top));
}

//清空栈(重新赋值时会直接覆盖原来的元素)
void QingKongZhan(sqs *s) {
    s->top = s->base;
}

//销毁栈
void XiaoHuiZhan(sqs *s) {
    int i, len;
    len = s->stackSize;//len=栈的长度
    for (i = 0; i < len; i++) {
        free(s->base);//释放栈底
        s->base++;//栈底想栈顶方向移动
    }
    s->base = s->top = NULL;
    s->stackSize = 0;
}

//求栈的当前容量(不是最大容量,最大容量是s->stack)
void RongLiang(sqs *s) {
    printf("当前栈的容量为%d\n", s->top - s->base);
}