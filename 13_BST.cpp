#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left, *right;
};

class bst
{

    node *root;
public:
    bst();
    void insert(int);
    void travesal();
    void inorder();
    void postorder(node *);
    void preorder(node *);
    node* deletenode(struct node*,int);
};

bst ::bst()
{
    root = NULL;
}

void bst ::insert(int num)
{
    node *r, *temp, *prev;
    r = new node;
    r->data = num;
    r->left = NULL;
    r->right = NULL;
    if (root == NULL)
    {
        root = r;
    }
    else
    {
        temp = root;
        while (temp != NULL)
        {
            prev = temp;
            if (temp->data > num)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (prev->data > num)
        {
            prev->left = r;
        }
        else
        {
            prev->right = r;
        }
    }
}
void bst ::preorder(node *root)
{
    if (root != NULL)
    {
        cout << " " << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}
void bst ::inorder()
{
    if (root != NULL)
    {
        preorder(root->left);
        cout << " " << root->data;
        preorder(root->right);
    }
}
void bst ::postorder(node *root)
{
    if (root != NULL)
    {
        preorder(root->left);
        preorder(root->right);
        cout << " " << root->data;
    }
}
struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

node*  bst ::deletenode(struct node* root,int num)
{
      struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        delete(root);
        return NULL;
    }

     
    if (num < root->data){
        root-> left = deletenode(root->left,num);
    }
    else if (num > root->data){
        root-> right = deletenode(root->right,num);
    }
    
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deletenode(root->left, iPre->data);
    }
    return root;
       
       
}   
      
int main()
{
    bst b;
    b.insert(5);
    b.insert(3);
    b.insert(6);
    b.insert(1);
    b.insert(4);
    b.inorder();
    printf("\n");
//    b1.deletenode(b1, 3);
    

    
    return 0;
}