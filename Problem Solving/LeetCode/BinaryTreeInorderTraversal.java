package problemSolving;

import java.util.ArrayList;
import java.util.List;

public class BinaryTreeInorderTraversal {

	public static void main(String[] args) {
		TreeNode root = new TreeNode(1, null, new TreeNode(2, new TreeNode(3), null));
		
		inOrder(root);
		
	}
	
	static List<Integer> list;

	public List<Integer> inorderTraversal(TreeNode root) {
		list = new ArrayList<>();
		inOrder(root);
        return list;
    }
    
    public static void inOrder(TreeNode root) {
    	if(root == null)return;
    	inOrder(root.left);
    	list.add(root.val);
    	inOrder(root.right);
    }

}
