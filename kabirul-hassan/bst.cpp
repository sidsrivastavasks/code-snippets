#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data,height;
    struct node *left, *right; 
}Node;

class BST
{
private:
    Node *root;
    /* data */
public:
    BST(int);
    ~BST();

    int balanceFactor(Node*);
    int nodeHeight(Node*);
    void insert(Node*,int);
    Node* rInsert(Node*,int);
    void inorder(Node*);

    Node* getRoot()
    {
        return root;
    }
    Node* setRoot(Node* t)
    {
        root=t;
        return root;
    }
};

BST::BST(int x)
{
    root = new Node;
    root->data=x;
    root->left=root->right=NULL;
}

BST::~BST()
{
    delete root;
}
int BST::nodeHeight(Node* t)
{
    int hl,hr;
    hl = (t&&t->left)?t->left->height+1:0;
    hr = (t&&t->right)?t->right->height+1:0;
    return (hl>hr?hl:hr)+1;
}

int BST::balanceFactor(Node* t)
{
    int hl,hr;
    hl = (t&&t->left)?t->left->height+1:0;
    hr = (t&&t->right)?t->right->height+1:0;
    return hl-hr;
}
void BST::insert(Node *t, int key)
{
    Node *r=NULL, *p;
    while(t!=NULL)
    {
        r=t;
        if(key==t->data)
            return;
        else if(key<t->data)
            t=t->left;
        else
            t=t->right;
    }
    p = new Node;
    p->data=key;
    p->left=p->right=NULL;
    if(p->data<r->data)
        r->left=p;
    else
        r->right=p;
}

Node* BST::rInsert(Node *t,int key)
{
    Node *temp;
    if(t==NULL)
    {
        temp = new Node;
        temp->data=key;
        temp->left=temp->right=NULL;
        return temp;
    }
    if(key<t->data)
        t->left=rInsert(t->left,key);
    else if(key>t->data)
        t->right=rInsert(t->right,key);
    return t;
}
void BST::inorder(Node* t)
{
    if(t!=NULL)
    {
    BST::inorder(t->left);
    cout<<t->data<<" ";
    BST::inorder(t->right);   
    }
}

int main()
{
    int x;
    cout<<"Enter the root node: ";
    cin>>x;
    BST bst(x);
    cout<<"Start inserting enter -1 to stop:\n";
    for(;x>-1;)
    {
        cin>>x;
        if(x>-1)
            bst.rInsert(bst.getRoot(),x);
    }
    bst.inorder(bst.getRoot());
    cout<<endl;
}
