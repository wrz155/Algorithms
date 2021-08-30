package com.algorithm.problems.self;

import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class 求二叉树叶子节点个数 {
    public static class TreeNode {
        public int value;
        public TreeNode left;
        public TreeNode right;

        public TreeNode(int value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }
    }

    public static int leafNum(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        int sum = 0;

        q.add(root);
        while (!q.isEmpty()) {
            TreeNode tmp = q.poll();
            if (tmp.left != null)
                q.add(tmp.left);
            if (tmp.right != null)
                q.add(tmp.right);

            if (tmp.left == null && tmp.right == null)
                sum++;
        }

        return sum;
    }

    public static void main(String[] args) {
        TreeNode treeNode = new TreeNode(10);
        treeNode.left = new TreeNode(20);
        //treeNode.right = new TreeNode(30);

        System.out.println(leafNum(treeNode));
    }
}
