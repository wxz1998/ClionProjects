//
// Created by wxz18 on 2019/4/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 0
#define LIST_INIT_SIZE 50
// ����Ԫ������
typedef int MyElemType;
// ����˳�������
typedef struct {
    MyElemType *Data;
    int Length;
    int ListSize;
} SqList;

// ����һ���յ�˳���
int InitList(SqList *L) {
    L->Data = (MyElemType *) malloc(sizeof(MyElemType));
    if (!L->Data) return ERROR;
    L->Length = 0;
    L->ListSize = LIST_INIT_SIZE;
    return 1;
}

// ��ȡ˳���ָ��λ��(i)��Ԫ��
MyElemType GetListElem(SqList *L, int i) {
    if (i < 1 || i > L->Length)
        return ERROR;
    else
        return L->Data[i - 1];
}

// ��˳���ָ��λ��(i)����Ԫ��
int InsertListElem(SqList *L, int i, MyElemType e) {
    int k;
    if (i < 1 || i > L->Length + 1) return ERROR;
    if (L->Length >= L->ListSize) {
        L->Data = (MyElemType *) realloc(L->Data, (L->ListSize + 10) * sizeof(MyElemType));
        if (!L->Data) return ERROR;
        L->ListSize += 10;
    }

    for (k = L->Length - 1; k >= i - 1; k--)
        L->Data[k + 1] = L->Data[k];
    L->Data[i - 1] = e;
    L->Length++;
    return 1;
}

// ɾ��˳���ָ��λ��(i)��Ԫ��
int DeleteListElem(SqList *L, int i) {
    int k;
    // �ж�λ�úϷ���
    if (i < 1 || i > L->Length) return ERROR;
    // Ԫ��ǰ��1λ
    for (k = i; k <= L->Length; k++)
        L->Data[k - 1] = L->Data[k];
    // ˳����ȼ�1
    L->Length--;
    // ɾ���ɹ�
    return 1;
}
// �޸�˳����i��Ԫ��
int UpdateListElem(SqList *L, int i, MyElemType e)
{
    // �ж�λ�úϷ���
    if (i < 1 || i >L->Length) return ERROR;
    // �޸ĵ�i��Ԫ��ֵ
    L->Data[i-1] = e;
    // �޸ĳɹ�
    return 1;
}

int main() {
    int i, choice;
    MyElemType data, elem;
    int isRunning = 1;

    SqList *pl = (SqList *) malloc(sizeof(SqList));

    while (isRunning) {
        printf("**********˳����������**********\n");
        printf("1. �˳�˳����������\n");
        printf("2. ����һ���յ�˳���\n");
        printf("3. ��˳���ָ��λ�ò�������\n");
        printf("4. ɾ��˳���ָ��λ�õ�����\n");
        printf("5. �޸�(����)˳���ָ��λ�õ�����\n");
        printf("6. ��ѯ˳���ָ��λ�õ�����\n");
        printf("********************************\n");
        printf("\n�������蹦������1-8: ");
        scanf("%d", &choice);
        printf("\n��ѡ�����: %d\n", choice);

        switch (choice) {
            case 1:
                // �˳�˳����������
                isRunning = 0;
                break;
            case 2:
                // ����һ���յ�˳���
                if (InitList(pl))
                    printf("\n˳������ɹ���\n\n");
                else
                    printf("\n˳�����ʧ�ܣ�\n\n");
                system("pause");
                break;
            case 3:
                // ��˳���ָ��λ�ò�������
                printf("����i(��ָλ��),data(��λ��Ҫ���������)\n");
                printf("�����ʽΪ(%%d,%%d)\n");
                printf("i,data=");
                scanf("%d,%d", &i, &data);
                if (InsertListElem(pl, i, data))
                    printf("\n���ݲ���ɹ���\n\n");
                else
                    printf("\n���ݲ���ʧ�ܣ�\n\n");
                system("pause");
                break;
            case 4:
                // ɾ��˳���ָ��λ�õ�����
                printf("����i(ָ��ɾ����λ��)\n");
                printf("i=");
                scanf("%d", &i);
                if (DeleteListElem(pl, i))
                    printf("\n����ɾ���ɹ���\n\n");
                else
                    printf("\n����ɾ��ʧ�ܣ�\n\n");
                system("pause");
                break;
            case 5:
                // �޸�˳���ָ��λ�õ�����
                printf("����i(��ָλ��),data(��λ��Ҫ���µ�����)\n");
                printf("�����ʽΪ(%%d,%%d)\n");
                printf("i,data=");
                scanf("%d,%d", &i, &data);
                if (UpdateListElem(pl, i, data))
                    printf("\n���ݸ��³ɹ���\n\n");
                else
                    printf("\n���ݸ���ʧ�ܣ�\n\n");
                system("pause");
                break;
            case 6:
                // ��ѯ˳���ָ��λ�õ�����
                printf("����i(��ָλ��)\n");
                printf("i=");
                scanf("%d", &i);
                elem = GetListElem(pl, i);
                if (elem)
                    printf("L[%d]=%d\n\n", i, elem);
                else
                    printf("�����λ�ò��Ϸ���");
                system("pause");
                break;
        }
    }
    printf("\nллʹ��");
    return 0;
}
