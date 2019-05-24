//
// Created by wxz18 on 2019/4/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define true 1
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
LinkList L;

//在表头插入结点
LinkList Create_LinkList1() {
    L = NULL;                        //定义L为空链表
    int x;                                    //设数据元素为int类型
    LNode *s;
    scanf("%d", &x);
    while (x != -1) {
        s = (LNode *) malloc(sizeof(LNode));    //申请内存
        if (s == NULL) {
            printf("申请内存空间失败！");
            break;
        }
        s->data = x;
        s->next = L;    //若是第一个结点，则将NULL赋给s，从第二个开始，
        //因为是从头部插入，所以s->next指向的是上一轮定义的结点
        L = s; //头指针指向最新的结点s
        scanf("%d", &x);
    }
    return L; //返回头指针，通过头指针可以遍历该链表
}

//在表尾插入结点
LinkList Create_LinkList2() {
    L = NULL;
    LNode *s;    //定义结点
    LNode *r;    //定义尾指针，永远指向最后一个结点
    int x;
    s = (LNode *) malloc(sizeof(LNode));    //定义头结点，申请内存
    if (s == NULL) {
        printf("申请内存空间失败！");
    }
    s->next = NULL;
    L = s;    //头指针指向头结点
    r = s;    //尾指针指向头结点		注：此时链表里面没有数据结点
    scanf("%d", &x);
    while (x != -1) {
        s = (LNode *) malloc(sizeof(LNode));
        if (s == NULL) {
            printf("申请内存空间失败！");
            break;
        }
        s->data = x;
        s->next = NULL;
        r->next = s;    //将尾结点的next指向最新的结点
        r = s;          //尾指针指向最新的结点
        scanf("%d", &x);
    }
    return L;
}

//获取链表长度(带头结点)
int Length_LinkList1(LinkList L) {
    LNode *p = L;
    int j = 0;
    while (p->next) {
        p = p->next;
        j++;
    }
    return j;
}

//获取链表长度(不带头结点)
int Length_LinkList2(LinkList L) {
    LNode *p = L;            //非空表下指向的就是第一个结点
    int j = 0;
    while (p) {
        j++;
        p = p->next;
    }
    return j;
}

//按序号查找单链表中的第i个元素结点，找到返回指针，否则返回空 （带头结点）
LNode *Get_LinkList(LinkList L, int i) {
    LNode *p = L;
    int j = 0;
    while (j < i && p->next != NULL) {
        p = p->next;
        j++;
    }
    if (j == i)
        return p;
    else
        return NULL;
}

// 按值查找（带头结点）
LNode *Locate_LinkList(LinkList L, int x) {
    LNode *p = L->next;
    while (p != NULL && p->data != x) {
        p = p->next;
    }
    return p;
}

//插入（前插结点）（带头结点）（失败返回0，成功返回1）
int Insert_LinkList(LinkList L, int i, int x) {
    LNode *p, *s;
    p = Get_LinkList(L, i - 1);    //获取第i-1个结点
    if (p == NULL) {
        printf("参数i错误!\n");
        return 0;
    } else {
        s = (LNode *) malloc(sizeof(LNode));    //申请、填装结点
        if (s == NULL) {
            printf("申请内存空间失败！");
            return 0;
        }
        s->data = x;
        s->next = p->next;
        p->next = s;
        return 1;
    }

}

//删除结点
int Delete_LinkList(LinkList L, int i) {
    LinkList p, s;
    p = Get_LinkList(L, i - 1);    //获取第i-1个节点
    if (p == NULL) {
        printf("第i-1个结点不存在\n");
        return -1;
    } else if (p->next == NULL) {
        printf("第i个结点不存在");
        return 0;
    } else {
        s = p->next;
        p->next = s->next;
        free(s);    //释放*s;
        return 1;
    }
}

//遍历链表
void Find(LinkList L) {
    LNode *p = L->next;
    int i = 0;
    while (p) {
        i++;
        printf("---->|Node%d->data:%d|\n", i, p->data);
        p = p->next;
    }
}

void list() {
    printf("This is a Singly Linked List.\n");
    printf("-----------------------------------\n");
    printf("Please press the button:\n");
    printf("Button 1 ---> Create_LinkList()创建单链表(带头结点,表尾插入)\n");
    printf("Button 2 ---> Length_LinkList(L)获取链表长度\n");
    printf("Button 3 ---> Get_LinkList(L,i)按序号查找\n");
    printf("Button 4 ---> Locate_LinkList(L,x)按值查找\n");
    printf("Button 5 ---> Insert_LinkList(L,i,number)插入结点\n");
    printf("Button 6 ---> Delete_LinkList(L,i)删除结点\n");
    printf("Button 7 ---> Find(L)遍历链表\n");
    printf("Button 8 ---> Exit the program退出程序\n");
    printf("-----------------------------------\n");
}


int main() {
    list();
    while (true) {
        printf("Choose Button: ");
        int n;
        int flag = 1;
        int length, i, number, item;//item用于Insert插入和Detele删除的返回数据
        LNode *p;
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("If you enter '-1',the list is created\n");            //若输入-1，则表示链表元素创建完成
                L = Create_LinkList2();
                printf("-----------------------------------\n");
                break;

            case 2:
                length = Length_LinkList1(L);
                printf("The Singly Link List length is: %d\n", length);        //单链表的长度为
                printf("-----------------------------------\n");
                break;
            case 3:
                printf("Please enter you want to find serial number-->i:  ");//请输入你想查找的序号
                scanf("%d", &i);
                p = Get_LinkList(L, i);
                if (p == NULL) {
                    printf("Sorry!Wrong!\n-----------------------------------\n");            //第i个位置为NULL，错误
                } else {
                    printf("Successsful!The Node data is:%d\n-----------------------------------\n",
                           p->data);//不为NULL，查找成功，输出该结点数据域
                }
                break;
            case 4:
                printf("Please enter you want to find number:  ");
                scanf("%d", &number);
                p = Locate_LinkList(L, number);
                if (p == NULL)
                    printf("Sorry!Wrong!\n-----------------------------------\n");            //第i个位置为NULL，错误
                else
                    printf("Successsful!The Node data is:%d\n-----------------------------------\n",
                           p->data);//不为NULL，查找成功，输出该结点数据域
                break;

            case 5:                            //插入结点
                printf("Please enter i and number:  ");
                scanf("%d%d", &i, &number);
                item = Insert_LinkList(L, i, number);
                if (item == 0)
                    printf("Insert failed-----------------------------------\n");
                else
                    printf("Insert successful-----------------------------------\n");
                break;

            case 6:                                    //删除结点
                printf("Please enter i:  ");
                scanf("%d", &i);
                item = Delete_LinkList(L, i);
                if (item == 0 || item == -1)
                    printf("Delete failed-----------------------------------\n");
                else
                    printf("Delete successful-----------------------------------\n");
                break;

            case 7:
                printf("Traverse Singly Linked List:\n");        //遍历该单链表
                Find(L);
                printf("-----------------------------------\n");
                break;

            case 8:
                printf("Exit the program successful!\n");
                flag = -1;
                break;

            default:
                printf("Sorry！You can't do that!\n");
                flag = -1;
                break;
        }
        if (flag == -1)
            break;
    }

}
