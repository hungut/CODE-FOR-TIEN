//abstract for each Handler
public abstract class Banker {
    protected int money;
    protected int count;
    protected Banker nextbanker; // The next Handler in the chain

    public Banker(int money, int amount) {
        this.money = money;
        this.count = amount;
    }
 
    // Set the next logger to make a list/chain of Handlers.
    public Banker setNext(Banker nextbanker) {
        this.nextbanker = nextbanker;
        return nextbanker;
    }
 
    public void doDraw(int Amount){
        if(Amount==0) {
            return;
        }
        if(this.canDraw(Amount)) {
            Amount-=this.money;
            this.count++;
        }
        nextbanker.doDraw(Amount);
    }

    public boolean canDraw(int amount){
        return (amount >= this.money);
    }

    public abstract void showInf();
}
