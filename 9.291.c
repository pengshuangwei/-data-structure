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
struct link* AppendNode(struct link* head);//��ӽڵ�
void DisplayNode(struct link* head);//չʾ����
void DeleteNode(struct link* head);//�ͷſռ�
struct link* Deletecertain(struct link* head, int x);//ɾ��ĳָ��Ԫ��
void Delete(struct link* head, struct link* p);//ɾ��ָ��λ��Ԫ��
struct link* Deleteagain(struct link* head);//ɾ���ظ�Ԫ��
void Merge(List L1, List L2,List L3);//�������Ա�Ĺ鲢�㷨
void Insert(List L4, int x);//����x
void Shiftleft(List L5, int p);//��L5�е�Ԫ��ѭ������p����λ