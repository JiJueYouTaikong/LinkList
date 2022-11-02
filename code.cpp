#include <iostream>

typedef struct LNode
{
    int data;
    struct LNode *next;

}LNode,*LinkList;

bool InsertLNodebyHead(LinkList& L, int n);               //头插法插入节点
bool InsertLNodebyRear(LinkList& L, int n);               //尾插法插入节点
bool InsertLNodebyRearbyInput(LinkList& L, int n);        //尾插法输入方式插入节点
void PrintLinkList(LinkList& L);                          //遍历输出链表
LinkList UniteLinkList(LinkList& L1, LinkList& L2);       //合并有序链表并返回至L1
LinkList UniteLinkListWithDecrease(LinkList& L1, LinkList& L2);       //合并有序链表为非递增并返回L3
LinkList GettheIntersectionSet(LinkList& L1, LinkList& L2);       //求两个链表的交集并返回至L1
LinkList GettheDifferenceSet(LinkList& L1, LinkList& L2);       //求两个链表的差集并返回至L1
void DeleteTheMinNumber(LinkList& L);       //删除链表最小节点
void DeleteAllTheX(LinkList& L,int x);       //删除链表所有值为x的节点
int main()
{
    LinkList L1,L2;
    //功能：创建基础链表
    //InsertLNodebyHead(L1, 8);
    //InsertLNodebyRear(L2, 8);
    //PrintLinkList(L1); 
    //PrintLinkList(L2);  

    //算法1：合并两个升序链表并返回至L1
    /*InsertLNodebyRearbyInput(L1, 4);
    InsertLNodebyRearbyInput(L2,2);
    UniteLinkList(L1, L2);
    PrintLinkList(L1);*/

    //算法2：合并两个升序链表为非递增并返回L3
    /*InsertLNodebyRearbyInput(L1, 5);
    InsertLNodebyRearbyInput(L2,4);
    PrintLinkList(L1);
    PrintLinkList(L2);
    LinkList L3 = UniteLinkListWithDecrease(L1, L2);
    PrintLinkList(L3);*/
    
    //求两个链表的交集并返回至L1
    /*InsertLNodebyRearbyInput(L1, 5);
    InsertLNodebyRearbyInput(L2, 4);
    PrintLinkList(L1);
    PrintLinkList(L2);
    GettheIntersectionSet(L1, L2);
    PrintLinkList(L1);*/

    //求两个链表的差集并返回至L1
    /*InsertLNodebyRearbyInput(L1, 5);
    InsertLNodebyRearbyInput(L2, 4);
    PrintLinkList(L1);
    PrintLinkList(L2);
    GettheDifferenceSet(L1, L2);
    PrintLinkList(L1);*/

    //删除链表最小节点
    /*InsertLNodebyRearbyInput(L1, 5);
    InsertLNodebyRearbyInput(L2, 3);
    PrintLinkList(L1);
    PrintLinkList(L2);
    DeleteTheMinNumber(L1);
    DeleteTheMinNumber(L2);
    PrintLinkList(L1);
    PrintLinkList(L2);*/

    //删除链表所有值为x的节点
    /*InsertLNodebyRearbyInput(L1, 7);
    InsertLNodebyRearbyInput(L2, 5);
    PrintLinkList(L1);
    PrintLinkList(L2);
    DeleteAllTheX(L1,1);
    DeleteAllTheX(L2,1);
    PrintLinkList(L1);
    PrintLinkList(L2);*/

    return 0;
}

