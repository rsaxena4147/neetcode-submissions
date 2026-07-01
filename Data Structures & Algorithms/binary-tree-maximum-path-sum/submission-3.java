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
    int ans =Integer.MIN_VALUE;
    int solve(TreeNode root){
        if(root == null)return 0;

        int left = Math.max(0 , solve(root.left));
        int right = Math.max(0 , solve(root.right));

        ans = Math.max(ans , root.val + left + right);

        return Math.max(left , right) + root.val;
    }
    public int maxPathSum(TreeNode root) {
        if(root == null)return ans;
        solve(root);
        
        maxPathSum(root.left);
        maxPathSum(root.right);
        return ans;
        
    }
}
