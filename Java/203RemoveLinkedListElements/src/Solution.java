/**
 * Created by zwb on 2016/12/9.
 */
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        //if head == val ,del head first
        while(head != null && head.val == val){
            head = head.next;
        }

        ListNode node = head;
        ListNode nodePre = head;
        while (node != null) {
            if (node.val != val) {
                nodePre = node;
            } else {
                nodePre.next = node.next;
            }
            node = node.next;
        }

        return head;
    }
}
