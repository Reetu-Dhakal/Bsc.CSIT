#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *list = NULL;

void insertBeginning(int val)
{
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->info = val;
    if (list == NULL)
    {
        ins->next = ins;
        list = ins;
    }
    else
    {
        struct node *temp = list;
        while (temp->next != list)
            temp = temp->next;
        temp->next = ins;
        ins->next = list;
        list = ins;
    }
}

void insertEnd(int val)

{
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->info = val;
    if (list == NULL)
    {
        ins->next = ins;
        list = ins;
    }
    else
    {
        struct node *temp = list;
        while (temp->next != list)
            temp = temp->next;
        temp->next = ins;
        ins->next = list;
    }
}

void insertPosition(int val, int pos)
{
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->info = val;
    if (pos == 1 || list == NULL)
    {
        insertBeginning(val);
        return;
    }
    struct node *temp = list;
    for (int i = 1; i < pos - 1 && temp->next != list; i++)
        temp = temp->next;
    ins->next = temp->next;
    temp->next = ins;
}

void display()
{
    if (list == NULL)
        return;
    struct node *temp = list;
    do
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    } while (temp != list);
    printf("\n");
}

int main()
{
    insertBeginning(10);
    insertEnd(19);
    insertPosition(6, 2);
    display();
       getchar();
    getchar();
    return 0;
}
