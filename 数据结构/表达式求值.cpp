#include <malloc.h> 
#include <stdio.h> 
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量

typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

struct SqStack
{
     SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
     SElemType *top; // 栈顶指针
     int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

Status InitStack(SqStack &S)       
{   
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
     if(!S.base) return ERROR;
	 S.top=S.base;
	 S.stacksize=STACK_INIT_SIZE;
	 return OK;
}

Status Push(SqStack &S,SElemType e)   
{   
// 在栈S中插入元素e为新的栈顶元素
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) return ERROR;
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return OK;
}

Status Pop(SqStack &S,SElemType &e)   
{   
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S.top==S.base) return ERROR;
     e=*--S.top;
	 return OK;
}

Status GetTop(SqStack S,SElemType &e)   
{    
// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if(S.top==S.base) return ERROR;
    e=*(S.top-1);
	return OK;
}

int StackLength(SqStack S) 
{   
// 返回栈S的元素个数
	int i;
    i=S.top-S.base;
	return i;
}

Status StackTraverse(SqStack S)
{
// 从栈顶到栈底依次输出栈中的每个元素
	SElemType *p = (SElemType *)malloc(sizeof(SElemType)); 
	p = S.top;       
	if(S.top==S.base)printf("The Stack is Empty!");  
	else
	{
		printf("The Stack is: ");
		p--;
		while(p>=S.base)             
		{
			printf("%d ", *p);
			p--;               
		}
	}
	printf("\n");
	return OK;
}

// ==================== 以上为顺序栈基本操作（题目已给）====================
// ==================== 以下为表达式求值核心代码 ==========================

// 运算符 → 优先表索引映射
int IndexOf(char op)
{
    switch(op)
    {
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '(': return 4;
        case ')': return 5;
        case '#': return 6;
        default:  return -1;
    }
}

// 运算符优先关系表（教材表3.1）
//  行：栈顶运算符 θ   列：当前读入运算符 c
//  '<' → θ < c，入栈
//  '=' → θ = c，脱括号
//  '>' → θ > c，先算！
//  'E' → 错误（合法输入不会出现）
char Precede[7][7] = {
    //  +    -    *    /    (    )    #
    { '>', '>', '<', '<', '<', '>', '>' },  // 行 θ = +
    { '>', '>', '<', '<', '<', '>', '>' },  // 行 θ = -
    { '>', '>', '>', '>', '<', '>', '>' },  // 行 θ = *
    { '>', '>', '>', '>', '<', '>', '>' },  // 行 θ = /
    { '<', '<', '<', '<', '<', '=', 'E' },  // 行 θ = (
    { '>', '>', '>', '>', 'E', '>', '>' },  // 行 θ = )
    { '<', '<', '<', '<', '<', 'E', '=' }   // 行 θ = #
};

// 执行一次二元运算：a θ b
int Operate(int a, char theta, int b)
{
    switch(theta)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default:  return 0;
    }
}

// 取运算符栈栈顶（封装 GetTop，直接返回 char）
char GetTopOptr(SqStack &S)
{
    SElemType e;
    if (GetTop(S, e) == ERROR) return '#';
    return (char)e;
}

int main()
{
    SqStack OPND;  // 运算数栈（存 int）
    SqStack OPTR;  // 运算符栈（存 char，用 int 存储）
    InitStack(OPND);
    InitStack(OPTR);
    Push(OPTR, (int)'#');  // 表达式结束符 '#' 作哨兵

    char c = getchar();  // 读第一个字符

    while (c != '=' || GetTopOptr(OPTR) != '#')
    {
        if (c >= '0' && c <= '9')
        {
            // ── 情况1：数字 → 拼出完整的数值 ──
            int num = 0;
            while (c >= '0' && c <= '9')
            {
                num = num * 10 + (c - '0');
                c = getchar();
            }
            Push(OPND, num);
            // 此时 c 已读到下一个非数字字符，交给循环继续处理
        }
        else
        {
            // ── 情况2：运算符 → 查表决定动作 ──
            char top_op = GetTopOptr(OPTR);
            int i = IndexOf(top_op);
            int j = IndexOf(c);
            char prec = Precede[i][j];

            if (prec == '<')
            {
                // 栈顶优先级 < 当前运算符 → 入栈，读下一个
                Push(OPTR, (int)c);
                c = getchar();
            }
            else if (prec == '=')
            {
                // 栈顶优先级 = 当前运算符 → 只有 '('=')'，脱括号
                SElemType tmp;
                Pop(OPTR, tmp);  // 弹出 '('
                c = getchar();   // 读下一个字符
            }
            else // prec == '>'
            {
                // 栈顶优先级 > 当前运算符 → 先算栈顶的！
                SElemType theta, b, a;
                Pop(OPTR, theta);   // 弹出运算符
                Pop(OPND, b);       // 弹出右操作数（先弹出的！）
                Pop(OPND, a);       // 弹出左操作数（后弹出的！）
                int result = Operate(a, (char)theta, b);
                Push(OPND, result);
                // ★ 不读下一个字符！继续用当前 c 和新栈顶比较 ★
            }
        }
    }

    // 输出最终结果
    SElemType answer;
    GetTop(OPND, answer);
    printf("%d\n", answer);

    return 0;
}
