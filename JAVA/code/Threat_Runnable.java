package Monday;
/*
 * 第二种方法创建线程
 * 1：自定义MyRunnable实现Runnable接口
 * 2：重写run()方法
 * 3：创建MyRunnable类的对象
 * 4：创建Thread类的对象 并把3中的对象作为构造参数传递
 */
public class monday {
	public static void main(String[] args) {
		MyRunnable myRunnable = new MyRunnable();
		Thread t1 = new Thread(myRunnable, "李和平");
		Thread t2 = new Thread(myRunnable,"艾璐瑶");
		
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
