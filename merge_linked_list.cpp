#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(): data(0), next(nullptr){}
    Node(int x): data(x), next(nullptr){}
};

void push(Node** head_ref, int x){
    Node* node = new Node();
    node->data = x;
    node->next = (*head_ref);
    (*head_ref) = node;
}
void print_ll(Node* root){
    while(root !=NULL){
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}
void append(Node** head_ref, int x){
    Node *new_node = new Node();
    new_node->data = x;
    new_node->next = NULL;
    Node* last = *head_ref;
    while (last->next !=NULL){
        last = last->next;
    }
    last->next = new_node;

}
Node * merge_link(Node *l1, Node *l2){
//speed up
        if(NULL == l1) return l2;
        if(NULL == l2) return l1;
        Node res(0);
        Node *curRes = &res;
        while(l1 != NULL && l2 != NULL){
            if(l1->data < l2->data)
            {
                curRes->next = l1;
                l1 = l1->next;
            }else
            {
                curRes->next = l2;
                l2 = l2->next;
            }
            curRes = curRes->next;
        }
//        curRes->next = l1 ? l1 : l2;// if l1 ==true (has value), then curRes->next = l1, otherwise, curRes->next = l2
        if (l1){
            curRes->next = l1;
        }
        else{
            curRes->next = l2;
        }
        return res.next;//cuz first is the initial 0, so skip it and return from the next.
}



int main(){
    Node *link1 = new Node;
    link1->data = 1;
    Node *link2 = new Node;
    link2->data = 7;
    append(&link1, 2);
    append(&link1, 3);
    append(&link1, 4);

    append(&link2, 8);
    append(&link2, 9);
    append(&link2, 10);
    Node *ret = merge_link(link1, link2);
    print_ll(ret);

}
