#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left, *right;
};

struct node *list = NULL;

void insertFront(int val)
{
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->info = val;
    ins->left = NULL;
    ins->right = list;
    if (list != NULL)
        list->left = ins;
    list = ins;
}

void insertEnd(int val)
{
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->info = val;
    ins->right = NULL;
    if (list == NULL)
    {
        ins->left = NULL;
        list = ins;
        return;
    }
    struct node *temp = list;
    while (temp->right != NULL)
        temp = temp->right;
    temp->right = ins;
    ins->left = temp;
}

void insertMiddle(struct node *pred, int val)
{
    if (pred == NULL)
    {
        insertFront(val);
        return;
    }
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->info = val;
    ins->right = pred->right;
    pred->right = ins;
    ins->left = pred;
    if (ins->right != NULL)
        ins->right->left = ins;
}

void deleteFront()
{
    if (list == NULL)
        return;
    struct node *temp = list;
    list = list->right;
    if (list != NULL)
        list->left = NULL;
    free(temp);
}

void deleteEnd()
{
    if (list == NULL)
        return;
    struct node *temp = list;
    while (temp->right != NULL)
        temp = temp->right;
    if (temp->left != NULL)
        temp->left->right = NULL;
    else
        list = NULL;
    free(temp);
}

void deleteMiddle(struct node *del)
{
    if (del == NULL)
        return;
    if (del == list)
    {
        deleteFront();
        return;
    }
    if (del->right == NULL)
    {
        deleteEnd();
        return;
    }
    del->left->right = del->right;
    del->right->left = del->left;
    free(del);
}

void display()
{
    struct node *temp = list;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->right;
    }
    printf("\n");
}

int main()
{
    insertFront(20);
    insertEnd(55);
    insertFront(15);
    insertMiddle(list, 35); // Insert after first node
    printf("Doubly Linked List: ");
    display();
    deleteFront();
    printf("After deleting front: ");
    display();
    deleteEnd();
    printf("After deleting end: ");
    display();
    deleteMiddle(list->right); // Deleting middle node
    printf("After deleting middle node: ");
    display();
       getchar();
    getchar();
    return 0;
}