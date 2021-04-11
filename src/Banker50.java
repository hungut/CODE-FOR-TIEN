public class Banker50 extends Banker {
    public Banker50() {
        super(50, 0);
    }
        


    @Override
    public void showInf() {
        System.out.println("A amount bills of 50: " + this.count);
    }

    
}
