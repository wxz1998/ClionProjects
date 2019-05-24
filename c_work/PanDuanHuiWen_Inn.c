//
// Created by wxz18 on 2019/4/25.
//

#include <stdio.h>
#include<stdlib.h>
//容量大小
#define M 100
//定义栈
typedef struct {
    char data[M];
    int top;
} zhan;

//初始化栈
void ChuShiHuaZhan(zhan *s) {
    s->top = 0;
}

//判断栈是否为空
int PanDuanZhanKong(zhan *s) {
    if (s->top == 0) {
        return 0;
    } else {
        return 1;
    }
}

//入栈
void RuZhan(zhan *s, char x) {
    if (s->top == M) {
        printf("栈空\n");
    } else {
        s->data[++s->top] = x;
    }
}

//出栈
char ChuZhan(zhan *s) {
    char y;
    if (s->top == 0) {
        printf("栈空\n");
        return '0';
    } else {
        y = s->data[s->top];
        s->top = s->top - 1;
        return y;
    }
}

//定义队列
typedef struct {
    char data[M];
    int front;
    int rear;
} dui;

//初始化队列
void ChuShiHuaDuiLie(dui *q) {
    q->front = q->rear = 0;
}

//入队
void RuDui(dui *q, char e) {
    if ((q->rear + 1) % M == q->front) {
        printf("队列为空\n");
    } else {
        q->data[q->rear] = e;
        q->rear = (q->rear + 1);
    }
}

//出队
char ChuDui(dui *q) {
    char f;
    if (q->front == q->rear) {
        printf("队列为空\n");
        return 0;
    } else {
        f = q->data[q->front];
        q->front = (q->front + 1);
        return f;
    }
}

int main() {
    char c;
    int y = 0;
    zhan *s = (zhan *) malloc(sizeof(zhan));
    dui *q = (dui *) malloc(sizeof(dui));
    ChuShiHuaZhan(s);
    ChuShiHuaDuiLie(q);
    printf("输入一串字符,键入 $ 符号表示终止输入:\n");
    while ((c = getchar()) != '$') {
        RuZhan(s, c);
        RuDui(q, c);
    }
    while (PanDuanZhanKong(s)) {
        if (ChuZhan(s) == ChuDui(q)) {
            y = 1;
            continue;
        } else {
            y = 0;
            break;
        }
    }
    if (y == 1)
        printf("Yes! 此字符串为回文\n");
    else
        printf("No! 此字符串不是回文\n");
    return 0;
}
