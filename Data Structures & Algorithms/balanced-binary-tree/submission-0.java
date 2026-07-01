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
    int depth(TreeNode root){

        if(root == null)return 0;
        int ans = 0;
        ans = Math.max(ans , 1 + depth(root.left));
        ans = Math.max(ans , 1 + depth(root.right));
        return ans;
    }
    boolean solve(TreeNode root){
        if(root == null)return true;

        int l = depth(root.left);
        int r = depth(root.right);

        if(Math.abs(l - r) > 1)return false;

        return solve(root.left) && solve(root.right);
        

    }
    public boolean isBalanced(TreeNode root) {
        return solve(root);
    }
}
