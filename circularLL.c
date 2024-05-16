#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} sn;

sn *insertionAtBegining(sn *head, int data)
{
    sn *newNode = malloc(sizeof(sn));
    newNode->data = data;
    newNode->next = newNode;

    if (head == NULL)
    {
        return newNode;
    }

    sn *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;

    return newNode;
}

sn *insertionAtEnd(sn *head, int data)
{
    sn *newNode = malloc(sizeof(sn));
    newNode->data = data;
    newNode->next = newNode;

    if (head == NULL)
    {
        return newNode;
    }

    sn *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;

    return head;
}

sn *insertAtPosition(sn *head, int data, int pos)
{

    if (pos == 1)
    {
        return insertionAtBegining(head,data);
    }

    sn *newNode = malloc(sizeof(sn));
    newNode->data = data;
    newNode->next = NULL;

    int count = 1;
    sn *temp = head;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int searchList(sn *head, int key)
{
    int count = 1;
    sn *temp = head;
    while (temp->data != key && (count == 1 || temp != head))
    {
        temp = temp->next;
        count++;
    }

    if (temp == head && temp->data != key)
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
    if(head->next == head){
        free(head);
        return NULL;
    }

    sn *newHead = head->next;
    sn *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newHead;
    free(head);
    return newHead;
}

sn *deleteAtEnd(sn *head)
{
    if (head == NULL)
    {
        return head;
    }
    if(head->next == head){
        free(head);
        return NULL;
    }

    sn *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = head;

    return head;
}

sn *deleteParticularNode(sn *head, int ref)
{
    if(head->next == head && head->data == ref){
        free(head);
        return NULL;
    }

    sn *temp = head;
    while (temp->next != head && temp->next->data != ref)
    {
        temp = temp->next;
    }

    if (temp->next != head)
    {
        sn *toDel = temp->next;
        temp->next = toDel->next;
        free(toDel);
    }

    return head;
}


sn *deleteAtPos(sn *head, int pos)
{
    if (pos == 1)
    {
        return deleteAtBegining(head);
    }

    int count = 1;
    sn *temp = head;
    while (count != pos - 1 && temp != head)
    {
        temp = temp->next;
        count++;
    }

    if (temp != head && temp->next != head)
    {
        sn *toDel = temp->next;
        temp->next = toDel->next;
        free(toDel);
        return head;
    }
    else
    {
        printf("Invalid Position!\n");
        return head;
    }
}

void printLinkedList(sn *head)
{
    if (head == NULL)
    {
        printf("Empty List.\n");
        return;
    }

    sn* temp = head;
    while (temp->next != head)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> ", temp->data); // Printing the last node.
    printf("%d -> .....\n",temp->next->data);
}

int main()
{

    sn *head = NULL;
    printf("Initially : ");
    printLinkedList(head);
    head = insertionAtBegining(head, 4);
    head = insertionAtBegining(head, 3);
    head = insertionAtBegining(head, 2);
    head = insertionAtBegining(head, 1);
    printf("After inserting 4,3,2,1 at begining : ");
    printLinkedList(head);
    head = insertionAtEnd(head, 5);
    head = insertionAtEnd(head, 6);
    printf("After inserting 5,6 at end : ");
    printLinkedList(head);
    head = insertAtPosition(head, 7, 5);
    printf("After inserting 7 at 3th position : ");
    printLinkedList(head);

    // // Search A Element
    printf("Searching 5 in the list : ");
    int ans = searchList(head,5);
    if(ans){
        printf("%d is present at %dth position.\n",5,ans);
    }else{
        printf("%d is not present in list.\n",5);
    }

    head = deleteAtBegining(head);
    head = deleteAtEnd(head);
    printf("After deleting element at begining and end : ");
    printLinkedList(head);

    head = deleteParticularNode(head, 3);
    printf("After deleting element 3: ");
    printLinkedList(head);

    printf("After deleting 5th node : ");
    head = deleteAtPos(head, 5);
    printLinkedList(head);

    // Free Up Memory.
    sn* temp = head;
    while (temp != head)
    {
        sn *toDel = temp;
        temp = temp->next;
        free(toDel);
    }

    return 0;
}