package hello;

import java.util.Scanner;

public class string_many {
	public static void main(String[] args) {
		//读取一行字符串
		Scanner s = new Scanner(System.in);
		System.out.println("Please input a String:");
		String get = s.nextLine();
		System.out.println();
		
		//将大写转化为小写
		
		get = get.trim().toLowerCase();
		//用一个数组存储每一位出现的次数  如 a的次数储存在num[0]中
		int[] num = new int [26];
		int max = 0;
		
		for(int i = 0;i < get.length();i++){
			
			//用ch 接收get中的每一个字符
			char ch = get.charAt(i);
			if(ch==' ') continue;
			
			
			//index找寻坐标  储存次数
			int  index = ch - 'a';
			if (index>=0&&index<=26) {
				num[index]++;	
				if(num[index]>max)
					max = num[index];
			}
		}
			while(max != 0){
				System.out.print("\t"+max+"  ");
				for(int j : num){
					if(j>=max){
						System.out.print("@");					
					}
					else System.out.print(" ");
				}
				System.out.println();
				max--;
			}
			System.out.print("\t   ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		
	}
}
