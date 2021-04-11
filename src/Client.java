import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        // Build the chain of responsibility
        AppBanker s1=new AppBanker();
        Banker banker = s1.getBanker();
        Scanner scanner = new Scanner(System.in);

        System.out.println("So tien nhap la boi cua 50:");
        int money = scanner.nextInt();
        banker.doDraw(money);
        s1.showAll();
        scanner.close();
    }  
}
