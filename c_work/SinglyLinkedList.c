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

//�ڱ�ͷ������
LinkList Create_LinkList1() {
    L = NULL;                        //����LΪ������
    int x;                                    //������Ԫ��Ϊint����
    LNode *s;
    scanf("%d", &x);
    while (x != -1) {
        s = (LNode *) malloc(sizeof(LNode));    //�����ڴ�
        if (s == NULL) {
            printf("�����ڴ�ռ�ʧ�ܣ�");
            break;
        }
        s->data = x;
        s->next = L;    //���ǵ�һ����㣬��NULL����s���ӵڶ�����ʼ��
        //��Ϊ�Ǵ�ͷ�����룬����s->nextָ�������һ�ֶ���Ľ��
        L = s; //ͷָ��ָ�����µĽ��s
        scanf("%d", &x);
    }
    return L; //����ͷָ�룬ͨ��ͷָ����Ա���������
}

//�ڱ�β������
LinkList Create_LinkList2() {
    L = NULL;
    LNode *s;    //������
    LNode *r;    //����βָ�룬��Զָ�����һ�����
    int x;
    s = (LNode *) malloc(sizeof(LNode));    //����ͷ��㣬�����ڴ�
    if (s == NULL) {
        printf("�����ڴ�ռ�ʧ�ܣ�");
    }
    s->next = NULL;
    L = s;    //ͷָ��ָ��ͷ���
    r = s;    //βָ��ָ��ͷ���		ע����ʱ��������û�����ݽ��
    scanf("%d", &x);
    while (x != -1) {
        s = (LNode *) malloc(sizeof(LNode));
        if (s == NULL) {
            printf("�����ڴ�ռ�ʧ�ܣ�");
            break;
        }
        s->data = x;
        s->next = NULL;
        r->next = s;    //��β����nextָ�����µĽ��
        r = s;          //βָ��ָ�����µĽ��
        scanf("%d", &x);
    }
    return L;
}

//��ȡ������(��ͷ���)
int Length_LinkList1(LinkList L) {
    LNode *p = L;
    int j = 0;
    while (p->next) {
        p = p->next;
        j++;
    }
    return j;
}

//��ȡ������(����ͷ���)
int Length_LinkList2(LinkList L) {
    LNode *p = L;            //�ǿձ���ָ��ľ��ǵ�һ�����
    int j = 0;
    while (p) {
        j++;
        p = p->next;
    }
    return j;
}

//����Ų��ҵ������еĵ�i��Ԫ�ؽ�㣬�ҵ�����ָ�룬���򷵻ؿ� ����ͷ��㣩
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

// ��ֵ���ң���ͷ��㣩
LNode *Locate_LinkList(LinkList L, int x) {
    LNode *p = L->next;
    while (p != NULL && p->data != x) {
        p = p->next;
    }
    return p;
}

//���루ǰ���㣩����ͷ��㣩��ʧ�ܷ���0���ɹ�����1��
int Insert_LinkList(LinkList L, int i, int x) {
    LNode *p, *s;
    p = Get_LinkList(L, i - 1);    //��ȡ��i-1�����
    if (p == NULL) {
        printf("����i����!\n");
        return 0;
    } else {
        s = (LNode *) malloc(sizeof(LNode));    //���롢��װ���
        if (s == NULL) {
            printf("�����ڴ�ռ�ʧ�ܣ�");
            return 0;
        }
        s->data = x;
        s->next = p->next;
        p->next = s;
        return 1;
    }

}

//ɾ�����
int Delete_LinkList(LinkList L, int i) {
    LinkList p, s;
    p = Get_LinkList(L, i - 1);    //��ȡ��i-1���ڵ�
    if (p == NULL) {
        printf("��i-1����㲻����\n");
        return -1;
    } else if (p->next == NULL) {
        printf("��i����㲻����");
        return 0;
    } else {
        s = p->next;
        p->next = s->next;
        free(s);    //�ͷ�*s;
        return 1;
    }
}

//��������
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
    printf("Button 1 ---> Create_LinkList()����������(��ͷ���,��β����)\n");
    printf("Button 2 ---> Length_LinkList(L)��ȡ������\n");
    printf("Button 3 ---> Get_LinkList(L,i)����Ų���\n");
    printf("Button 4 ---> Locate_LinkList(L,x)��ֵ����\n");
    printf("Button 5 ---> Insert_LinkList(L,i,number)������\n");
    printf("Button 6 ---> Delete_LinkList(L,i)ɾ�����\n");
    printf("Button 7 ---> Find(L)��������\n");
    printf("Button 8 ---> Exit the program�˳�����\n");
    printf("-----------------------------------\n");
}


int main() {
    list();
    while (true) {
        printf("Choose Button: ");
        int n;
        int flag = 1;
        int length, i, number, item;//item����Insert�����Deteleɾ���ķ�������
        LNode *p;
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("If you enter '-1',the list is created\n");            //������-1�����ʾ����Ԫ�ش������
                L = Create_LinkList2();
                printf("-----------------------------------\n");
                break;

            case 2:
                length = Length_LinkList1(L);
                printf("The Singly Link List length is: %d\n", length);        //������ĳ���Ϊ
                printf("-----------------------------------\n");
                break;
            case 3:
                printf("Please enter you want to find serial number-->i:  ");//������������ҵ����
                scanf("%d", &i);
                p = Get_LinkList(L, i);
                if (p == NULL) {
                    printf("Sorry!Wrong!\n-----------------------------------\n");            //��i��λ��ΪNULL������
                } else {
                    printf("Successsful!The Node data is:%d\n-----------------------------------\n",
                           p->data);//��ΪNULL�����ҳɹ�������ý��������
                }
                break;
            case 4:
                printf("Please enter you want to find number:  ");
                scanf("%d", &number);
                p = Locate_LinkList(L, number);
                if (p == NULL)
                    printf("Sorry!Wrong!\n-----------------------------------\n");            //��i��λ��ΪNULL������
                else
                    printf("Successsful!The Node data is:%d\n-----------------------------------\n",
                           p->data);//��ΪNULL�����ҳɹ�������ý��������
                break;

            case 5:                            //������
                printf("Please enter i and number:  ");
                scanf("%d%d", &i, &number);
                item = Insert_LinkList(L, i, number);
                if (item == 0)
                    printf("Insert failed-----------------------------------\n");
                else
                    printf("Insert successful-----------------------------------\n");
                break;

            case 6:                                    //ɾ�����
                printf("Please enter i:  ");
                scanf("%d", &i);
                item = Delete_LinkList(L, i);
                if (item == 0 || item == -1)
                    printf("Delete failed-----------------------------------\n");
                else
                    printf("Delete successful-----------------------------------\n");
                break;

            case 7:
                printf("Traverse Singly Linked List:\n");        //�����õ�����
                Find(L);
                printf("-----------------------------------\n");
                break;

            case 8:
                printf("Exit the program successful!\n");
                flag = -1;
                break;

            default:
                printf("Sorry��You can't do that!\n");
                flag = -1;
                break;
        }
        if (flag == -1)
            break;
    }

}
