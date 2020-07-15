#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x),  left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) 
    {
        while(root)
        {
            nodeStack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return !nodeStack.empty();
    }

    /** @return the next smallest number */
    int next() 
    {
        TreeNode* node = nodeStack.top();
        nodeStack.pop();
        int num = node->val;
        
        node = node->right;
        while(node)
        {
            nodeStack.push(node);
            node = node->left;
        }
        
        return num;
    }
    
private:
    std::stack<TreeNode*> nodeStack;
};


int main(void){
    TreeNode *root;
    BSTIterator* bsti = new BSTIterator(root);
    int param_1 = bsti->next();

}
