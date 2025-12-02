#include<stdio.h>
#define true 1
#define false -1
#define MAXSIZE 20
typedef char ElementType;
typedef int flag;
//顺序栈
typedef struct SqStack{
	ElementType data[MAXSIZE];
	int top;//栈顶指针
}SqStack;

SqStack initStack(){
	SqStack s;
	s.top = -1;
	return s;
}

flag stackEmpty(SqStack* p){
	return p->top == -1;
}

flag push(SqStack* p,ElementType element){
	if(p->top == MAXSIZE-1){
		printf("栈满");
		return false;
	}
	p->data[++p->top] = element;
	return true;
}
flag pop(SqStack* p,ElementType* e){
	if(p->top == -1){
		printf("栈空");
		return false;
	}
	*e = p->data[p->top];
	p->top--;
	return true;
}

//栈在括号匹配上的应用
int bracketCheck(char str[], int length) {

	SqStack s = initStack();
	
	for (int i = 0; i < length; i++) {
		char current = str[i];
		
		// 左括号入栈
		if (current == '(' || current == '[' || current == '{') {
			push(&s, current);
		}
		// 右括号处理
		else if (current == ')' || current == ']' || current == '}') {
			
			if (stackEmpty(&s)) {
				return 0; // 栈空，匹配失败
			}
			
			char top;
			pop(&s, &top);
			
			// 检查是否匹配
			if ((current == ')' && top != '(') ||
				(current == ']' && top != '[') ||
				(current == '}' && top != '{')) {
				return 0;
			}
		}
		// 其他字符忽略
	}
	
	// 如果最后栈空，则匹配成功
	return stackEmpty(&s);
}

