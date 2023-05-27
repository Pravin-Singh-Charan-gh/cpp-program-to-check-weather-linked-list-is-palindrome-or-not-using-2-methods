#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
};
void print(Node**head){
    Node*temp=*head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
void append(Node**head,int data){
    Node*newn=new Node();
    newn->data=data;
    newn->next=NULL;
    
    if(*head==NULL){
        *head=newn;
        return;
    }
    
    Node*temp=*head;
    while(temp->next)
    temp=temp->next;
    
    temp->next=newn;
}
bool check_palindrome(Node**head){
    stack<int>st;
    Node*temp=*head;
    
    while(temp){
        st.push(temp->data);
        temp=temp->next;
    }
    int data;
    temp=*head;
    while(temp){
        data=st.top();
        if(temp->data != data)
        return false;
        st.pop();
        temp=temp->next;
    }
    return true;
}

void reverseLL(Node**head){
    Node*curr=*head;
    Node*prev=NULL;
    Node*next=NULL;
    
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
}
Node* getmid(Node**head){
    Node*slow=*head, *fast=(*head)->next;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
bool isPalindrome(Node**head){
    if(*head==NULL || (*head)->next==NULL)
    return true;
    Node*mid=getmid(head);
    
    reverseLL(&(mid->next));
    Node*first_half=*head;
    Node*second_half=mid->next;
    while(second_half){
        if(first_half->data != second_half->data)
        return false;
        
        first_half=first_half->next;
        second_half=second_half->next;
    }
    reverseLL(&(mid->next));
    return true;
}
    
int main(){
    Node*head=NULL;
    for(int i=0;i<=9;i++)
    append(&head,i);
    for(int i=9;i>=0;i--)
    append(&head,i);
    
    print(&head);
    
    cout<<"Using isPalindrome function :"<<isPalindrome(&head)<<endl;
    cout<<"Using check_palindrome function : "<<check_palindrome(&head)<<endl;
    return 0;
}
