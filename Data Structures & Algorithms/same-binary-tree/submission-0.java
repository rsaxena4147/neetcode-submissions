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
    boolean solve(TreeNode a , TreeNode b){
        if(a == null && b == null)return true;
        if(a == null || b == null)return false;

        if(a.val != b.val)return false;

        return solve(a.left , b.left) && solve(a.right , b.right);

    }
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return solve(p , q);
    }
}
