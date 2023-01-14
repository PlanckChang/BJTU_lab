public class Main {
    public static void main(String[] args) {
        con X = new con();
        X.p = X.generate_node();
        X.p.x = 1;
        X.p.next = X.generate_node();
        X.p.next.x = 2;
        X.p.next.next = X.generate_node();
        X.p.next.next.x = 3;

        for (int i=0; i<50; ++i){
            X.a[i] = 4+i;
        }

//        var item = X.begin();
//        while(item.isNotEqual(X.end())){
//            System.out.println(item.getitem());
//        }

        System.out.println("Hello world!");
    }
}



// todo

class con{
    public node p;
    public int[] a = new int[50];
    public con(){p = null;}

    public void newP(){
        p = new node();
    }
    public void setX(int a){
        p.x = a;
    }

//    public class Iterator{
//        public con pp;
//        public node pEle;
//        public int now;
//        public Iterator(con p1, int b){
//            if( b==0){
//                pp = p1;
//                pEle = p1.p;
//                if(pEle==null){
//                    now = 0;
//                }
//                else now = -1;
//            }
//            else if( b==1){
//                pp = p1;
//                pEle = null;
//                now = 50;
//            }
//        }
//        public int next(){
//            if(pEle!=null && pEle.next !=null){
//                pEle = pEle.next;
//            }
//            else {
//                now ++;
//            }
//            return getitem();
//        }
//
//        public int getitem(){
//            if(now < 0){
//                return pEle.x;
//            }
//            else{
//                return pp.a[now];
//            }
//        }
//
//        public boolean isEqual( Iterator A){
//            return A.pEle == pEle && A.now == now;
//        }
//
//        public boolean isNotEqual(Iterator A){
//            if(A.now == now){
//                return false;
//            }
//            return A.now != now || A.pEle != pEle;
//        }
//    };
    public static class  node{
        public node next;
        public int x;
    }

//    Iterator begin(){
//        Iterator iter =  new Iterator(this, 0);
//        return iter;
//    }
//
//    Iterator end(){
//        Iterator iter = new Iterator(this, 1);
//        return iter;
//    }

    void print(int a){
        System.out.println(a);
    }

    node generate_node(){
        return new node();
    }
}

