public class Banker200 extends Banker {
    public Banker200() {
        super(200,0);
    }
 
    @Override
    public void showInf() {
        System.out.println("A amount bills of 200: " + this.count);
    }
}
