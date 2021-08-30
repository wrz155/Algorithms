package com.algorithm;

public class 删除链表中间位置的节点 {
    public static class Node{
        public int value;
        public Node next;

        public Node(int data){
            this.value = data;
        }
    }

    public static Node removeMidNode(Node head) {
        if(head == null || head.next == null)
            return head;
        if(head.next.next == null)
            return head.next;
        Node slow = head;           // 不仅是慢指针，还是中间节点的前一个
        Node fast = head.next.next;

        while (fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        slow.next = slow.next.next;
        return head;
    }

    public static void printLinkedList(Node head) {
        System.out.print("Linked List: ");
        while (head != null) {
            System.out.print(head.value + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Node head1 = new Node(1);
        head1.next = new Node(2);
        head1.next.next = new Node(3);
        head1.next.next.next = new Node(4);
        head1 = removeMidNode(head1);
        printLinkedList(head1);
    }
}
