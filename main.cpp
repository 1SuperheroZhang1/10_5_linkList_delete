#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;//数据域
    struct LNode* next;//指针域 用于指向下一个节点
}LNode,*LinkList;
//LNode*和LinkList完全等价

//头插法新建链表
void list_head_insert(LNode* &L){
    //带头结点的链表
    L=(LNode*)malloc(sizeof(LNode));//申请头结点空间，头指针指向头节点
    L->next=NULL;//L->data中没放数据
    ElemType x;
    scanf("%d",&x);//从标准输入读取数据
    LNode* s;//用来指向申请的新节点
//    s=(LinkList) malloc(sizeof(LNode));
//    s->data=x;
//    s->next=NULL;
//    L->next=s;//头结点的next指向第一个节点
    while(x!=9999){
//        scanf("%d",&x);
        s=(LinkList)malloc(sizeof(LNode));//申请一个新空间给s，强制类型转换
        s->data=x;//把读取到的值，给新空间中的data成员
        s->next=L->next;//s的next指向原链表的第一个结点，让新节点的next指针指向链表的第一个元素
        L->next=s;//头结点的next指针，指向新结点 让s作为第一个元素
        scanf("%d",&x);//读取标准输入
    }
}

//尾插法新建链表
void list_tail_insert(LNode* &L){
    L=(LinkList) malloc(sizeof(LNode));//申请头结点空间，头指针指向头结点
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LNode *s,*r=L;//s是用来指向申请的新节点，r始终指向链表尾部
    while(x!=9999){
        s=(LinkList) malloc(sizeof(LNode));//为新节点申请空间
        s->data=x;
        r->next=s;//让尾部结点指向新结点
        r=s;//r要指向新的尾部
        scanf("%d",&x);
    }
    r->next=NULL;//让尾结点的next为NULL
}

/*
 * 因为单链表只能从前往后遍历，不能像顺序表那样拿某个位置可以直接到达，
 * 顺序表的按位置获取元素时间复杂度为O(1)，但是链表位置查找的时间复杂度是O(n)
 * 链表按值查找的时间复杂度是O(n)
 * */
//单链表按序号查找结点值，NULL代表查找的结点不存在
LinkList searchByLocation(LinkList L,int pos){
    int i=0;
    if(pos<1){
        return NULL;
    }
    while(L&&i<pos){
        L=L->next;
        i++;
    }
    return L;
}

//按值查找，返回NULL代表没找到
LinkList searchByValue(LinkList L,ElemType searchValue){
    while(L){
        if(L->data==searchValue){//如果找到对应的值，就返回那个结点的地址
            return L;
        }
        L=L->next;
    }
    return NULL;
}

//在第i个位置插入元素
bool listInsertByIndex(LinkList L,int index,ElemType e){
    LinkList p= searchByLocation(L,index-1);//查找第index-1个元素的地址
    if(NULL==p){
        return false;
    }
    LinkList q;//用来存储将要插入的节点
    q=(LinkList) malloc(sizeof(LNode));//为新插入的结点申请空间
    q->data=e;
    q->next=p->next;
    p->next=q;
    return true;
}

//打印链表中每个结点的值
void print_list(LinkList L){
    L=L->next;
    while(L!=NULL){//NULL是为了代表一张空的藏宝图
        printf("%3d",L->data);//打印当前节点的数据
        L=L->next;//指向下一个结点
    }
    printf("\n");
}

//删除链表第i个结点
//删除时不会改变头指针L，所以不需要加引用
bool list_delete(LinkList L,int index){//index代表要删除的元素的位置
    LinkList p= searchByLocation(L,index-1);//存放要删除结点的前一个结点
    if(NULL==p){
        return false;
    }
    LinkList q;//用来存储要删除的结点地址
    q=p->next;
    p->next=q->next;//断链
    free(q);//释放被删除结点的空间
    return true;
}
int main() {

    LinkList L;//链表头指针，是结构体指针类型
    LinkList search;//用来存放查找的第一个结点
    //头插法新建链表
//    list_head_insert(L);//输入数据可以是3 4 5 6 7 9999，
    //尾插法新建链表
    list_tail_insert(L);
    //打印链表
    print_list(L);
    //单链表按序号查找结点值
//    search=searchByLocation(L,2);
//    if(search!=NULL){
//        printf("Succeeded in searching by serial number\n");
//        printf("%d\n",search->data);
//    }
    //按值查找
//    search=searchByValue(L,6);//按值查找
//    if(search!=NULL){
//        printf("Search by value succeeded\n");
//        printf("%d\n",search->data);
//    }
    //在第i个位置插入元素
//    bool ret;
//    ret=listInsertByIndex(L,2,99);//新结点插入到第index个位置
//    if(ret){
//        print_list(L);
//    }
    //删除链表第i个节点
    list_delete(L,2);//删除第2个结点
    //打印链表
    print_list(L);
    return 0;
}



