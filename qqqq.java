package test;
import java.util.Scanner;

public class qqqq{	
	public void Diamond(int n){
		
		
		/*
			��ȡ����n ���ε��ϰ벿����f1���� �°벿����f2����
		*/
		if(n%2==0)
			--n;
		int f1 = n/2+1;
		int f2 = n/2;
		int i ,j,k,m,q;
		for(i=1;i<=f1;i++){	//����f1�����ѭ���������̻����ε��ϰ벿��
			for(m=0;m<f1-i;m++){	//�����һ�οո�   
				System.out.print(" ");
			}
			System.out.print("*");  //������ε����
			for(q=1;q<=2*i-3;q++){
				System.out.print(" ");//����ڶ��οո�   
			}
			if (i==1) {
				System.out.println("");
			}
			else {
				System.out.println("*");
			}

		}
		for(i=1;i<=f2;i++){			//����f2��ѭ�� �������̻��°벿��
			for(m=0;m<i;m++){
				System.out.print(" ");
			}
			System.out.print("*");  //������ε����
			for(q=1;q<=(f2-i)*2-1;q++){
				System.out.print(" ");
			}
			if(i==f2){
				System.out.println("");
			}
			else {
				System.out.println("*");
			}
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