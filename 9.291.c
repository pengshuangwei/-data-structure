#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
    int number;
    struct link* next;
}LINK;
typedef struct List {
    int data[100];
    int length;
}List;
struct link* AppendNode(struct link* head);//添加节点
void DisplayNode(struct link* head);//展示数据
void DeleteNode(struct link* head);//释放空间
struct link* Deletecertain(struct link* head, int x);//删除某指定元素
void Delete(struct link* head, struct link* p);//删除指定位置元素
struct link* Deleteagain(struct link* head);//删除重复元素
void Merge(List L1, List L2,List L3);//有序线性表的归并算法
void Insert(List L4, int x);//插入x
void Shiftleft(List L5, int p);//将L5中的元素循环左移p个单位