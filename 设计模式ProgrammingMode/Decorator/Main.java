



public class Main {
    public static void main(String[] args) {
        Component window = new Window();
        ComponentDecorator black_decorator = new BlackBorderDecorator(window);
        black_decorator.display();

    }
}


abstract class Component{
    abstract public void display();
}

class Window extends Component{
    public void display(){
        System.out.println("window display");
    }
}

class ComponentDecorator extends Component{
    private Component component;
    public void display(){
        component.display();
    }
    public ComponentDecorator(Component component1){
        component = component1;
    }
}

class BlackBorderDecorator extends ComponentDecorator{
    public BlackBorderDecorator(Component component1){
        super(component1);
    }
    public void setBlackBorder(){
        System.out.println("black border");
    }
    public void display(){
        super.display();
        setBlackBorder();
    }
}