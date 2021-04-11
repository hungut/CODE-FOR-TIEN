public class Banker100 extends Banker {
    public Banker100() {
        super(100,0);
    }
 
    @Override
    public void showInf() {
        System.out.println("A amount bills of 100: " + this.count);
    }
}
