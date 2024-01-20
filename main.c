#include <stdio.h>
#include <stdlib.h>
#define MAX 1024
#include<string.h>
//                 树：
/*
					 a                   
					↙    ↘                
				 B          F               
				   ↘           ↘              
					 C           G              
					↙  ↘       ↙:                  
				  D     E     H           
											
*/



//树的结构体
struct treeNode
{
	struct treeNode*Beforetree;
	
	int data;
	
	int Flag;
	
	struct treeNode*Aftertree;
};


//栈
struct sstack
{
	void*data[MAX];
	
	int m_size;
};

//数据
struct Data
{
	
	
	char name[64];
	
	int age;
};



typedef void*seqstack;

//递归遍历树
void found(struct treeNode*root)
{
	//  struct treeNode *pos=a.Beforetree;
	//  int i=0;
	if(root==NULL)
	{
		return;
	}
	else
		
	{
		printf("正常遍历的结果为");
		printf("%d\n",root->data);
		found(root->Aftertree);
		found(root->Beforetree);
		
		//  printf("%d",root->data);
		
		
	}
	
}
//       ''''@@栈部分ss'

//创建栈
seqstack init_seqstack()
{
	struct sstack*stack = malloc(sizeof(struct sstack));
	
	if(stack==NULL)
	{
		printf("开辟堆空间失败");
		return NULL;
	}
	
	memset(stack->data,0,sizeof(void*)*MAX);
	
	stack->m_size = 0;
	
	return stack;
}


void push_seqstack(seqstack stack,void*data)
{
	if(stack==NULL)
	{
		return;
	}
	if(data==NULL)
	{
		return;
	}
	
	struct sstack*mystack = stack;
	
	if(mystack->m_size==MAX)
	{
		return;
	}
	
	
	mystack->data[mystack->m_size] = data;
	mystack->m_size++;
	
}

void*gettop_seqstack(seqstack stack)
{
	if(stack==NULL)
	{
		return NULL;
	}
	
	struct sstack*mystack = stack;
	
	if(mystack->m_size==0)
	{
		return NULL;
		
	}
	
	return mystack->data[mystack->m_size-1];
}

int size_stack(seqstack stack)
{
	
	
	if(stack==NULL)
	{
		return-1;
	}
	
	struct sstack*mystack = stack;
	
	return mystack->m_size;
}

//判断此栈是否为空
int isEmptyStack(seqstack stack)
{
	if(stack==NULL)
	{
		return-1;
	}
	struct sstack*mystack = stack;
	if(mystack->m_size==0)
	{
		return-1;
	}
	
	return 0;
	
}

void pop_seqstack(seqstack stack)
{
	if(stack==NULL)
	{
		return;
	}
	struct sstack*mystack = stack;
	if(mystack->m_size==0)
	{
		return;
	}
	
	mystack->data[mystack->m_size-1] = NULL;
	mystack->m_size--;
	
}

void destroy_seqstack(seqstack stack)
{
	if(stack==NULL)
	{
		return;
	}
	
	free(stack);
	
	stack = NULL;
}

//              text01～～
void perm()
{
	seqstack*stack = init_seqstack();
	
	struct Data personA = {
		"aaa",1
	};
	struct Data personB = {
		"bbb",2
	};
	struct Data personC = {
		"ccc",3
	};
	
	push_seqstack(stack,&personA);
	
	push_seqstack(stack,&personB);
	
	push_seqstack(stack,&personC);
	
	while(isEmptyStack(stack)==0)
	{
		struct Data*datta = gettop_seqstack(stack);
		
		printf("姓名为%s 年龄为%d\n",datta->name,datta->age);
		
		pop_seqstack(stack);
		
		//destroy_seqstack(stack);
		
		int size = size_stack(stack);
		
		printf("栈的大小为%d\n",size);
		
		
	}
	//删除
	destroy_seqstack(stack);
	
}



void CreateNodeTree()
{
	//        DATA       ____
	
	struct treeNode a = {
		NULL,10,0,NULL
	};
	struct treeNode b = {
		NULL,20,0,NULL
	};
	struct treeNode c = {
		NULL,30,0,NULL
	};
	struct treeNode d = {
		NULL,40,0,NULL
	};
	struct treeNode e = {
		NULL,50,0,NULL
	};
	struct treeNode f = {
		NULL,60,0,NULL
	};
	
	
	
	//           end    ____
	
	//relation
	a.Beforetree = &b;
	a.Aftertree = &c;
	b.Beforetree = &d;
	c.Aftertree = &f;
	b.Aftertree = &e;
	
	found(&a);
}

int main(const char argc,const char *argv)
{
	CreateNodeTree();
	
	perm();
	
	printf("hello world!");
	return EXIT_SUCCESS;
}