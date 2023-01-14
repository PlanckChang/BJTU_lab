#include <iostream>
#include <algorithm>

using namespace std;

struct node{
    node *next = NULL;
    int x;
};

ostream &operator <<(ostream &out, node &now){
    out << now.x;
    return out;
}

class con{
public:
    node *p;
    int a[50];

    class Iterator {
    public:
        con *pp;
        node *pEle;
        int now;

        Iterator(con *p1 = NULL, int b = 0) {
            if (b == 0) {
                pp = p1;
                pEle = p1->p;
                if (pEle == NULL) {
                    now = 0;
                } else now = -1;
            }
            else if (b == 1) {
                pp = p1;
                pEle = NULL;
                now = 50;
            }
        }

        Iterator &operator++() {
            if (pEle->next != NULL && pEle != NULL) {
                pEle = pEle->next;
            } else {
                now++;
            }
            return *this;
        }

        Iterator operator++(int) {
            Iterator itnow = *this;
            if (pEle != NULL && pEle->next != NULL) {
                pEle = pEle->next;
            } else now++;

            return itnow;
        }

        int &operator*() {
            if (now < 0) {
                return pEle->x;
            }
            else
                return pp->a[now];
        }

        bool operator!=(const Iterator &A) const{
            if(A.now == now){
                return false;
            }
            return A.now!=now || A.pEle != pEle;
        }

        bool operator == (const Iterator &A){
            return A.pEle == pEle && A.now == now;
        }
    };

    Iterator begin(){
        Iterator iter(this, 0);
        return iter;
    }

    Iterator end(){
        Iterator iter(this, 1);
        return iter;
    }

    static void out (int a){
        cout << a << endl;
    }
};

int main(){
    con X;
    X.p = new node;
    X.p->x = 1;
    X.p->next = new node;
    X.p->next->x = 2;
    X.p->next->next = new node;
    X.p->next->next->x = 3;
    for(int i=0; i< 50;++i){
        X.a[i] = 4+i;
    }

    for_each(X.begin(), X.end(), con :: out);

    return 0;
}