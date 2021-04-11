//create chain of Handler
public class AppBanker {
    public static Banker start;
    public  Banker getBanker() {
        Banker level_500 = new Banker500();//0
        Banker level_200 = level_500.setNext(new Banker200());//1
        Banker level_100 = level_200.setNext(new Banker100());//2
        Banker a1=level_100.setNext(new Banker50());//3
        a1.setNext(level_500);
        start=level_500;
        return level_500;
    }
    public void showAll(){
        int a=4;
        while(a!=0){
            start.showInf();
            start=start.nextbanker;
            a--;
        }
    }
}
//This case:500 Level(500)-->200 level(200)-->100 Level(100)-->20 Level(20)
//Handler1 print:Numbers of 500 cash +count
//Handler2 print:File logger +msg
//Handler3 print:Email logger +msg
