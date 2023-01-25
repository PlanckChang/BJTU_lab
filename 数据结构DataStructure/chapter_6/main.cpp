#include <cstdio>
#include <cstdlib>
#include <cstring>



typedef struct BiTNode
{
    char data;
    BiTNode *lchild, *rchlid;
};

int top = -1;

void visit_tree(BiTNode *p){
    printf("%c ", p->data);
}


//6.1
int creat_BiTree(BiTNode *T)
{
    char ch;
    scanf("%c",&ch);
    if(ch == '!')
    {
        T=NULL;
    }
    else
    {
        if(!(T = (BiTNode*) malloc(sizeof(BiTNode))))
            exit(0);
        T->data = ch;
        creat_BiTree(T->lchild);
        creat_BiTree(T->rchlid);
    }
    return 1;
}

//6.2 (1)
void preorder(BiTNode *T)
{
    if(T)
    {
        visit_tree(T);
        preorder(T->lchild);
        preorder(T->rchlid);
    }
}

//6.2 (2)
void inorder(BiTNode *T)
{
    if(T)
    {
        inorder(T->lchild);
        visit_tree(T);
        inorder(T->rchlid);
    }
}

//6.2 (3)
void postorder(BiTNode *T)
{
    if(T)
    {
        postorder(T->lchild);
        postorder(T->rchlid);
        visit_tree(T);
    }
}

//6.3
void push(BiTNode **a, BiTNode *elem)
{
    a[++top] = elem;
}
void pop()
{
    if(top == -1)
        return;
    --top;
}
BiTNode * getTop(BiTNode **a)
{
    return a[top];
}

void inOrderTraverse(BiTNode *T)
{
    BiTNode *a[200];
    BiTNode *p;
    push(a, T);
    while(top!=-1)
    {
        while((p = getTop(a))&& p){
            push(a ,p->lchild); // has no lchild, thus push NULL to stack
        }
        pop(); // 压栈到最后就是null when circulation ending, the top elem is certainly NULL
        if(top != -1)
        {
            p = getTop(a);
            pop();
            visit_tree(p);
            push(a, p->rchlid);
        }
    }
}
//6.4(2) 6.5(2)
void show_bitree(BiTNode *T)
{
    if(T==NULL) printf("*");
    else
    {
        printf("%c", T->data);
        printf("(");
        show_bitree(T->lchild);
        printf(" ");
        show_bitree(T->rchlid);
        printf(")");
    }
}

// 6.5
char * cut_string(char *string, int start, int count)
{
    char *tem= (char*) malloc(sizeof(char)*11);
    for(int i= start, j =0; j<count; ++i, ++j)
    {
        tem[j] = string[i];
    }
    tem[count] = '\0';
    return tem;
}


BiTNode * in_post_to_bitree(char *in, char *post)
{
    if(strlen(in) == 0) return NULL;
    BiTNode *tem = (BiTNode *) malloc(sizeof (BiTNode));
    char p= post[strlen(post)-1];
    tem->data = p;

    for(int i=0; i<strlen(in) ; ++i)
    {
        if(p == in[i])
        {
            if(i == 0) tem->lchild =NULL;
            else
                tem->lchild = in_post_to_bitree(cut_string(in, 0, i), cut_string(post, 0, i));
            if(i == strlen(in)-1) tem->rchlid = NULL;
            else
                tem->rchlid = in_post_to_bitree( cut_string( in, i+1, strlen(in)-i-1), cut_string(post, i, strlen(in)-i-1));
            break;
        }
    }
    return tem;
}

//6.6

// 6.5 6.6 use the same cut_string function

BiTNode * pre_in_to_tree(char *pre, char*in)
{
    if(strlen(pre) == 0 ) return NULL;
    BiTNode * tem = (BiTNode *) malloc(sizeof (BiTNode));
    char p= pre[0];
    tem->data = p;

    for(int i=0 ; i<strlen(in); ++i)
        if(p== in[i])
        {
            if(i==0) tem->lchild=NULL;
            else
                tem->lchild = pre_in_to_tree( cut_string(pre, 1, i), cut_string(in, 0, i));
            if(strlen(in)==i+1) tem->rchlid= NULL;
            else
                tem->rchlid = pre_in_to_tree( cut_string( pre, i+1, strlen(pre)-i-1), cut_string(in, i+1, strlen(in)-i-1));
            break;
        }
    return tem;
}

