#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} sn;

sn *insertionAtBegining(sn *head, int n)
{
    sn *newNode = malloc(sizeof(sn));
    newNode->data = n;
    newNode->next = head;
    return newNode;
}

sn *insertionAtEnd(sn *head, int data)
{
    sn *newNode = malloc(sizeof(sn));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    sn *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

int searchList(sn *head, int key)
{
    int count = 1;
    sn *temp = head;
    while ( temp != NULL && temp->data != key)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
        return 0;
    else
        return count;
}

sn *deleteAtBegining(sn *head)
{
    if (head == NULL)
    {
        return head;
    }

    sn *newHead = head->next;
    free(head);
    return newHead;
}
sn *deleteAtEnd(sn *head)
{
    if (head == NULL)
    {
        return head;
    }

    if (head->next == NULL) // Only one element in the list
    {
        free(head);
        return NULL;
    }

    sn *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;

    return head;
}
void printLinkedList(sn *head)
{
    if (head == NULL)
    {
        printf("Empty List.\n");
        return;
    }
    while (head->next != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("%d -> ", head->data); // Printing the last node.
    printf("END\n");
}

int main()
{

    sn *head = NULL;
    printf("Initially : ");
    printLinkedList(head);
    head = insertionAtBegining(head, 2);
    head = insertionAtBegining(head, 1);
    printf("After inserting 2,1 at begining : ");
    printLinkedList(head);
    head = insertionAtEnd(head, 3);
    head = insertionAtEnd(head, 4);
    printf("After inserting 3,4 at end : ");
    printLinkedList(head);
    printf("Searching 7 in the list : ");
    int ans = searchList(head,7);
    if(ans){
        printf("%d is present at %dth position.\n",7,ans);
    }else{
        printf("%d is not present in list.\n",7);
    }
    head = deleteAtBegining(head);
    head = deleteAtEnd(head);
    printf("After deleting element at begining and end : ");
    printLinkedList(head);
   while (head != NULL)
    {
        sn *toDel = head;
        head = head->next;
        free(toDel);
    }

    return 0;
}