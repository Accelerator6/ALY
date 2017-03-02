package test;
import java.util.Scanner;

public class qqqq{	
	public void Diamond(int n){
		
		
		/*
			读取参数n 菱形的上半部分用f1接收 下半部分用f2接收
		*/
		if(n%2==0)
			--n;
		int f1 = n/2+1;
		int f2 = n/2;
		int i ,j,k,m,q;
		for(i=1;i<=f1;i++){	//共有f1次外层循环，用来刻画菱形的上半部分
			for(m=0;m<f1-i;m++){	//输出空格   
				System.out.print(" ");
			}
			for(q=1;q<=2*(i-1)+1;q++){
				System.out.print("*");
			}
			System.out.println();
		}
		for(i=1;i<=f2;i++){
			for(m=0;m<i;m++){
				System.out.print(" ");
			}
			for(q=1;q<=(f2-i)*2+1;q++){
				System.out.print("*");
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
		int  n;
		Scanner sc = new Scanner(System.in);
		System.out.println("Please input the Diamond layer :");
		n = sc.nextInt();
		qqqq qqqq =new qqqq();
		qqqq.Diamond(n);
	}
}