//6.7
// by traversing the level_ and in_, find the lchild' level_ and rhcild's level_. then recursive it
BiTNode * level_in_to_bitree(char *level, char *in)
{
    if(strlen(level) == 0 ) return NULL;
    BiTNode * tem = (BiTNode*) malloc(sizeof (BiTNode));
    char left[15];
    char right[15];
    int count_left;
    int count_right;
    count_left = count_right=0;

    tem->data = level[0];
    char p = level[0];

    for(int i =0; i<strlen(in); ++i)
    {
        if(in[i] == p)
        {
            for(int j=1; j<=strlen(level); ++j )
            {
                int flag=0;
                for(int k=0; k<i; ++k){
                    if(level[j] == in[k])
                    {
                        left[count_left++] = level[j];
                        flag = 1;
                        break;
                    }
                }
                if(flag ==0){
                    right[count_right++] = level[j];
                }
            }

            //if(count_left == i) break;
//
//            for(int j=1; j<=strlen(level); ++j )
//                for(int k=i+1; k<=strlen(in)-1; ++k)
//                    if(level[j] == in[k])
//                        {
//                        right[count_right++] = level[j];
//                        break;
//                        }

            //if(count_right == strlen(in)-i-1) break;
            left[count_left]= '\0';
            right[count_right] = '\0';

            tem->lchild = level_in_to_bitree(left, cut_string(in, 0, i));
            tem->rchlid = level_in_to_bitree(right, cut_string(in, i+1 , strlen(in)-i-1));
            break;
        }
    }
    return tem;
}

//6.8
void level_traversal(BiTNode *T)
{
    BiTNode queue[100];
    int front, rear;
    front = rear =0;
    BiTNode tem;
    if(T == NULL) return;
    else
    {
        queue[rear] = *T;
        ++  rear;
        do {
            tem = queue[front];
            printf("%c ", tem.data);
            ++ front;
            if(tem.lchild != NULL)
            {
                queue[rear] = *tem.lchild;
                ++ rear;
            }
            if(tem.rchlid != NULL)
            {
                queue[rear] = *tem.rchlid;
                ++rear;
            }
        } while (front != rear);
    }
}

//6.9
int depth(BiTNode *T)
{
    if(!T) return 0;
    else
    {
        int left = depth(T->lchild);
        int right = depth(T->rchlid);
        return 1 + (left >= right ? left : right);
    }
}

//6.10
    typedef struct PTNode
    {
        char data;
        int parent;
    }PTNode;

    typedef struct PTree
    {
        PTNode nodes[20];
        int r, n;
    };

    typedef struct CSNode
    {
        char data;
        struct CSNode * first_child, *next_sibling;
    };
    ///
    /// \param T
    /// \return
    CSNode * creat_cstree_by_ptree(PTree *T)
    {
        CSNode *tem[15];
        CSNode *p, *q;
        int parent;
        if(T->n <= 0) return NULL;

        for(int i=0; i<T->n; ++i)
        {
            p = (CSNode* ) malloc(sizeof (CSNode));
            p->data = T->nodes[i].data;
            p->first_child = p->next_sibling =NULL;
            parent = T->nodes[i].parent;
            if(parent != -1)
            {
                if(tem[parent]->first_child == NULL) tem[parent]->first_child = p;
                else {
                    q = tem[parent]->first_child;
                    while(q->next_sibling != NULL)
                    {
                        q = q->next_sibling;
                    }
                    q->next_sibling = p;
                }
            }
            tem[i] = p;
        }
        return tem[0];
    }

void show_cstree(CSNode *T)
{

//    if(T==NULL) return;
////  recursion is not perfect
//    else  printf("%c", T->data);
//    show_cstree(T->next_sibling);
//    show_cstree(T->first_child);
//
    CSNode tem[30];
    int front, rear;
    front =rear =0;
    CSNode p;
    if(T == NULL) return;
    else
    {
            tem[rear] = *T;
            ++rear;
        do {
            p = tem[front];
            ++front;
            printf("%c ", p.data);
            if(p.first_child == NULL) continue;
            else
            {
                p = *p.first_child;
                tem[rear] = p;
                ++rear;
            }
            while (p.next_sibling != NULL) {
                tem[rear] = *p.next_sibling;
                ++rear;
                p = *p.next_sibling;
            }
        } while (front <rear);
    }
}

//6.11
int depth_tree_cs(CSNode * T){
    if(T == NULL) return 0;
    else{
        int depth = depth_tree_cs(T->first_child);
        while(T->next_sibling)
        {
            int count = depth_tree_cs(T->next_sibling);
            if(count > depth) depth = count;
            return depth; // the same level return, need not to plus one
        }
        return depth+1;// finish one level then depth plus one
    }
}

