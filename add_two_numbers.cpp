#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(): data(0), next(nullptr){}
//    Node(int x): data(x), next(nullptr){}
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printNode(Node* root){
    while(root !=NULL){
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}
void push(Node** head_ref, int x){
    Node *new_node = new Node();
    new_node->data = x;
    //new_node->next = NULL;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void append(Node** head_ref, int x){
    Node* new_node = new Node();
    new_node->data = x;
    new_node->next = NULL;
    Node* last = *head_ref;
    while (last->next!=NULL){
        last = last->next;
    }
    last->next = new_node;
}
void insert_after(Node* prev_node, int x){
    if (prev_node ==NULL){
        return;
    }
    Node* new_node = new Node();
    new_node->data = x;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
  
}
Node* merge_list(Node* l1, Node* l2){
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    Node res;
    Node* cur = &res;
    while( l1!=NULL && l2!=NULL){
        if(l1->data < l2->data){
            cur->next = l1;
            l1 = l1->next;
        }
        else{
            cur->next = l2;
            l2= l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1: l2;
    return res.next;
}

class Solution {
public:
    Node* addTwoNumbers(Node* a, Node* b) {
        int carry = 0;
        Node *result = nullptr, *temp = nullptr, *prev = nullptr;
        while(a or b){
            int sum = carry + (a ? a->data : 0) + (b ? b->data : 0);
            carry = sum >= 10;
            sum %= 10;
            temp = new Node(sum);
            if(!prev) result = temp;
            else prev->next = temp;
            prev = temp;
            a = a ? a->next : nullptr;
            b = b ? b->next : nullptr;
        }
        if(carry) temp->next = new Node(carry);
        return result;
    }
};

int main(){
    Node *node = new Node();
    node->data = 4;
//    push(&node, 2);
    append(&node, 5);
    append(&node, 6);
//    insert_after(node, 4);

    Node *node2 = new Node();
    node2->data = 7;
    append(&node2, 8);
    append(&node2, 9);
    printNode(node);
    printNode(node2);
    Solution s;
    
    auto res = s.addTwoNumbers(node, node2);
   
    printNode(res);

    
}
