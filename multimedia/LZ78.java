package Multimedia;

import java.util.*;

public class LZ78 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		System.out.print("Enter text to be compressed: ");
		String str = s.nextLine();
		
		System.out.println();
		System.out.println("COMPRESSION");
		System.out.println();
		
		HashMap<String,Integer> map = new HashMap<>();
		ArrayList<pair> codeGenerated = new ArrayList<>();
		int code = 1;
		int i = 0;
		while(i<str.length())
		{
			int j = i;
			String temp = "";
			while(j<str.length())
			{
				temp += str.charAt(j);
				if(map.containsKey(temp) && j<str.length()-1)
				{
					j++;
					continue;
				}
				else if(map.containsKey(temp))
				{
					codeGenerated.add(new pair(map.get(temp),'-'));
					break;
				}
				else
				{
					map.put(temp, code);
					code++;
					if(temp.length()==1)
						codeGenerated.add(new pair(0,str.charAt(j)));
					else
						codeGenerated.add(new pair(map.get(temp.substring(0,temp.length()-1)),str.charAt(j)));
					break;
				}
			}
			i = j+1;
		}
		System.out.println("Output");
		for(i=0;i<codeGenerated.size();i++)
			System.out.println(codeGenerated.get(i).pcode+" "+codeGenerated.get(i).cc);
		
		System.out.println();
		System.out.println("DECOMPRESSION");
		System.out.println();
		
		String test = "";
		for(i=0;i<codeGenerated.size();i++)
		{
			pair p = codeGenerated.get(i);
			char cc = p.cc;
			String temp = "";
			while(p.pcode!=0)
			{
				temp = codeGenerated.get(p.pcode-1).cc + temp;
				p = codeGenerated.get(p.pcode-1);
			}
			
			test += temp+cc;
		}
		System.out.println("Output");
		System.out.println(test);
	}
	
	public static class pair{
		int pcode;
		char cc;
		
		pair(int pcode, char cc)
		{
			this.pcode = pcode;
			this.cc = cc;
		}
	}

}
