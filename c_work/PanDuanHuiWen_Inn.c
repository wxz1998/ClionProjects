//
// Created by wxz18 on 2019/4/25.
//

#include <stdio.h>
#include<stdlib.h>
//������С
#define M 100
//����ջ
typedef struct {
    char data[M];
    int top;
} zhan;

//��ʼ��ջ
void ChuShiHuaZhan(zhan *s) {
    s->top = 0;
}

//�ж�ջ�Ƿ�Ϊ��
int PanDuanZhanKong(zhan *s) {
    if (s->top == 0) {
        return 0;
    } else {
        return 1;
    }
}

//��ջ
void RuZhan(zhan *s, char x) {
    if (s->top == M) {
        printf("ջ��\n");
    } else {
        s->data[++s->top] = x;
    }
}

//��ջ
char ChuZhan(zhan *s) {
    char y;
    if (s->top == 0) {
        printf("ջ��\n");
        return '0';
    } else {
        y = s->data[s->top];
        s->top = s->top - 1;
        return y;
    }
}

//�������
typedef struct {
    char data[M];
    int front;
    int rear;
} dui;

//��ʼ������
void ChuShiHuaDuiLie(dui *q) {
    q->front = q->rear = 0;
}

//���
void RuDui(dui *q, char e) {
    if ((q->rear + 1) % M == q->front) {
        printf("����Ϊ��\n");
    } else {
        q->data[q->rear] = e;
        q->rear = (q->rear + 1);
    }
}

//����
char ChuDui(dui *q) {
    char f;
    if (q->front == q->rear) {
        printf("����Ϊ��\n");
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
    printf("����һ���ַ�,���� $ ���ű�ʾ��ֹ����:\n");
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
        printf("Yes! ���ַ���Ϊ����\n");
    else
        printf("No! ���ַ������ǻ���\n");
    return 0;
}
