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
    int max_depth = 0;
    int solve(TreeNode root){

        if(root == null)return 0;
        int ans = 0;
        int l = 0 , r = 0;
        if(root.left != null)
         l = Math.max(ans , 1 + solve(root.left));
        if(root.right != null)
         r = Math.max(ans , 1 + solve(root.right));
        max_depth = Math.max(l + r , max_depth);
        return Math.max(l , r);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        
        solve(root);
        if(root.left != null)
        diameterOfBinaryTree(root.left);
        if(root.right != null)
        diameterOfBinaryTree(root.right);

        return max_depth;
    }
}
