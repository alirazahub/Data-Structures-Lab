#include<iostream>
using namespace std;
struct node
{
    int info;
    node *left;
    node *right;

};
node * root;
node * insertion(node*root,int x)
{
    if(root==NULL)
    {
        node* p= new node;
        p->info=x;
        p->left=NULL;
        p->right=NULL;
        root=p;
    }
    else if(root->info==x)
    {
        cout<<x<<" is Discarded"<<endl;
    }
    else if(x>root->info)
    {
        root->right=insertion(root->right,x);
    }
    else if(x<root->info)
    {
        root->left=insertion(root->left,x);
    }
    return root;
}
//post order
void displaypost(node*root)
{
    if(root==NULL)
    {
        return;
    }

    displaypost(root->left);
    displaypost(root->right);
    cout<<root->info<<"  ";
}

//pre order
void displaypre(node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->info<<"  ";
    displaypre(root->left);
    displaypre(root->right);

}
//in order
void displayin(node*root)
{
    if(root==NULL)
    {
        return;
    }

    displayin(root->left);
    cout<<root->info<<"  ";
    displayin(root->right);
}

//maximum value in bst
int max(node*root)
{
    if(root==NULL)
    {
        return -1;
    }
    else if(root->right==NULL)
    {
        return root->info;
    }
    else
    {
        return max(root->right);
    }
}
int min(node*root)
{
    if(root==NULL)
    {
        return -1;
    }
    else if(root->left==NULL)
    {
        return root->info;
    }
    else
    {
        return min(root->left);
    }
}


// delete a node
node* deletenode(node*root,int x)
{
    if(root==NULL)
    {
        cout<<"Not Found"<<endl;
    }
    else if(x>root->info)
    {
        root->right=deletenode(root->right,x);
    }
    else if(x<root->info)
    {
        root->left=deletenode(root->left,x);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        else if(root->left==NULL)
        {
            node*temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            node*temp=root;
            root=root->left;
            delete temp;
        }
        else
        {
            int y=min(root->right);
            root->info=y;
            root->right=deletenode(root->right,y);
        }
    }
    return root;
}


int main()
{
    root=NULL;
    root=insertion(root,10);
    root=insertion(root,8);
    root=insertion(root,15);
    root=insertion(root,7);
    root=insertion(root,9);
    root=insertion(root,14);
    root=insertion(root,16);
    cout<<"Pre Order "<<endl;
    displaypre(root);
    cout<<endl;
    cout<<"Post Order "<<endl;
    displaypost(root);
    cout<<endl;
    cout<<"In Order "<<endl;
    displayin(root);
    cout<<endl;
    cout<<"Maximum Value in BST is "<<max(root)<<endl;
    cout<<"Minimum Value in BST is "<<min(root)<<endl;
}