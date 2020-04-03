//参考:《大话数据结构》
//"ElemType"代表所有可能的数据类型(数据结构中方便解决问题) 一般为int类型

// 函数返回值是找到的结点指针
template <class T> // 线性表的元素类型为 T
Link<T> * lnkList <T>:: setPos(int i) {
	int count = 0;
	if (i == -1) // i 为 -1 则定位到头结点
	return head;
	// 循链定位，若i为0则定位到第一个结点
 	Link<T> *p = head->next;
	while (p != NULL && count < i) {
 		p = p-> next;
 		count++;
 	};
	// 指向第 i 结点，i＝0,1,…，当链表中结点数小于 i 时返回 NULL
	return p;
}


//结构体+结构指针描述链表
typedef struct  Node
{
	ElemType data;     //数据域
	struct Node *next; //指针域
}Node, *LinkList;
//对于LinkList L: L是指向定义的Node结构体的指针
//可用 L->data 访问结构体成员(箭头运算符访问)
//(*L)是Node型的结构体 可以直接(*L).data(点运算符访问)

//LinkList *L: L是指向定义的Node结构体指针的指针 (*L)是指向Node结构体的指针
//可用(*L)->data 访问结构体成员
//(**L)是Node型的结构体 可以(**L).data

/*在链表操作中,我们常常要用链表变量作为函数的参数,这时,用LinkList L还
是LinkList *L就很值得考虑深究了,一旦用不好,函数就会出现逻辑错误,其准则是:
如果函数会改变指针L的值,而你希望函数结束调用后保存L的值,那你就要用LinkList *L,
这样,向函数传递的就是指针的地址,结束调用后,自然就可以去改变指针的值;
而如果函数只会修改指针所指向的内容,而不会更改指针的值,那么用LinkList L就行了*/

//查找单链表中的第i个元素 用e返回L中第i个数据元素的值
//调用完不会改变指针L的值
Status GetElem(LinkList L, int i, ElemType *e)
{
	int cnt;
	LinkList p;
	cnt = 1;
	while(p && cnt < i) {  //p不为空并且计数器小于i
		p = p->next;	//核心思想是将工作指针后移
		cnt++;
	}					//最坏情况的时间复杂度是O(n)
	if( !p || cnt > i)
		return ERROR; //第i个元素不存在
	*e = p->data;
	return OK;
}


//插入、删除都会改变指针L 故用*L
//单链表第i个数据插入节点的算法
Status ListInsert(LinkList *L, int i, ElemType e){
	int cnt;
	LinkList p, s;
	p = *L;
	cnt = 1;
	while(p && cnt < i){
		p = p->next;
		cnt++;
	}
	if(!p || cnt > i)
		return ERROR;
	s = (LinkList) malloc(sizeof(Node)); //生成一个新的节点
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//删除L的第i个数据元素 并用e返回其值
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int cnt;
	LinkList p,q;
	p = *L;
	cnt = 1;
	while(p->next && cnt < i){
		p = p->next;
		cnt++;
	}
	if(!(p->next) || cnt > i)
		return ERROR;
	q = p->next;  
	p->next = q->next; //将q的后继赋值给p的后继
	*e = q->data;
	free(q);
	return OK:
}

//单链表的整表创建(带表头结点)
//始终让新结点在第一的位置(头插法)
//函数调用完毕后 如果用L,则会指向一个空的链表,所以用*L
void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	srand(time(NULL));
	*L = (LinkList) malloc(sizeof(Node));
	(*L)->next = nullptr;        //建立一个带头结点的单链表
	for(int i = 0; i < n; i++){
		p = (LinkList) malloc(sizeof(Node));
		p->data = rand()%100 + 1;
		p->next = (*L)->next;  
		(*L)->next = p;		//插入到表头
	}
}

//尾插法
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	srand(time(NULL));
	*L = (LinkList) malloc(sizeof(Node));
	r = *L; //r为指向尾部的结点
	for(int i = 0; i < n; i++){
		p = (LinkList) malloc(sizeof(Node));
		p->data = rand()%100 + 1;
		r->next = p; 	//将表尾终端结点的指针指向新结点
		r = p; 			//将当前新结点定义为表尾终端结点
	}
	r->next = nullptr; //当前链表结束
}

//单链表的整表删除
Status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;
	while(p){
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = nullptr; //头结点的指针域为空
	return OK;
}
