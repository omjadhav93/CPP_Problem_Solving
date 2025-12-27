#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} sn;

sn *createNode(sn *head, int n)
{
    sn *newNode = (sn *)malloc(sizeof(sn));
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

sn *insertionAtBegining(sn *head, int n)
{
    sn *newNode = createNode(head, n);

    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    return newNode;
}

sn *insertionAtEnd(sn *head, int n)
{
    sn *newNode = createNode(head, n);

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
    newNode->prev = temp;

    return head;
}

sn *insertAfterNode(sn *head, int data, int ref)
{
    sn *newNode = createNode(head, data);

    if (head == NULL)
    {
        printf("%d is not there in code!\n", ref);
        return head;
    }

    sn *temp = head;
    while (temp != NULL && temp->data != ref)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("%d is not there in code!\n", ref);
        return head;
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        return head;
    }
}

sn *insertBeforeNode(sn *head, int data, int ref)
{
    sn *newNode = createNode(head, data);

    if (head == NULL)
    {
        printf("%d is not there in code!\n", ref);
        return head;
    }

    if (head->data == ref)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    sn *temp = head;
    while (temp != NULL && temp->next->data != ref)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("%d is not there in code!\n", ref);
        return head;
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        return head;
    }
}

sn *insertAtPosition(sn *head, int data, int pos)
{
    sn *newNode = malloc(sizeof(sn));
    newNode->data = data;
    newNode->next = NULL;

    if (head != NULL && pos == 1)
    {
        newNode->next = head;
        return newNode;
    }

    int count = 1;
    sn *temp = head;
    while (temp != NULL && count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        printf("Invalid Position!\n");
        return head;
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        return head;
    }
}

int searchList(sn *head, int key)
{
    int count = 1;
    sn *temp = head;
    while (temp != NULL && temp->data != key)
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
    if (head != NULL && pos == 1)
    {
        return head->data;
    }

    int count = 1;
    sn *temp = head;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }

    if (temp != NULL)
    {
        return temp->data;
    }
    else
    {
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
    newHead->prev = NULL;
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


sn *deleteAfterNode(sn *head, int ref)
{
    sn *temp = head;
    while (temp != NULL && temp->data != ref)
    {
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL)
    {
        sn *toDel = temp->next;
        temp->next = toDel->next;
        toDel->next->prev = temp;
        free(toDel);
    }

    return head;
}

sn *deleteBeforeNode(sn *head, int ref)
{
    if( head == NULL || head->next == NULL){
        return head;
    }

    if (head->data == ref)
    {
        return head;
    }
    else if (head->next->data == ref)
    {
        sn *toDel = head;
        head = toDel->next;
        head->prev = NULL;
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
        toDel->next->prev = temp;
        free(toDel);
    }

    return head;
}


sn *deleteParticularNode(sn *head, int ref)
{
    if(head == NULL){
        return head;
    }

    if (head->data == ref)
    {
        sn *toDel = head;
        head = toDel->next;
        head->prev = NULL;
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
        toDel->next->prev = temp;
        free(toDel);
    }

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

sn *deleteAtPos(sn *head, int pos)
{
    if (head != NULL && pos == 1)
    {
        sn *toDel = head;
        head = toDel->next;
        free(toDel);
        return head;
    }

    int count = 1;
    sn *temp = head;
    while (temp != NULL && count != pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp != NULL && temp->next != NULL)
    {
        sn *toDel = temp->next;
        temp->next = toDel->next;
        toDel->next->prev = temp;
        free(toDel);
        return head;
    }
    else
    {
        printf("Invalid Position!\n");
        return head;
    }
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
    head = insertAfterNode(head, 5, 3);
    printf("After inserting 5 after 3 : ");
    printLinkedList(head);
    head = insertBeforeNode(head, 6, 2);
    printf("After inserting 6 before 2 : ");
    printLinkedList(head);
    head = insertAtPosition(head, 7, 6);
    printf("After inserting 7 at 6th position : ");
    printLinkedList(head);

    // // Search A Element
    printf("Searching 7 in the list : ");
    int ans = searchList(head,7);
    if(ans){
        printf("%d is present at %dth position.\n",7,ans);
    }else{
        printf("%d is not present in list.\n",7);
    }

    printf("Finding what is at 5th position : ");
    printf("%d.\n",returnParticularNode(head,5));

    head = deleteAtBegining(head);
    head = deleteAtEnd(head);
    printf("After deleting element at begining and end : ");
    printLinkedList(head);
    head = deleteAfterNode(head, 6);
    printf("After deleting element after 6: ");
    printLinkedList(head);
    head = deleteBeforeNode(head, 7);
    printf("After deleting element before 7: ");
    printLinkedList(head);
    head = deleteParticularNode(head, 3);
    printf("After deleting element 3: ");
    printLinkedList(head);
    head = deleteAtPos(head, 5);
    printf("After deleting 5th node : ");
    printLinkedList(head);


    // Free Up Memory.
    while (head != NULL)
    {
        sn *toDel = head;
        head = head->next;
        free(toDel);
    }

    return 0;
}