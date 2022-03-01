#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void deleteFirst(node **head)
{
    node *temp = *head;
    (*head) = temp->next;
}

void deleteLast(node **head)
{
    node *temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    temp->next = NULL;
}

void deleteAfter(node *prevNode)
{
    prevNode->next = prevNode->next->next;
}
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
    node *second = new node();
    node *third = new node();
    node *forth = new node();
    node *fifth = new node();
    node *sixth = new node();
    node *seventh = new node();
    node *mid = new node();
	node *last = new node();
    
    first->data = 11;
    first->next = second;
    first->next->next = third;
    first->next->next->next = mid;
    mid->next = fifth;
    mid->next->next = sixth;
    mid->next->next->next = last;
    
    second->data = 12;
    third->data = 13;
    mid->data = 14;
    fifth->data = 17;
    sixth->data = 19;
    last->data = 25;
    last->next = NULL;

    (*head) = first;
    printList(first);
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
    
    cout << "Deletion  : ";
    deleteFirst(&head);
    deleteLast(&head);
    deleteAfter(head->next);
    printList(head);
    int key = 14;
    if (searchNode(&head, key))
        cout << key << " is found";
    else
        cout << key << " is not found";
    return 0;
}
