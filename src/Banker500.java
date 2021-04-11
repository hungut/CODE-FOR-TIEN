public class Banker500 extends Banker {
    public Banker500() {
        super(500,0);
    }
    @Override
    public void showInf() {
        System.out.println("A amount bills of 500: " + this.count);
    }
}
