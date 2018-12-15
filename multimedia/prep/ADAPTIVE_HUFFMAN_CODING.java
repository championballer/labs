import java.util.HashSet;
import java.util.Scanner;

public class ADAPTIVE_HUFFMAN_CODING {
	
	public static class Node{
		char ch;
		Node left;
		Node right;
		boolean isNYT;
		int order;
		int weight;
		Node parent;
		
		Node(char ch,int weight,int order,boolean isNYT){
			this.ch = ch;
			this.weight = weight;
			this.order = order;
			this.isNYT = isNYT;
			
		}
		
	}
	
	public static Node NYT_sender,NYT_receiver;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		HashSet<Character> set = new HashSet<>();
		
		String str = s.nextLine();
		
		for(int i=0;i<str.length();i++)
			if(!set.contains(str.charAt(i)))
				set.add(str.charAt(i));
		Node root_sender = new Node('-',0,2*set.size()+1,true);
		Node root_receiver = new Node('-',0,2*set.size()+1,true);;
		
		NYT_sender = new Node('-',0,2*set.size()+1,true);
		NYT_receiver = new Node('-',0,2*set.size()+1,true);
		String msg = "";
		String code = "";
		for(int i=0;i<str.length();i++) {
			char ch = str.charAt(i);
			code += Encode(root_sender,ch);
			System.out.println("Code = "+code);
			
		}
		msg = Decode(root_receiver,code);
		System.out.println("MSG = "+msg);
		

	}
	
	public static String Encode(Node root,char ch) {
		//System.out.println("Encoding "+ch);
		String code;
		Node node = search(root,ch);
		if(node!=null) {
			code = getCode(ch,root,"");
			updateTree(root, ch,NYT_sender);
		}
		
		else {
			code = getCode('-',root,"");
			code+=toBinaryString((int)ch);
			updateTree(root,ch,NYT_sender);
		}

		printTree(node);
		
		return code;
		
	}
	
	public static String Decode(Node root,String code) {
		
		String msg = "";
		Node currentNode = root;
		while(code.length()>0) {
			if(currentNode.left==null&&currentNode.right==null) {
				char ch = '*';
				//System.out.println("There");
				if(currentNode.isNYT) {
					//System.out.println("hey");
				    ch = (char)IntValue(code.substring(0,8));
					code = code.substring(8,code.length());
				}
				
				else {
					ch = currentNode.ch;
				}
				updateTree(root,ch,NYT_receiver);
				currentNode = root;
				msg+=ch;
			}
			
			else {
				char bit = code.charAt(0);
				if(bit=='0')
					currentNode = currentNode.left;
				else
					currentNode = currentNode.right;
				
				code = code.substring(1,code.length());
			}
		}
		
		return msg;
	}
	
	public static int IntValue(String bits) {
		int value = 0;
		int pow = 1;
		for(int i=bits.length()-1;i>=0;i--,pow = pow*2)
		{
		    value+=(bits.charAt(i)-'0')*pow;	
		}
		
		return value;
	}
	
	public static String getCode(char ch,Node node,String code) {
		if(node==null)
			return null;
		if(node.ch==ch)
			return code;
		else {
			String ans = getCode(ch,node.left,code+"0");
			if(ans!=null)
				return ans;
			else
				return getCode(ch,node.right,code+"1");
		}
	}
	
	public static void updateTree(Node root,char ch,Node NYT) {
		//System.out.println("Searching "+ch);
		Node node = search(root,ch);
		if(node==null) {
			//System.out.println("Hello");
			Node right = new Node(ch,1,NYT.order-1,false);
			right.parent = NYT;
			NYT.isNYT = false;
			NYT.right = right;
			Node left = new Node('-',0,NYT.order-2,true);
			NYT.left = left;
			left.parent = NYT;
			NYT = left;
			
			updateWeights(NYT.parent,root);
		}
		else {
			//System.out.println("There");
			node.weight++;
			updateWeights(node.parent,root);
		}
		
	}
	
	public static String toBinaryString(int val) {
		String bin = "";
		while(val!=0) {
			int mod = val%2;
			val = val/2;
			if(mod==0)
				bin = '0'+bin;
			else 
				bin = '1'+bin;
		}
		
		while(bin.length()!=8)
			bin = '0'+bin;
		return bin;
	}
	
	public static void updateWeights(Node node,Node root) {
		//System.out.println("updating "+node.order);
		if(node.parent == null)
			{node.weight = node.left.weight+node.right.weight;
			//System.out.println(node.weight);
			 return;}
		else {
			//System.out.println("Looking for"+node.order);
			Node same_wgt_high_order = search(root,node.weight);
			if(same_wgt_high_order==node) {
				node.weight = node.left.weight + node.right.weight;
				updateWeights(node.parent, root);
			}
			
			else {
				int order = node.order;
				node.order = same_wgt_high_order.order;
				same_wgt_high_order.order = order;
				Node p1 = node.parent;
				Node p2 = same_wgt_high_order.parent;
				
				boolean l1=false,l2 = false;
				if(p1.left==node)
					l1 = true;
				if(p2.left == same_wgt_high_order)
					l2 = true;
				
				if(l1) {
					p1.left = same_wgt_high_order;
					same_wgt_high_order.parent = p1;
					
					if(l2)
						p2.left = node;
					else
						p2.right = node;
					node.parent = p2;
				}
				
				else  {
					p1.right = same_wgt_high_order;
					same_wgt_high_order.parent = p1;
					
					if(l2)
						p2.left = node;
					else
						p2.right = node;
					node.parent = p2;
				}
				node.weight = node.left.weight+node.right.weight;
				updateWeights(node.parent, root);
			}
			
		    
		}
	}
	
	public static Node search(Node root,int weight) {
		
		if(root==null)
			return null;
		else {
		///System.out.println("At "+root.order+" "+root.ch+" "+weight);
		if(root.isNYT)
			return null;
		if(root.weight==weight)
			return root;
		else {
			Node n1 = search(root.right,weight);
			if(n1!=null)
				return n1;
			else
				return search(root.left,weight);
		}
		}
	}
	
	public static Node search(Node root,char ch) {
		if(root==null)
			return null;
		//System.out.println(root.isNYT);
		if(root.isNYT)
			return null;
		else if(root.ch==ch)
			return root;
		else {
			Node n1 = search(root.right,ch);
			if(n1!=null)
				return n1;
			else
				return search(root.left,ch);
		}
	}
	
	public static void printTree(Node node) {
		
		if(node==null||node.left==null)
			return;
		if(node.isNYT)
			System.out.println("NYT");
		else
		{
			
			System.out.print(showNode(node.left));
			
			System.out.print("=>");
			
			System.out.print(showNode(node));
			
			System.out.print("<=");
			
			System.out.println(showNode(node.right));
			printTree(node.right);
			printTree(node.left);
			
		}
	}
	
	public static String showNode(Node node) {
		if(node.isNYT)
			return "{NYT,"+node.order+"}";
		else
			return "{"+node.ch+", "+node.order+", "+node.weight+"}";
	}

}