#include<bits/stdc++.h>
using namespace std;

//Node class
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to create tree
Node* create(string levelorder[], int n,  int idx)
{
    if(idx >= n || levelorder[idx] == "null")
        return NULL;
    Node* root = new Node(stoi(levelorder[idx]));
    root->left = create(levelorder, n, 2*idx+1);
    root->right = create(levelorder, n, 2*idx+2);
}

// Searching for target node using simple preorder
Node* find(Node* root, int target)
{
    if(root == NULL)
        return NULL;

    if(root->data == target)
        return root;
    Node* left = find(root->left, target);
    Node* right = find(root->right, target);
    if(left)
        return left;
    if(right)
        return right;
    return NULL;
}
 
// creating the map which stores parent of each node
void createParent(Node* root,unordered_map<Node*, Node*> &mp )
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* top = q.front();
        q.pop();
        if(top->left)
        {
            mp[top->left] = top;
            q.push(top->left);
        }
        if(top->right)
        {
            mp[top->right] = top;
            q.push(top->right);
        }
    }        
}

// function to find all the nodes at k distance
vector<int> Kdistance(Node* root, Node* target, int k) {
    
    unordered_map<Node*, Node*> mp;
    createParent(root, mp);
    
    unordered_map<Node*, bool> visited;
    int curr = 0;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    
    while(!q.empty())
    {
        int sz = q.size();
        if(curr++ == k)
            break;
        //for each node present in the queue check if the node is visited or not.... if not visited then push it into queue
        for(int i = 0; i<sz; i++)
        {
            Node* top = q.front();
            q.pop();
            
            // checking in all the possible direction to obtain the answer
            if(top->left && !visited[top->left]) 
            {
                q.push(top->left);
                visited[top->left] = true;
            }
            if(top->right && !visited[top->right]) 
            {
                q.push(top->right);
                visited[top->right] = true;
            }
            if(mp[top] && !visited[mp[top]]) 
            {
                q.push(mp[top]);
                visited[mp[top]] = true;
            }
        }
    }

    // storing the answer in vector
    vector<int> ans;
    while(!q.empty()) 
    {
        Node* current = q.front(); 
        q.pop();
        ans.push_back(current->data);
    }
    return ans;
}

int main()
{
    // taking input
    int n;
    cin>>n;
    string levelorder[n];

    for(int i = 0; i<n; i++)
        cin>>levelorder[i];
    Node* root = NULL;
    int idx = 0;
    // creating the tree
    root = create(levelorder, n, 0);

    int target, k;
    cout<<"Enter the value of the target node::";
    cin>>target;
    cout<<"Enter the value of k::";
    cin>>k;
    //finding target node in the recently created tree
    Node* targetNode = find(root, target);

    //calling the Kdistance function and calculating the answer
    vector<int> ans = Kdistance(root, targetNode, k);
    cout<<endl<<"All the nodes at "<<k<<" distance from the target node are:";
    for(auto i: ans)
        cout<<i<<" ";
    return 0;
}