//6.12
typedef struct DTree{
        char data;
        int degree;
    };
CSNode * creat_by_tree_degree(DTree * T, int n)
{
    if(!T) return NULL;
    CSNode *tem = (CSNode*) malloc(sizeof(CSNode) * n);
    int index=1;
    for(int i =0; i<n; ++i)
    {
        tem[i].data = T[i].data;
        tem[i].next_sibling = tem[i].first_child =NULL;
    }

    for(int i=0; i<n; ++i){
        int degree = T[i].degree;
        if(degree == 0) index++;
        else if(degree == 1)
        {
            tem[i].first_child = &tem[index++];
        }
        else if(degree >1)
        {
            tem[i].first_child = &tem[index++];
            for (int j=0; j<degree-1; ++j){
                tem[index-1].next_sibling = &tem[index++];
            }
        }
    }
    return &tem[0];
}

int main() {
//    6.4
//    char pre[20];
//    strcpy(pre,"EBADCFHGIKJ");
//    char in[20];
//    strcpy(in, "ABCDEFGHIJK");
//    BiTNode *T;
//    T = pre_in_to_tree( pre, in);
//   inorder(T);
//    printf("\n");
//
//    printf("\n");
//    strcpy(pre, "ABCDGEIHFJK");
//    strcpy(in, "DCBGEAHFIJK");
//    T = pre_in_to_tree(  pre, in);
//    inorder(T);]
//    char str[20];
//    int count;
//    do {
//        scanf("%s", &str);
//        count ++;
//    }while(getchar()!='\n');
//    printf("%d", count);
//
//    show_bitree(T);
//    printf("\n");
//    level_traversal(T);
//    printf("\n");
//    printf("%d", depth(T));

//
// //   6.10
//    PTNode general_tree[10];
//    PTree pTree;
//    CSNode * CST;
//    general_tree[0].data = 'R';
//    general_tree[0].parent = -1;
//    for(int i = 1; i<=9; ++i)
//    {
//        general_tree[i].data = 'A' +i-1 ;
//    }
//    general_tree[1].parent = general_tree[2].parent =
//    general_tree[3].parent =0;
//    general_tree[4].parent = general_tree[5].parent =1;
//    general_tree[6].parent = 3;
//    general_tree[7].parent = general_tree[8].parent =
//    general_tree[9].parent = 6;
//    for(int i = 0; i< 10; ++i)
//        pTree.nodes[i] = general_tree[i];
//    pTree.n=10;
//    pTree.r = 0;
//    CST =  creat_cstree_by_ptree(&pTree);
//    show_cstree(CST);

//    //6.10 sample two
//    PTree pTree1;
//    pTree1.n =11;
//    pTree1.r = 0;
//    pTree1.nodes[0].data = 'R';
//    pTree1.nodes[0].parent = -1;
//    for(int i=1; i<=11; ++i)
//    {
//        pTree1.nodes[i].data = 'A'+i -1;
//    }
//
//    pTree1.nodes[1].parent = 0;
//    pTree1.nodes[2].parent = 0;
//    pTree1.nodes[3].parent = 0;
//    pTree1.nodes[4].parent = 2;
//    pTree1.nodes[5].parent = 2;
//    pTree1.nodes[6].parent = 2;
//    pTree1.nodes[7].parent = 3;
//    pTree1.nodes[8].parent = 6;
//    pTree1.nodes[9].parent = 7;
//    pTree1.nodes[10].parent = 9;
//    CSNode* CST = creat_cstree_by_ptree(&pTree1);
//    show_cstree(CST);
//    printf("\n%d",depth_tree_cs(CST));

////6.5
//char in[15] = "DCBGEAHFIJK";
//char post[15] = "DCEGBFHKJIA";
//BiTNode *T = in_post_to_bitree(in, post);
//show_bitree(T);
//
////6.7
//char level[15] ="ABCDEFGHIJ";
//char in[15] = "DBGEHJACIF";
//BiTNode * T = level_in_to_bitree(level, in);
//show_bitree(T);

//6.12
int n=8;
DTree dtree[8];
dtree[0].data = 'R';
dtree[0].degree = 3;
for(int i=1; i<=8; ++i)
{
    dtree[i].data = 'A' +i -1;
}
dtree[1].degree = dtree[3].degree = 1;
dtree[2].degree = 2;
dtree[4].degree = dtree[5].degree =dtree[6].degree =dtree[7].degree= 0;

    CSNode *T = creat_by_tree_degree(dtree, n);
    show_cstree(T);
}
