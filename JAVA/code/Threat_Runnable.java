package Monday;
/*
 * �ڶ��ַ��������߳�
 * 1���Զ���MyRunnableʵ��Runnable�ӿ�
 * 2����дrun()����
 * 3������MyRunnable��Ķ���
 * 4������Thread��Ķ��� ����3�еĶ�����Ϊ�����������
 */
public class monday {
	public static void main(String[] args) {
		MyRunnable myRunnable = new MyRunnable();
		Thread t1 = new Thread(myRunnable, "���ƽ");
		Thread t2 = new Thread(myRunnable,"�����");
		
		Thread.currentThread().setName("test demo");
		
		for(int x=0;x<5;x++){
			System.out.println(Thread.currentThread().getName()+x);
		}
		
		t1.start();
		t2.start();

	}
}


class MyRunnable implements Runnable {
	public void run() {
		for(int x=0;x<50;x++){
			System.out.println(Thread.currentThread().getName()+x);
		}
	}
}
