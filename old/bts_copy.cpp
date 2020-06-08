#include <iostream>

using namespace std;

struct Node
{
   int key;
   Node *left;
   Node *right;
   Node *parent;
};

// Helper function that allocates a new Node 
Node* newNode( int key )
{
   Node* n = new Node;
   n->key = key;
   n->left = nullptr;
   n->right = nullptr;
   n->parent = nullptr;

   return n;
}

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use 
Node *insert( Node *root, int key )
{
   // 1) If the tree is empty, return a new single Node
   if( root == nullptr )
      return newNode( key );

   Node *temp;

   // 2) Otherwise, recur down the tree
   if( key < root->key )
   {
      temp = insert( root->left, key );
      root->left = temp;
      temp->parent = root;
   } else
   {
      temp = insert( root->right, key );
      root->right = temp;
      temp->parent = root;
   }

   // Return the (unchanged) Node pointer
   return root;
}

// Return a pointer to a Node in the BST by its key.
// Use this fuction when you need a Node to test your 
// findInOrderSuccessor function on
Node *getNodeByKey( Node *root, int key )
{
   Node *currentNode = root;

   while( currentNode )
   {
      if( key == currentNode->key )
         return currentNode;

      if( key < currentNode->key )
         currentNode = currentNode->left;
      else
         currentNode = currentNode->right;
   }

   return nullptr;
}
Node* FindLeftNode(Node *inputNode){
  while (inputNode->left != NULL){
    inputNode=inputNode->left;
  }
  return inputNode;
}

Node* findInOrderSuccessor( Node *inputNode )
{
  if (inputNode->right != NULL){
    FindLeftNode(inputNode->right);
  }
  auto ancestor = inputNode->parent;
  auto child = inputNode;
  while(ancestor!=NULL && child == ancestor->right){
    child = ancestor;//?
    ancestor = child->parent;
  }
  return ancestor;
   // your code goes here
}
void insort_node(Node * node){
    if (node != NULL){
        insort_node(node->left);	 
        cout << node->key<<endl;
        insort_node(node->right);
	}
}

Node * findleft(Node* node){
    while (node->left !=NULL){
    node = node->left;
    }
    return node;
}

Node * find_order_sucessor(Node* node, int key){
	if (node->right !=NULL){
     	    findleft(node->right);
	}
	auto* parent = node->parent;


	while(parent !=NULL && node == parent->right){
            node = parent;
	    parent = parent->parent;
	}
	return parent;

}

int main() {
    Node *node = newNode(10);
    node = insert(node, 20);
    node = insert(node, 30);
//    insort_node(node);
    auto *n_node = find_order_sucessor(node, 20);
    insort_node(n_node);
  return 0;
}
