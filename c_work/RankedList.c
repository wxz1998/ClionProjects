//
// Created by wxz18 on 2019/4/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 0
#define LIST_INIT_SIZE 50
// 定义元素类型
typedef int MyElemType;
// 定义顺序表类型
typedef struct {
    MyElemType *Data;
    int Length;
    int ListSize;
} SqList;

// 创建一个空的顺序表
int InitList(SqList *L) {
    L->Data = (MyElemType *) malloc(sizeof(MyElemType));
    if (!L->Data) return ERROR;
    L->Length = 0;
    L->ListSize = LIST_INIT_SIZE;
    return 1;
}

// 获取顺序表指定位置(i)的元素
MyElemType GetListElem(SqList *L, int i) {
    if (i < 1 || i > L->Length)
        return ERROR;
    else
        return L->Data[i - 1];
}

// 在顺序表指定位置(i)插入元素
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

// 删除顺序表指定位置(i)的元素
int DeleteListElem(SqList *L, int i) {
    int k;
    // 判断位置合法性
    if (i < 1 || i > L->Length) return ERROR;
    // 元素前移1位
    for (k = i; k <= L->Length; k++)
        L->Data[k - 1] = L->Data[k];
    // 顺序表长度减1
    L->Length--;
    // 删除成功
    return 1;
}
// 修改顺序表第i个元素
int UpdateListElem(SqList *L, int i, MyElemType e)
{
    // 判断位置合法性
    if (i < 1 || i >L->Length) return ERROR;
    // 修改第i个元素值
    L->Data[i-1] = e;
    // 修改成功
    return 1;
}

int main() {
    int i, choice;
    MyElemType data, elem;
    int isRunning = 1;

    SqList *pl = (SqList *) malloc(sizeof(SqList));

    while (isRunning) {
        printf("**********顺序表基本操作**********\n");
        printf("1. 退出顺序表操作程序\n");
        printf("2. 创建一个空的顺序表\n");
        printf("3. 向顺序表指定位置插入数据\n");
        printf("4. 删除顺序表指定位置的数据\n");
        printf("5. 修改(更新)顺序表指定位置的数据\n");
        printf("6. 查询顺序表指定位置的数据\n");
        printf("********************************\n");
        printf("\n根据所需功能输入1-8: ");
        scanf("%d", &choice);
        printf("\n您选择的是: %d\n", choice);

        switch (choice) {
            case 1:
                // 退出顺序表操作程序
                isRunning = 0;
                break;
            case 2:
                // 创建一个空的顺序表
                if (InitList(pl))
                    printf("\n顺序表创建成功！\n\n");
                else
                    printf("\n顺序表创建失败！\n\n");
                system("pause");
                break;
            case 3:
                // 向顺序表指定位置插入数据
                printf("输入i(所指位置),data(该位置要插入的数据)\n");
                printf("输入格式为(%%d,%%d)\n");
                printf("i,data=");
                scanf("%d,%d", &i, &data);
                if (InsertListElem(pl, i, data))
                    printf("\n数据插入成功！\n\n");
                else
                    printf("\n数据插入失败！\n\n");
                system("pause");
                break;
            case 4:
                // 删除顺序表指定位置的数据
                printf("输入i(指定删除的位置)\n");
                printf("i=");
                scanf("%d", &i);
                if (DeleteListElem(pl, i))
                    printf("\n数据删除成功！\n\n");
                else
                    printf("\n数据删除失败！\n\n");
                system("pause");
                break;
            case 5:
                // 修改顺序表指定位置的数据
                printf("输入i(所指位置),data(该位置要更新的数据)\n");
                printf("输入格式为(%%d,%%d)\n");
                printf("i,data=");
                scanf("%d,%d", &i, &data);
                if (UpdateListElem(pl, i, data))
                    printf("\n数据更新成功！\n\n");
                else
                    printf("\n数据更新失败！\n\n");
                system("pause");
                break;
            case 6:
                // 查询顺序表指定位置的数据
                printf("输入i(所指位置)\n");
                printf("i=");
                scanf("%d", &i);
                elem = GetListElem(pl, i);
                if (elem)
                    printf("L[%d]=%d\n\n", i, elem);
                else
                    printf("输入的位置不合法！");
                system("pause");
                break;
        }
    }
    printf("\n谢谢使用");
    return 0;
}
