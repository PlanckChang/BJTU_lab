
public class test{
    interface Arithmetic{
        public abstract int operation(int a, int b);
    }


    static class Add implements Arithmetic{
        public int operation(int a, int b) {
            return a+b;
        }
    }

    static class Subtract implements Arithmetic{
        public int operation(int a, int b){
            return a-b;
        }
    }

    interface Factory {
        public abstract Arithmetic create();
    }

    static class Factory_Add implements Factory{
        public Arithmetic create(){
            return new Add();
        }
    }
    static class Factory_Subtract implements Factory{
        public Arithmetic create(){
            return new Subtract();
        }
    }

    public static void main(String[] args) {
        Factory factoryAdd = new Factory_Add();
        Factory factorySubtract = new Factory_Subtract() ;
        int add = factoryAdd.create().operation(4, 4);
        int subtract = factorySubtract.create().operation(5, 3);
        System.out.println(add);
        System.out.println(subtract);
        return;
    }
}
