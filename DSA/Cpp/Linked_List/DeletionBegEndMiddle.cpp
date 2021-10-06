#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
void linkedlisttravesal(struct Node *ptr)
{
    while (ptr != NULL)
    {                                                //yeh maine traversal.cpp se seedha
                                                     //taepa hai nvm
        cout << ptr->data;
        ptr = ptr->next;
    }
}

struct Node* deleteFirst( struct Node *head){
    struct Node *ptr=head;
    head= head->next;
    free(ptr);
    return head;
};

struct Node * deleteAtIndex(struct Node*head,int index){
  struct Node *p=head;
  
  int i=0;
  while(i<index-1){
      p=p->next;
      
      i++;
  } 
 struct Node*q=p->next;
  p->next=q->next;
  free(q);
  return head;

};

struct Node * deleteAtLast(struct Node*head){
  struct Node *p=head;
   struct Node*q=head->next;
  
  while(q->next!=NULL){
      p=p->next;
      q=q->next;
      
  } 
  p->next=NULL;
  free(q);
  return head;
}


struct Node * deleteAtCertainIndex(struct Node*head,int value){
  struct Node *p=head;
  struct Node *q=head->next;
  
  
  while(q->data!=value&&q->next!=NULL){
      p=p->next;
      q=q->next;
     
  } 
if(q->data==value){
    p->next=q->next;
    free(q);
}
return head;
};



int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //linking first and second nodes
    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 74;
    third->next = fourth;


    fourth->data = 33;
    fourth->next = NULL;

    cout<<"Linked list before deletion"<<endl;
    linkedlisttravesal(head);
    cout<<endl;
    

    //head= deleteFirst(head);
    //head=deleteAtIndex(head, 2);
   //head=deleteAtLast(head);
   head=deleteAtCertainIndex(head,74);
    cout<<"Linked list after deletion"<<endl;
    linkedlisttravesal(head);
    
}