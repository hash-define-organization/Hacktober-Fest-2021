#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

void insert_after_value(Node **head, int datum, int after)
{
    Node *temp = *head;
    Node *new_node = new Node();

    new_node->data = datum;

    while (temp != NULL && temp->data != after)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Value does not exist in doubly linked list" << endl;
    }
    else
    {
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
    }
}

void push(Node **head, int datum)
{

    Node *new_node = new Node();
    new_node->data = datum;

    new_node->next = *head;
    new_node->prev = NULL;

    if ((*head) != NULL)
    {
        (*head)->prev = new_node;
    }

    (*head) = new_node;
}

void append(Node **head, int datum)
{
    Node *temp = *head;
    Node *new_node = new Node();
    new_node->data = datum;
    new_node->next = NULL;

    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void Node_delete(Node **head, int val)
{
    Node *temp = *head;
    while (temp != NULL && temp->data != val)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Node not found" << endl;
    }
    else
    {
        (temp->prev)->next = temp->next;
        (temp->next)->prev = temp->prev;
    }
}


void display(Node *head)
{
    Node *temp = new Node();
    temp = head;
    while (temp != NULL)
    {
        if (temp == head)
        {
            cout << "head:";
        }
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    push(&head, 7);
    push(&head, 8);
    append(&head, 6);
    insert_after_value(&head, 99, 7);
    display(head);
    Node_delete(&head,7);
    display(head);
}