bool InsertLNodebyHead(LinkList& L, int n) //头插法插入节点
{
    L = new LNode;
    L->next = NULL;
    for ( int i = 0; i < n; i++)
    {
        LNode* q = new LNode;
        q->data = i+1;
        q->next = L->next;
        L->next = q;
    }
   
    return true;   

}
bool InsertLNodebyRear(LinkList& L, int n) //尾插法插入节点
{
    L = new LNode;
    L->next = NULL;
    LNode* r = L;
    for (int i = 0; i < n; i++)
    {
        LNode* q = new LNode;
        q->data = i+1;
        r->next = q;
        r = q;
        r->next = NULL;
   
    }
    return true;
}
bool InsertLNodebyRearbyInput(LinkList& L, int n) //尾插法输入方式插入节点
{
    L = new LNode;
    L->next = NULL;
    LNode* r = L;
    int x;
    for (int i = 0; i < n; i++)
    {
        LNode* q = new LNode;
        printf("输入待插入的数据（共%d个）：",n);
        scanf_s("%d", &x);
        q->data = x;
        q->next = NULL;
        r->next = q;
        r = q;
        

    }
    return true;
}
void PrintLinkList(LinkList& L)            //遍历输出链表
{
    LNode* p = L->next;
    for(; p!=NULL;p=p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");

}
LinkList UniteLinkList(LinkList& L1, LinkList& L2) //合并有序链表并返回至L1
{
    LNode* p = L1->next;
    LNode* q = L2->next;
    LNode* rear = L1;
    while (p != NULL && q!= NULL)
    {
        if (p->data < q->data)
        {
            rear->next = p;
            rear = p;
            p = p->next;
        }
        else
        {
            rear->next = q;
            rear = q;
            q = q->next;
        }
    }
    if (p == NULL)
    {
        rear->next = q;
    }
    else
    {
        rear->next = p;

    }
   
    return L1;
}
LinkList UniteLinkListWithDecrease(LinkList& L1, LinkList& L2)       //合并有序链表为非递增并返回至L1
{
    /*
    关键点/错误点：
            1.用L1存放结果，先L1->next = NULL将其断开，防止L1自己的节点往里插入时导致指针死循环
    */
    LNode* p = L1->next;
    LNode* q = L2->next;
    LNode* t = NULL;
    L1->next = NULL;
    while (p != NULL && q != NULL)
    {
        if (p->data <= q->data)
        {
            t = p->next;
            p->next = L1->next;
            L1->next = p;
            p = t;
            /*
            如果不用t来让p后移，直接使用p = p->next，会导致p移动错误，因为此时p已经连接到L3链表
            */
        }
        else
        {
            t = q->next;
            q->next = L1->next;
            L1->next = q;
            q = t;
            
            
        }
    }

    if (p == NULL)
    {
        while (q != NULL)
        {
            t = q->next;
            q->next = L1->next;
            L1->next = q;
            q = t;
        }
     
    }
    else
    {
        while (p != NULL)
        {
            
            t = p->next;
            p->next = L1->next;
            L1->next = p;
            p = t;
            
        }
        //6 7 8 9
        //1 2 3 4
        //      p
    }

    
    return L1;
    //1 2 3 4
    //2 4
}
LinkList GettheIntersectionSet(LinkList& L1, LinkList& L2)       //求两个链表的交集并返回至L1
{
    LNode* p = L1->next;
    LNode* q = L2->next; 
    LNode *t = NULL;
    L1->next = NULL;//将L1断开为空表
    LNode* r = L1;
    while (p != NULL)
    {
        t = p->next;
        q = L2->next;
        /*
         关键点/错误点：
                1.p每次循环后移要借助中间变量指针t
                2.每次循环q指针要重新从链头开始
        */
        while (q != NULL)
        {
            if (p->data == q->data)
            {
                
                p->next = NULL;
                r->next = p;
                r = p;
                break;
            }
            else
            {
                q = q->next;
            }
        }
        p = t;
    }
    return L1;
}
LinkList GettheDifferenceSet(LinkList& L1, LinkList& L2)       //求两个链表的差集并返回至L1
{
    LNode* p = L1->next;
    LNode* q = L2->next;
    LNode* t = NULL;
    L1->next = NULL;//将L1断开为空表
    LNode* r = L1;
    int mark ;
    while (p != NULL)
    {
        mark = 0;
        t = p->next;
        q = L2->next;
        while (q != NULL)
        {
            if (p->data == q->data)
            {
                //两链表都存在的元素
                mark = 1;
                break;
            }
            else
            {
                q = q->next;
            }

        }
        if(mark ==0)
        {
            p->next = NULL;
            r->next = p;
            r = p;
        }
        p = t;
        
    }
    return L1;
}
void DeleteTheMinNumber(LinkList& L)       //删除链表最小节点
{
    /*
      错误点： 1.minbefore与最小值节点下一个节点连接时，应使用minbefore->next指针，而不是minbfore自己
    */
    LNode* p = L->next;
    LNode* min = L->next;
    LNode* minbefore = L;
    while (p != NULL)
    {
        if (p->next!=NULL && p->next->data < p->data)
        {
            minbefore = p;
            min = p->next;
        }
        
            p = p->next;
        
    }
   
        minbefore->next = min->next;
        delete(min);
       
}
void DeleteAllTheX(LinkList& L,int x)       //删除链表所有值为x的节点
{
    /*
     错误点：
        1.当p节点就是x节点时，应使用准备好的pre前驱(初始默认指向L表头指针)连接第二个节点，
          并让工作指针移动到第二个节点，pre不变
        2.当p不是，p后继是x的时候，应立即标记p为pre（是作为），删除后继后，p后移
    */
    LNode* p = L->next;//工作指针p
    LNode* k = L->next;//标记x的指针
    LNode* pre = L; //x前驱指针
    //我的
    /*while (p != NULL)
    {
        if (p->data == x)
        {
            k = p;
            pre->next = p->next;
            p = p->next;
            delete(k);

        }
        else if (p->next!= NULL && p->next->data == x)
        {
            pre = p;
            k = p->next;
            p->next = p->next->next;
            p = p->next;
            delete(k);
        }
       
        else
        {
            p = p->next;
        }*/
    //抓码的 
    while(p!=NULL)
    {
        if (p->data == x)
        {
            k = p;
            pre->next = p->next;
            p = p->next;
            delete(k);

        }
        else
        {
            pre = p;
            p = p->next;
        }
        //1 1 2 2 2 1 1 2 1 2 1
        //            p  
        //k
      //pre    pre
    }
}
