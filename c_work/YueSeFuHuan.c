//
// Created by wxz18 on 2019/4/17.
//
/*Լɪ�򻷣�Լɪ�����⣩��һ����ѧ��Ӧ������:��֪n���ˣ��Ա��1��2��3...n�ֱ��ʾ��
 * Χ����һ��Բ����Χ���ӱ��Ϊk���˿�ʼ����������m���Ǹ��˳���;
 * ������һ�����ִ�1��ʼ����������m���Ǹ����ֳ���;���˹����ظ���ȥ��ֱ��Բ����Χ����ȫ�����С�
 * ͨ�������������ʱ���ǰѱ�Ŵ�0~n-1�������+1��Ϊԭ����Ľ⡣*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} person;

person *initLink(int n) {
    person *head = (person *) malloc(sizeof(person));
    head->number = 1;
    head->next = NULL;
    person *cyclic = head;
    for (int i = 2; i <= n; i++) {
        person *body = (person *) malloc(sizeof(person));
        body->number = i;
        body->next = NULL;
        cyclic->next = body;
        cyclic = cyclic->next;
    }
    cyclic->next = head;//��β����
    return head;
}

void findAndKillK(person *head, int k, int m) {
    person *tail = head;
//�ҵ�������һ��������һ����㣬Ϊɾ��������׼��
    while (tail->next != head) {
        tail = tail->next;
    }
    person *p = head;
//�ҵ����Ϊk����
    while (p->number != k) {
        tail = p;
        p = p->next;
    }
//�ӱ��Ϊk���˿�ʼ��ֻ�з���p->next==pʱ��˵�������г���p��㣬���б�Ŷ������ˣ�
    while (p->next != p) {
//�ҵ���p����1��ʼ����m���ˣ����һ�Ҫ֪����m-1de�˵�λ��tail��������ɾ��������
        for (int i = 1; i < m; i++) {
            tail = p;
            p = p->next;
        }
        tail->next = p->next;//�������Ͻ�p���ժ����
        printf("�����˵ı��Ϊ:%d\n", p->number);
        free(p);
        p = tail->next;//����ʹ��pָ��ָ����б�ŵ���һ����ţ���Ϸ����
    }
    printf("�����˵ı��Ϊ:%d\n", p->number);
    free(p);
}

int main() {
    printf("����Բ���ϵ�����n:");
    int n;
    scanf("%d", &n);
    person *head = initLink(n);
    printf("�ӵ�k�˿�ʼ����(k>1��k<%d)��", n);
    int k;
    scanf("%d", &k);
    printf("����m���˳��У�");
    int m;
    scanf("%d", &m);
    findAndKillK(head, k, m);
    return 0;
}