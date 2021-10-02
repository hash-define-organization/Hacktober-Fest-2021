#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next,*prev;
};

void push(Node **head,int datum){
    Node *new_node=new Node();
    new_node->data=datum;

    if(*head==NULL){
        *head=new_node;
        new_node->next=new_node;
        new_node->prev=new_node;
    }else{
        new_node->next=*head;
        new_node->prev= (*head)->prev;
        (*head)->prev->next=new_node;
        *head=new_node;
    }
}


void add(Node **head,int datum){
    Node *new_node=new Node();
    new_node->data=datum;

    Node *temp=*head;

    while(temp->next!=*head){
        temp=temp->next;
    }

    new_node->next=temp->next;
    temp->next->prev=new_node;
    temp->next=new_node;
    new_node->prev=temp;

}

void delete_last(Node **head){
    Node* temp= *head;
    while(temp->next!=*head){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
}

void delete_top(Node **head){
    if(*head==NULL){
        cout<<"NULL list"<<endl;
        return;
    }else{
        (*head)->prev->next=(*head)->next;
        (*head)->next->prev=(*head)->prev;
        (*head)=(*head)->next;
    }
}

void display(Node* head){
    Node *temp=head;
    while(temp->next!=head){
        if(temp==head){
            cout<<"head : ";
        }
        cout<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}


int main(){
    Node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    add(&head,5);
    display(head);
    delete_last(&head);
    display(head);
    delete_top(&head);
    display(head);
}