//{ Driver Code Starts
import java.util.*;

class Node
{
	int data ;
	Node next;
	Node(int d)
	{
		data = d;
		next = null;
	}
}

class Delete_Node
{
	Node head;
	Node tail;
	
	void printList(Node head)
	{
		Node tnode = head;
		while(tnode != null)
		{
			System.out.print(tnode.data+ " ");
			tnode = tnode.next;
		}
		System.out.println();
	}
	
	void addToTheLast(Node node)
	{
		
		if(head == null)
		{
			head = node;
			tail = node;
		}
		else
		{
		    tail.next = node;
		    tail = node;
		}
	}
	
	Node search_Node(Node head, int k)
	{
		Node current = head;
		while(current != null)
		{
			if(current.data == k)
				break;
			current = current.next;
		}
	return current;
	}
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		while(t>0)
		{
			int n = sc.nextInt();
			Delete_Node llist = new Delete_Node();
			//int n=Integer.parseInt(br.readLine());
			int a1=sc.nextInt();
			Node head= new Node(a1);
            llist.addToTheLast(head);
            for (int i = 1; i < n; i++) 
			{
				int a = sc.nextInt(); 
				llist.addToTheLast(new Node(a));
			}
			
			int k = sc.nextInt();
			Node del_node = llist.search_Node(llist.head,k);
			
			Solution g = new Solution();
			if(del_node != null && del_node.next != null)
			{
				g.deleteNode(del_node);
			}
			llist.printList(llist.head);
		t--;
		}
	}
}



// } Driver Code Ends


/*
class Node
{
	int data ;
	Node next;
	Node(int d)
	{
		data = d;
		next = null;
	}
}
*/

//Function to delete a node without any reference to head pointer.
class Solution
{
    void deleteNode(Node del_node)
    {
        Node temp = del_node.next;
        del_node.data = temp.data;
        del_node.next = temp.next;
        temp = null;
    }
}


