#include "9.291.c"

int main(int argc, const char* argv[]) {
    // insert code here...
    char c;
    int x;
    LINK* head = NULL;
    printf("Do you want to append a new node?\n");
    scanf_s(" %c", &c,1);
    while (c == 'y' || c == 'Y')
    {
        head = AppendNode(head);
        DisplayNode(head);
        printf("Do you want to append a new node?\n");
        scanf_s(" %c", &c,1);
    }
    printf("Do you want to delete a certain number?");
    scanf_s(" %c", &c,1);
    if (c == 'y' || c == 'Y')
    {
        printf("Input the number:");
        scanf_s("%d", &x);
        head = Deletecertain(head, x);
        DisplayNode(head);
    }
    printf("Do you want to delete copycode?\n");
    scanf_s(" %c", &c,1);
    if (c == 'y' || c == 'Y')
    {
        head = Deleteagain(head);
        DisplayNode(head);
    }
    DeleteNode(head);
    return 0;
}
struct link* AppendNode(struct link* head)
{
    LINK* p = NULL, * pr = head;
    int data;
    p = (struct link*)malloc(sizeof(struct link));
    if (p == NULL)
    {
        printf("No enough memory to allocate!\n");
        exit(0);
    }
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        while (pr->next != NULL)
        {
            pr = pr->next;
        }
        pr->next = p;
    }
    printf("Input node data:");
    scanf_s("%d", &data);
    p->number = data;
    p->next = NULL;
    return head;
}
void DisplayNode(struct link* head)
{
    struct link* p = head;
    int j = 1;
    while (p != NULL)
    {
        printf("%5d%10d\n", j, p->number);
        p = p->next;
        j++;
    }
}
void DeleteNode(struct link* head)
{
    LINK* p = head, * pr = NULL;
    while (p != NULL)
    {
        pr = p;
        p = p->next;
        free(pr);
    }
}
struct link* Deletecertain(struct link* head, int x)
{
    struct link* p = head, * pr = head;
    if (head == NULL)
    {
        printf("Linked Table is empty!\n");
        return head;
    }
    while (x != p->number && p->next != NULL)
    {
        pr = p;
        p = p->next;
    }
    if (x == p->number)
    {
        if (p == head)
        {
            head = p->next;
        }
        else {
            pr->next = p->next;
        }
        free(p);
    }
    else {
        printf("This node has not been found!");
    }
    return head;
}
void Delete(struct link* head, struct link* p)
{
    LINK* pr = NULL, * pl = p;
    pr = head;
    if (pl == head)
    {
        head = pr->next;
        free(pl);
        exit(1);
    }
    while (pr->next != pl)
    {
        pr = pr->next;
    }
    pr->next = pl->next;
    free(pl);

}
struct link* Deleteagain(struct link* head)
{
    struct link* p = head, * pr = head, * pl = NULL;
    pr = pr->next;
    while (p != NULL)
    {
        while (pr != NULL)
        {
            if (p->number == pr->number)
            {
                pl = pr->next;
                Delete(head, pr);
                pr = pl;
                pl = NULL;
            }
            else {
                pr = pr->next;
            }
        }
        p = p->next;
        if (p != NULL)
        {
            pr = p->next;
        }
    }
    return head;
}
