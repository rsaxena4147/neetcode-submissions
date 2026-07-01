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
    
    int solve(TreeNode root){
        if(root == null)return 0;
        int ans = 0;

     
            ans = Math.max(ans , 1 + solve(root.left));
        
        
            ans = Math.max(ans , 1 + solve(root.right));
        
        
        return ans;
    }
    public int maxDepth(TreeNode root) {
       
        return solve(root);
        
    }
}