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

sn *insertAfterNode(sn *head, int data, int ref)
{
    sn *newNode = malloc(sizeof(sn));
    newNode->data = data;
    newNode->next = NULL;

    sn *temp = head;
    while (temp->data != ref)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

sn *insertBeforeNode(sn *head, int data, int ref)
{
    sn *newNode = malloc(sizeof(sn));
    newNode->data = data;
    newNode->next = NULL;

    if (head->data == ref)
    {
        newNode->next = head;
        return newNode;
    }

    sn *temp = head;
    while (temp->next->data != ref)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

sn *insertAtPosition(sn *head, int data, int pos)
{
    sn *newNode = malloc(sizeof(sn));
    newNode->data = data;
    newNode->next = NULL;

    if (pos == 1)
    {
        newNode->next = head;
        return newNode;
    }

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
    while (temp->data != key && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
        return 0;
    else
        return count;
}

int returnParticularNode(sn *head, int pos)
{
    if (pos == 1)
    {
        return head->data;
    }

    int count = 1;
    sn *temp = head;
    while (count != pos && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if(temp != NULL){
        return temp->data;
    }else{
        printf("Invalid Position!\n");
        return -1;
    }
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

    sn *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;

    return head;
}

sn *deleteAfterNode(sn *head, int ref)
{
    sn *temp = head;
    while (temp != NULL && temp->data != ref)
    {
        temp = temp->next;
    }
    
    if ( temp != NULL && temp->next != NULL)
    {
        sn *toDel = temp->next;
        temp->next = toDel->next;
        free(toDel);
    }

    return head;
}

sn *deleteBeforeNode(sn *head, int ref)
{
    if(head->data == ref){
        return head;
    }else if(head->next->data == ref){
        sn *toDel = head;
        head = toDel->next;
        free(toDel);
        return head;
    }

    sn *temp = head;
    while (temp->next->next != NULL && temp->next->next->data != ref)
    {
        temp = temp->next;
    }

    if (temp->next->next != NULL)
    {
        sn *toDel = temp->next;
        temp->next = toDel->next;
        free(toDel);
    }

    return head;
}

sn *deleteParticularNode(sn *head, int ref)
{
    if(head->data == ref){
        sn *toDel = head;
        head = toDel->next;
        free(toDel);
        return head;
    }

    sn *temp = head;
    while (temp->next != NULL && temp->next->data != ref)
    {
        temp = temp->next;
    }
    
    if (temp->next != NULL)
    {
        sn *toDel = temp->next;
        temp->next = toDel->next;
        free(toDel);
    }

    return head;
}

sn* deleteAtPos(sn *head, int pos)
{
    if (pos == 1)
    {
        sn *toDel = head;
        head = toDel->next;
        free(toDel);
        return head;
    }

    int count = 1;
    sn *temp = head;
    while (count != pos-1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if(temp != NULL && temp->next != NULL){
        sn *toDel = temp->next;
        temp->next = toDel->next;
        free(toDel);
        return head;
    }else{
        printf("Invalid Position!\n");
        return head;
    }
}

void printLinkedList(sn head)
{
    while (head.next != NULL)
    {
        printf("%d -> ", head.data);
        head = *head.next;
    }
    printf("%d -> ", head.data); // Printing the last node.
    printf("END\n");
}

int main()
{

    sn *head = NULL;
    head = insertionAtBegining(head, 2);
    head = insertionAtBegining(head, 1);
    head = insertionAtEnd(head, 3);
    head = insertionAtEnd(head, 4);
    head = insertAfterNode(head, 5, 3);
    head = insertBeforeNode(head, 6, 2);
    head = insertAtPosition(head, 7, 6);
    printLinkedList(*head);

    head = deleteAtBegining(head);
    head = deleteAtEnd(head);
    head = deleteAfterNode(head,6);
    head = deleteBeforeNode(head, 7);
    head = deleteParticularNode(head, 3);
    head = deleteAtPos(head, 5);

    printLinkedList(*head);

    // // Search A Element
    // int ans = searchList(head,7);
    // if(ans){
    //     printf("%d is present at %dth position.\n",7,ans);
    // }else{
    //     printf("%d is not present in list.\n",7);
    // }

    // printf("At %dth position the data is %d.\n",5,returnParticularNode(head,5));

    // Free Up Memory.
    while (head != NULL)
    {
        sn *toDel = head;
        head = head->next;
        free(toDel);
    }

    return 0;
}