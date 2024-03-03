#include <iostream>
using namespace std;

class Node
{
    public:
    Node * left, * right;
    int data;
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

class Tree
{
    public:
    Node * root;
    
    public:
    Tree()
    {
        root = NULL;
    }

    Node * insert(Node *pnode, int value)
    {
        if(pnode == NULL)
        {
            Node * newnode = new Node(value);
            pnode = newnode;
        }
        else if( value < pnode->data )
        {
           pnode->left = insert(pnode->left,value);
        }
        else
        {
            pnode->right = insert(pnode->right, value);
        }
        return pnode;
    }

    void insert(int value)
    {
        root = insert(root,value);
    }

    void PreOrder(Node * root)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            cout << root->data << "\t";
            PreOrder(root->left);
            PreOrder(root->right);
        }
    }
   
    void PostOrder(Node * root)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            PostOrder(root->left);
            PostOrder(root->right);
            cout << root->data << "\t";
        }
    }
    
    void inOrder(Node * root)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            inOrder(root->left);
            cout << root->data << "\t";
            inOrder(root->right);
        }
    }

    Node * Search(Node * root, int key)
    {
        if(root == NULL)
        {
            return NULL;
        }
        else if(root->data == key)
        {
            return root;
        }
        else if(key < root->data)
        {
            return Search(root->left, key);
        }
        else
        {
            return Search(root->right, key);
        }
    }

    bool Search(int key)
    {
       Node * result = Search(root,key);

       return (result != NULL);
    }

    Node * Min(Node * root)
    {
        if(root == NULL)
        return NULL;
        else if(root->left == NULL)
        return root;
        else
        return Min(root->left);
    }
    
    Node * Max(Node * root)
    {
        if(root == NULL)
        return NULL;
        else if(root->right == NULL)
        return root;
        else
        return Max(root->right);
    }

    Node * Delete(Node * root, int value)
    {
        if(root == NULL)
        return NULL;
        else if(value < root->data)
        root->left = Delete(root->left, value);
        else if(value > root->data)
        root->right = Delete(root->right, value);
        else
        {
            if(root->right == NULL && root->left == NULL)
            {
                root = NULL;
            }
            else if(root->left != NULL && root->right == NULL)
            {
                 root->data = root->left->data;
                 delete root->left;
                 root->left = NULL;
            }
        
            else if(root->left == NULL && root->right != NULL)
            {
                 root->data = root->right->data;
                 delete root->right;
                 root->right = NULL;
            }
            else
            {
                Node * predec = Max(root->left);
                root->data = predec->data;
                root->left = Delete(root->left, predec->data);

                
            }
        }
        return root;
    }




};



int main()
{
    Tree tree;

    tree.insert(45);
    tree.insert(15);
    tree.insert(79);
    tree.insert(90);
    tree.insert(10);
    tree.insert(55);

    tree.PreOrder(tree.root);
    cout << tree.Search(55) << endl;
    cout << tree.Search(4444) << endl;

    cout << tree.Min(tree.root)->data << endl;
    cout << tree.Max(tree.root)->data << endl;

    tree.Delete(tree.root,79);

    tree.PreOrder(tree.root);
    


}