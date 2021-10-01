#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~node()
    {
        delete left;
        delete right;
    }
};

node *takeInput()
{
    static int index = 0;

    string rootData;

    cin >> rootData;

    if (rootData == "n")
    {
        return NULL;
    }

    node *root = new node(stoi(rootData));

    index++;

    root->left = takeInput();
    root->right = takeInput();

    return root;
}

void display(node *&root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

// In this question one thing to note is that it is not necessary that the path passes through the root node
// &
// that the path must be from one leaf node to another leaf node
// it can be any path within as well, not passing through the root and with no leaf nodes

int max_sum;

int maxPathSum(node *&root)
{
    if (root == NULL)
        return 0;

    int sum = 0;

    int lsum = maxPathSum(root->left);
    int rsum = maxPathSum(root->right);

    sum = max(root->data, max(root->data + lsum, root->data + rsum));

    max_sum = max(max_sum, max(sum, root->data + lsum + rsum));

    return sum;
}

int main()
{
    int size;
    cin >> size;

    node *root = takeInput();

    maxPathSum(root);
    cout << max_sum;

    return 0;
}

// 9 6 n n -3 -6 n n 2 2 -6 -6 n n n -6 n n n  ---> 16