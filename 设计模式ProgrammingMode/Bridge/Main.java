public class Main {
    public static void main(String[] args) {
        Brush brush = new BigBrush();
        brush.setColor(new Red());
        brush.paint();
    }
}

abstract class Color{
    public abstract void useColor();
}

class Red extends Color{
    public void useColor(){
        System.out.println("this is red");
    }
}

abstract class Brush{
    public Color color;
    public void setColor(Color color1){
        color = color1;
    }
    public abstract void paint();
}

class BigBrush extends Brush{
    @Override
    public void paint() {
        System.out.println("bigbrush is painting ");
        color.useColor();
    }
}