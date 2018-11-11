/**
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * <p>
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null) {
            return null;
        } else if (l1 != null && l2 == null) {
            return l1;
        } else if (l1 == null && l2 != null) {
            return l2;
        }
        int carryIn = 0;
        if (l1.val + l2.val >= 10) {
            carryIn = 1;
        }
        ListNode resultListNode = new ListNode((l1.val + l2.val) % 10);
        l1 = l1.next;
        l2 = l2.next;
        ListNode head = resultListNode;

        while (l1 != null && l2 != null) {
            resultListNode.next = new ListNode((l1.val + l2.val + carryIn) % 10);
            carryIn = l1.val + l2.val + carryIn >= 10 ? 1 : 0;

            resultListNode = resultListNode.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        while (l1 != null) {
            resultListNode.next = new ListNode((l1.val + carryIn) % 10);
            carryIn = l1.val + carryIn >= 10 ? 1 : 0;

            resultListNode = resultListNode.next;
            l1 = l1.next;
        }
        while (l2 != null) {
            resultListNode.next = new ListNode((l2.val + carryIn) % 10);
            carryIn = l2.val + carryIn >= 10 ? 1 : 0;
            resultListNode = resultListNode.next;
            l2 = l2.next;
        }
        if (carryIn == 1 && l1 == null & l2 == null) {
            resultListNode.next = new ListNode(carryIn);
        }

        return head;
    }
}
