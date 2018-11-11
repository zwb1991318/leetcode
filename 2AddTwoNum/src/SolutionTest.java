import static org.junit.Assert.*;

/**
 * Created by zwb on 2016/12/11.
 */
public class SolutionTest {

    @org.junit.Test
    public void testAddTwoNumbers() throws Exception {
        ListNode list1 = new ListNode(5);
//        list1.next = new ListNode(4);
//        list1.next.next = new ListNode(3);
        ListNode list2 = new ListNode(5);
//        list2.next = new ListNode(6);
//        list2.next.next = new ListNode(4);
        ListNode list = new ListNode(7);
        list.next = new ListNode(0);
        list.next.next = new ListNode(8);
        Solution solution = new Solution();
        assertEquals(list,solution.addTwoNumbers(list1,list2));
    }
}