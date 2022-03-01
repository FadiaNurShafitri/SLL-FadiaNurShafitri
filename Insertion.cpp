#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void printList(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void createList(node **head)
{
    node *first = new node();
    node *mid = new node();
    node *last = new node();

    first->data = 12;
    first->next = mid;
    mid->data = 20;
    mid->next = last;
    last->data = 35;
    last->next = NULL;

    (*head) = first;
    printList(first);
}

void insertFirst(node **head, int temp)
{
    node *newNode = new node();
    newNode->data = temp;
    newNode->next = (*head);
    (*head) = newNode;
}

void insertBefore(node **head, node *nextNode, int temp)
{
    node *current = *head;
    while (current->next->data != nextNode->data)
        current = current->next;
    node *newNode = new node();
    newNode->data = temp;
    newNode->next = current->next;
    current->next = newNode;
}

void insertAfter(node **head, node *prevNode, int temp)
{
    node *first = *head;
    if (prevNode == NULL)
        insertFirst(&first, temp);
    node *newNode = new node();
    newNode->data = temp;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertLast(node **head, int temp)
{
    node *newNode = new node();
    node *last = *head;
    newNode->data = temp;
    newNode->next = NULL;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
}

bool searchNode(node **head, int key)
{
    node *current = *head;
    while (current != NULL)
    {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

int main()
{
    node *head = NULL;
    createList(&head);
    cout << "Insertion : ";
    insertFirst(&head, 8);
    insertAfter(&head, head->next->next, 24);
    insertBefore(&head, head->next->next, 15);
    insertLast(&head, 40);
    printList(head);
    int key = 8;
    if (searchNode(&head, key))
        cout << key << " is found";
    else
        cout << key << " is not found";
    return 0;
}
