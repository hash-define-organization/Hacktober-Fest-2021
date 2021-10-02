#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertin(Node **head, int pos, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    Node *temp = *head;
    if (pos == 0)
    {
        cout << "Enter a valid position for insertion" << endl;
        return;
    }
    if (*head == NULL)
    {
        cout << "Empty linked list" << endl;
        return;
    }

    while (temp->next != NULL)
    {
        if (pos == 0)
        {
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        else
        {
            temp = temp->next;
            pos--;
        }
    }
}

void push(Node **head, int new_data) //add node to top
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head);
    *head = new_node;
}

void append(Node **head, int last_data) //add node to end
{
    Node *current = *head;
    Node *new_node = new Node();
    new_node->data = last_data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    return;
}
bool Search(Node *head, int x)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == x)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << " " << head->data << endl;
        head = head->next;
    }
}
int main()
{
    Node *head = NULL;
    int n;
    cout << "Enter size of linked list" << endl;
    cin >> n;
    cout << "Enter elements of linked list " << endl;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        append(&head, k);
    }
    push(&head, 35);
    insertin(&head, 4, 99);
    cout << " \n";
    display(head);
    cout << endl;
    cout << head->data;
}