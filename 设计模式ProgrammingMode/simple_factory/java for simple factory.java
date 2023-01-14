
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

    static class Factory{
        public static Arithmetic create(int i){
            Arithmetic tem;
            switch (i){
                case 1:
                    tem = new Add();
                    break;
                case 2:
                    tem = new Subtract();
                    break;
                default:
                    tem = null;
            }
            return tem;
        }
    }

    public static void main(String[] args) {
        Factory factory = new Factory();
        int add = factory.create(1).operation(4, 4);
        int subtract = factory.create(2).operation(5, 3);
        System.out.println(add);
        System.out.println(subtract);
        return;
    }
}