public class Main {
    abstract static class CarController{
        public void move(){
            System.out.println("this is car move func");
        }
        public abstract void phonate();
        public abstract void twinkle();
    }
    static class PoliceSound{
        public void alarmSound(){
            System.out.println("this is police alarm sound");
        }
    }
    static class PoliceLamp{
        public void alarmLamp(){
            System.out.println("this is police alarm lamp");
        }
    }
    static class PoliceCarAdapter extends CarController{
        private PoliceSound sound;
        private PoliceLamp lamp;
        public PoliceCarAdapter(){

            lamp = new PoliceLamp();
            sound = new PoliceSound();
        }
        public void phonate(){
            sound.alarmSound();
        }
        public void twinkle(){
            lamp.alarmLamp();
        }
    }


    public static void main(String[] args) {
        PoliceCarAdapter adapter = new PoliceCarAdapter();
        adapter.phonate();
        adapter.twinkle();
    }

}