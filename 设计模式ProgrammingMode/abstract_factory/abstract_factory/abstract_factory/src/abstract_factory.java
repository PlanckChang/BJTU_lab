
public class abstract_factory{
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

    public class Factory {
        public Arithmetic create_add() {
            return new Add();
        }

        public Arithmetic create_subtract(){
            return new Subtract();
        }
    }

    public class Factory_Add extends Factory{
        public Arithmetic create_add(){
            return new Add();
        }
    }
    public class Factory_Subtract extends Factory{
        public Arithmetic create_subtract(){
            return new Subtract();
        }
    }

    public void main(String[] args) {
        Factory factory = new Factory();
        int add = factory.create_add().operation(4, 4);
        int subtract = factory.create_subtract().operation(5, 3);
        System.out.println(add);
        System.out.println(subtract);
        return;
    }
}