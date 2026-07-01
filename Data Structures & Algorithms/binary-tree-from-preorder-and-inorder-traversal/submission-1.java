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
    int ind = 0;
    TreeNode solve(int[] preorder, int[] inorder , HashMap<Integer , Integer> mp ,  int l , int r){

        if(l > r)return null;
       // if(ind >= preorder.length) return null;
        int val = preorder[ind];
        ind++;
        TreeNode node = new TreeNode(val);
        node.left = solve(preorder , inorder , mp , l , mp.get(val) - 1);
        node.right = solve(preorder , inorder,mp  , mp.get(val) + 1 , r);

        return node;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        HashMap<Integer , Integer> mp = new HashMap<>();

        for(int i = 0 ; i < inorder.length ; i++){
            mp.put(inorder[i] , i);
        }
        
        return solve(preorder , inorder , mp , 0 , inorder.length - 1);
    }
}
