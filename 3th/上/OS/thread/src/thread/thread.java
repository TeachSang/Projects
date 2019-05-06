package thread;

public class thread {
	public static void main(String[] args) {
		CreateThread t = new CreateThread();
		for (int i = 0; i < 10; i++) {
			new Thread(t).start();
		}
	}
}
