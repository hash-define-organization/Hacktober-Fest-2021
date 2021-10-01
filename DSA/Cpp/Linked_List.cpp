                /* C++ Program To Implement Linked List*/

//Header Files
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class Node  //Parent class (main)
{
public:
    int VM;
    Node* next;
};

class PRO:public Node  //Inherited class
{
 
    Node *Pehla,*Aakhri;
public:
    PRO()
    {
        Pehla=NULL;
        Aakhri=NULL;
    }
    //Different Functions declarations for various Operations 
    void show();
    void search();
    void create();
    void insert();
    void remove();
};
void PRO::insert() //To insert elements
{
    int hi=1,n,pos,ch;
    Node *erly,*cur;
    erly=NULL;
    cur=Pehla;
    Node *temp=new Node;
    cout<<"\nEnter an Element to insert in exsisting LL:";
    cin>>n;
    temp->VM=n;
    temp->next=NULL;
    // Switch case for different insertion method
    cout<<"\nINSERT AS THE\n1:FIRS-TNODE\n2:LAST-NODE\n3:AT A SPECIFIC LOCATION";
    cout<<"\nEnter Your Choice from above list:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        temp->next=Pehla;
        Pehla=temp;
        break;
    case 2:
        Aakhri->next=temp;
        Aakhri=temp;
        break;
    case 3:
        cout<<"\nEnter the Position where you want to insert: ";
        cin>>pos;
        while(hi!=pos)
        {
            erly=cur;
            cur=cur->next;
            hi++;
        }
        if(hi==pos)
        {
            erly->next=temp;
            temp->next=cur;
        }
        else
            cout<<"\nFailed to Insert";
        break;
 
    }
}
void PRO::create()  //For creating new LL
{
    Node *temp;
    temp=new Node;
    int n;
    cout<<"\nEnter an Element to insert in the LL:";
    cin>>n;
    temp->VM=n;
    temp->next=NULL;
    if(Pehla==NULL)
    {
        Pehla=temp;
        Aakhri=Pehla;
    }
 
    else
    {
        Aakhri->next=temp;
        Aakhri=temp;
    }
}

void PRO::remove()  //To delete elements
{
    Node *erly=NULL,*cur=Pehla;
    int hi=1,pos,ch;
    cout<<"\nDELETE\n1:THE FIRST-NODE\n2:THE LAST NODE\n3:AT A SPECIFIC LOCATION";
       // Switch case for different deletion methods.
    cout<<"\nEnter Your Choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        if(Pehla!=NULL)
        {
            cout<<"\nDeleted Element is "<<Pehla->VM;
            Pehla=Pehla->next;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    case 2:
        while(cur!=Aakhri)
        {
            erly=cur;
            cur=cur->next;
        }
        if(cur==Aakhri)
        {
            cout<<"\nDeleted Element is: "<<cur->VM;
            erly->next=NULL;
            Aakhri=erly;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    case 3:
        cout<<"\nEnter the Position of Deletion:";
        cin>>pos;
        while(hi!=pos)
        {
            erly=cur;
            cur=cur->next;
            hi++;
        }
        if(hi==pos)
        {
            cout<<"\nDeleted Element is: "<<cur->VM;
            erly->next=cur->next;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    }
}
void PRO::search() //To search elements
{
    int v,pos=0;
    bool flag=false;
    if(Pehla==NULL)
    {
        cout<<"List is Empty";
        return;
    }
    cout<<"Enter the Value to be Searched:";
    cin>>v;
    Node *temp;
    temp=Pehla;
    while(temp!=NULL)
    {
        pos++;
        if(temp->VM==v)
        {
            flag=true;
            cout<<"Element "<<v<<"is at "<<pos<<" Position";
            return;
        }
        temp=temp->next;
    }
    if(!flag)
    {
        cout<<"Element "<<v<<" not Found in the List";
    }
}
void PRO::show()    //To display elements
{
    Node *temp=Pehla;
    if(temp==NULL)
    {
        cout<<"\nList is Empty";
    }
    while(temp!=NULL)
    {
        cout<<temp->VM;
        cout<<"-->";
        temp=temp->next;
    }
    cout<<"NULL";
}
int main()  //main function
{
    PRO l;
    int ch;
    while(1)
    {
        cout<<"\n!!** MENU  CARD **!!";
        cout<<"\n1:CREATE\n2:INSERT\n3:DISPLAY\n4:SEARCH\n5:DELETE\n6:EXIT\n";
        cout<<"\nEnter Your Choice:";
        cin>>ch;
        switch(ch)  //To create Menu
        {
        case 1:
            l.create();
            break;
        case 2:
            l.insert();
            break;
        case 3:
            l.show();
            break;
        case 4:
            l.search();
            break;
        case 5:
            l.remove();
            break;
        case 6:
            return 0;
        }
    }
    return 0;
}