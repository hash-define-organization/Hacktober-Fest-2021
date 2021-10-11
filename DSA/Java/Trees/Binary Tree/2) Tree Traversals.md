# Tree Traversals
> For the **implementation** of all traversals, we'll use a **TreeNode class** that will store node's value and keep a reference to each child:
```java
 public class TreeNode {
     int val;
     TreeNode left;
     TreeNode right;
     TreeNode() {}
     TreeNode(int val) { this.val = val; }
     TreeNode(int val, TreeNode left, TreeNode right) {
         this.val = val;
         this.left = left;
         this.right = right;
     }
 }
 ```
* ## Pre-order Traversal
> Pre-order traversal is to visit the root first. Then traverse the left subtree. Finally, traverse the right subtree.
```java
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> preorder = new ArrayList<Integer>(); 
        dfs(root, preorder);
        return preorder; 
    }
    private void dfs(TreeNode node, List<Integer> preorder) {
        if(node == null) return; 
        
        preorder.add(node.val); 
        dfs(node.left, preorder);
        dfs(node.right, preorder); 
    }
}
```
> `Time Complexity` **O(N)**   
> `Space Complexity` **O(N)**   
---
* ## In-order Traversal
> In-order traversal is to traverse the left subtree first. Then visit the root. Finally, traverse the right subtree.
```java
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> inorder = new ArrayList<Integer>(); 
        dfs(root, inorder);
        return inorder; 
    }
    private void dfs(TreeNode node, List<Integer> inorder) {
        if(node == null) return; 
         
        dfs(node.left, inorder);
        inorder.add(node.val);
        dfs(node.right, inorder); 
    }
}
```
> `Time Complexity` **O(N)**   
> `Space Complexity` **O(N)**   
---
* ## Post-order Traversal
> Post-order traversal is to traverse the left subtree first. Then traverse the right subtree. Finally, visit the root.
```java
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> postorder = new ArrayList<Integer>(); 
        dfs(root, postorder);
        return postorder; 
    }
    private void dfs(TreeNode node, List<Integer> postorder) {
        if(node == null) return; 
       
        dfs(node.left, postorder);
        dfs(node.right, postorder); 
        postorder.add(node.val); 
    }
}
```
> `Time Complexity` **O(N)**   
> `Space Complexity` **O(N)**   
---
* ## Level-order Traversal
> Level-order traversal is to traverse the tree level by level.
> Breadth-First Search is an algorithm to traverse or search in data structures like a tree or a graph. The algorithm starts with a root node and visit the node itself first. 
> Then traverse its neighbors, traverse its second level neighbors, traverse its third level neighbors, so on and so forth.
> When we do breadth-first search in a tree, the order of the nodes we visited is in level order.
```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> resultList = new ArrayList();
        if (root == null) return resultList;
        
        Queue<TreeNode> queue = new LinkedList();
        queue.add(root);
        
        while (!queue.isEmpty()) {
            List<Integer> levelList = new ArrayList();
            int levelSize = queue.size();
            for (int i=0; i<levelSize; i++) {
                TreeNode frontNode = queue.remove();
                levelList.add(frontNode.val);
                if (frontNode.left != null) queue.add(frontNode.left);
                if (frontNode.right != null) queue.add(frontNode.right);              
            }  
            resultList.add(levelList);
        }  
        
        return resultList;
    }
}
```
> `Time Complexity` **O(N)**   
> `Space Complexity` **O(N)**   
---
