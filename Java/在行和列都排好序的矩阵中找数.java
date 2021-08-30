package com.algorithm;

public class 在行和列都排好序的矩阵中找数 {
    /*
    * 这道题目的核心点在于选择 右上角或者左下角作为出发点
    * 如果选择左上角或者右下角无法淘汰更多的数
    * */
    public static boolean isContains(int[][] matrix, int k){
        int row = 0;
        int col = matrix[0].length - 1;
        while(row < matrix.length && col > -1) {
            if (matrix[row][col] == k)
                return true;
            else if (matrix[row][col] > k)
                col--;
            else
                row++;
        }
        return false;
    }

    public static void main(String[] args) {
        int[][] matrix = new int[][] {
                { 0, 1, 2, 3, 4, 5, 6 },// 0
                { 10, 12, 13, 15, 16, 17, 18 },// 1
                { 23, 24, 25, 26, 27, 28, 29 },// 2
                { 44, 45, 46, 47, 48, 49, 50 },// 3
                { 65, 66, 67, 68, 69, 70, 71 },// 4
                { 96, 97, 98, 99, 100, 111, 122 },// 5
                { 166, 176, 186, 187, 190, 195, 200 },// 6
                { 233, 243, 321, 341, 356, 370, 380 } // 7
        };
        int K = -1;
        System.out.println(isContains(matrix, K));
    }
}
