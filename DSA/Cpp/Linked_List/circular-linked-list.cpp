#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void delete_value(Node **head, int datum)
{
    Node *temp = *head;
    if (temp == NULL)
    {
        cout << "NULL LIST" << endl;
        return;
    }
    else
    {
        while (temp->next != *head && temp->next->data != datum)
        {
            temp = temp->next;
        }
        if (temp->next == *head)
        {
            if (temp->next->data == datum)
            {
                temp->next = temp->next->next;
                *head = temp->next->next;
            }
            else
            {
                cout << "Value does not exist" << endl;
                return;
            }
        }
        else
        {
            temp->next = temp->next->next;
        }
    }
}
void add(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;

    Node *temp = *head;
    if (*head == NULL)
    {
        *head = new_node;
        new_node->next = new_node;
        return;
    }
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = *head;
}
void push(Node **head, int data)
{
    Node *new_node = new Node();
    Node *temp = *head;

    new_node->data = data;

    if (*head == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
        return;
    }
    else
    {
        while (temp && temp->next != (*head))
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *head;
        *head = new_node;
    }
}

void delete_from_end(Node **head)
{
    Node *temp = *head;
    if (temp == NULL)
    {
        cout << "NULL LIST" << endl;
        return;
    }
    else
    {
        while (temp->next->next != *head)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}

void display(Node *head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        if (head == temp)
        {
            cout << "head : ";
        }
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data;
}

int main()
{
    Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head,5);
    add(&head, 4);
    display(head);
    delete_from_end(&head);
    delete_value(&head, 5);
    display(head);
}