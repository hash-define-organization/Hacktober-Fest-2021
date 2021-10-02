import java.util.*;

public class Trees {
    TreeNode root;

    public static void main(String[] args) {
        //Creating Tree
        Trees tree = new Trees();
        tree.root = new TreeNode(1);
        tree.root.left = new TreeNode(2);
        tree.root.right = new TreeNode(3);
        tree.root.left.left = new TreeNode(4);
        tree.root.left.right = new TreeNode(5);
      
        //Calling printInorder method to print Inorder Traversal of Tree
        tree.printInorder(tree.root);
    }

    private void printInorder(TreeNode node) {
        if (node == null) return;

        printInorder(node.left);
        System.out.println(node.val);
        printInorder(node.right);
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }
}
