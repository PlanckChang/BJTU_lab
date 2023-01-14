public class adapter_class {
    public static void main(String[] args){
        Target adapter = new Adapter();
        adapter.request();
    }
}

interface Target{
    public void request();
}

class Adaptee{
    public void specificRequest(){
        System.out.println("Adaptee specificRequest func is called");
    }
}

class Adapter extends Adaptee implements Target {
    public void request(){
        super.specificRequest();
    }
}