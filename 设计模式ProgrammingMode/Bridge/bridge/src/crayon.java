public class crayon {
    public static void main(String[] args){
        Crayon redBig = new RedBigCrayon();
        Crayon blueSmall = new BlueSmallCrayon();
        redBig.paint();
        blueSmall.paint();
    }
}

class Crayon{

    protected String size;
    protected String color;
    public void paint() {
        System.out.println(size + color + " is painting");
    }
};

class RedBigCrayon extends Crayon{
    public void setConfig(){
        size = "big";
        color = "red";
        }
    public RedBigCrayon(){
        setConfig();
        }
    };

class BlueSmallCrayon extends Crayon{
    public void setConfig(){
        size = "small";
        color = "blue";
        }
    public BlueSmallCrayon(){
        setConfig();
        }
    };