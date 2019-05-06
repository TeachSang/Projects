package thread;

public class CreateThread implements Runnable{
	private String name;
	private int money = 0;
	
	public void run() {
		String a = Thread.currentThread().getName();
		int b = Integer.parseInt(a.substring(a.length()-1));
		/*System.out.println(b);*/
		if(b%2 == 0) {			
			V(money);
			System.out.println(Thread.currentThread().getName()+" money is: "+ money);
		}
		else {	
			P(money);
			System.out.println(Thread.currentThread().getName()+" money is: "+ money);
		}
	}
	public synchronized void P(int count) {
		count++;
		if(count<=0) {
			try {
				System.out.println("waiting");
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}            
		}
	}
	public synchronized void V(int count) {
		count--;
		if(count>=10) {
			try {
				System.out.println("waiting");
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
