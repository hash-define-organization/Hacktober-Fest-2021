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
      
        //Calling printPreorder method to print Preorder Traversal of Tree
        tree.printPreorder(tree.root);
    }

    private void printPreorder(TreeNode node) {
        if (node == null) return;

        System.out.println(node.val);
        printPreorder(node.left);
        printPreorder(node.right);
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
