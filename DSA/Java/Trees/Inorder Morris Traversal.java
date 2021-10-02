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

        //Calling inorderMorrisTraversal to print Inorder Traversal
        tree.inorderMorrisTraversal(tree.root);
    }

    public void inorderMorrisTraversal(TreeNode root) {
        TreeNode curr = root;

        while (curr != null) {
            if (curr.left == null) {
                System.out.println(curr.val);
                curr = curr.right;
            } else {
                TreeNode rightMost = getRightMostNode(curr, curr.left);

                if (rightMost.right == null) {
                    // Create Thread
                    rightMost.right = curr;
                    curr = curr.left;
                } else {
                    // Delete Thread
                    rightMost.right = null;
                    System.out.println(curr.val);
                    curr = curr.right;
                }
            }
        }
    }

    public TreeNode getRightMostNode(TreeNode curr, TreeNode node) {
        while (node.right != null && node.right != curr) {
            node = node.right;
        }
        return node;
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
