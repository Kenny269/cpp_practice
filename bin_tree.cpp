#include <stdio.h>
#include <iostream>
using namespace std;
int depth = 0;

// define a struct for binTree
struct node
{
    int value;
    node *left;
    node *right;
    node(int value) : value(value), left(nullptr), right(nullptr)
    {
        // this->value = value;
    }

    void print()
    {
        cout << this->value << endl;
    }
};

node *addNode(node *root, int v)
{
    if (root == nullptr)
    {
        return new node(v);
    }
    if (root->value > v)
    {
        root->left = addNode(root->left, v);
    }
    else
    {
        root->right = addNode(root->right, v);
    }
    return root;
}

void midprint(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    midprint(root->left);
    cout << root->value << " ";
    midprint(root->right);
}
int Depth(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftDepth = Depth(root->left);
    int rightDepth = Depth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

bool search(node *current, int val)
{
    if (current == nullptr)
    {
        return 0;
    }
    if (val < current->value)
    {
        return search(current->left, val);
    }
    else if (val == current->value)
    {
        return 1;
    }
    else
    {
        return search(current->right, val);
    }
}

int main()
{
    node *root = nullptr;
    node *test = new node(10);
    test->print();

    while (1)
    {
        int a;
        cin >> a;
        // cout<<a<<endl;
        if (a < 0)
        {
            break;
        }
        else
        {
            root = addNode(root, a);
        }
    }
    //    cout<<"test"<<endl;
    midprint(root);
    int value;
    cout << "input a value to search:";
    cin >> value;
    cout << search(root, value) << endl;

    return 0;
}
