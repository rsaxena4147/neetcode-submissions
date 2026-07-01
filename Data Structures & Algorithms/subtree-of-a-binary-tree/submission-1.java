/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    boolean check(TreeNode a, TreeNode b) {
        if (a == null && b == null)
            return true;
        if (a == null || b == null)
            return false;

        if (a.val == b.val) {
            return check(a.left, b.left) && check(a.right, b.right);
        }

        return false;
    }
    boolean solve(TreeNode root, TreeNode subRoot) {
        if (root == null && subRoot == null)
            return true;
        if (root == null || subRoot == null)
            return false;

        if (root.val == subRoot.val) {
            if(check(root, subRoot)) return true;
        }

        return solve(root.left, subRoot) || solve(root.right, subRoot);
    }
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        return solve(root, subRoot);
    }
}
