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
    boolean solve(TreeNode root , TreeNode minT , TreeNode maxT){
        if(root == null)return true;

        if(minT != null){
            if(root.val <= minT.val)return false;
        }
        if(maxT != null){
            if(root.val >= maxT.val)return false;
        }

        return solve(root.left , minT , root) && solve(root.right , root , maxT);
    }
    public boolean isValidBST(TreeNode root) {
        return solve(root , null , null);
    }
}
