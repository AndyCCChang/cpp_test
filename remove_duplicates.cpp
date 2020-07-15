#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node(int x){
        data=x;
        next = NULL;
    }
};

void print(Node *n){
    Node *temp = n;
    while (temp !=NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
}

Node* removeDup(Node *root);

int main(){



}

Node * removeDuplicates( Node *head) 
{
    Node *curr = head, *temp = NULL;
    while (curr != NULL){
        temp = curr;
        while (temp->next !=NULL){
            if (temp->next->data == curr->data){
                temp->next = temp->next->next;
            }
            else
            temp = temp->next;
        }
            curr = curr->next;
    }
    return head;    
    

 // your code goes here
}
