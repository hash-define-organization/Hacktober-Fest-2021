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

        //Calling printPostorder method to print Postorder Traversal of Tree
        tree.printPostorder(tree.root);
    }

    private void printPostorder(TreeNode node) {
        if (node == null) return;

        printPostorder(node.left);
        printPostorder(node.right);
        System.out.println(node.val);
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
