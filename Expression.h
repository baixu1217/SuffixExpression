#pragma once
#include<stack>
#include<assert.h>

enum Type
{
	OP_SYMBOL,
	OP_NUM,
	ADD,
	SUB,
	MUL,
	DIV
};

struct Cell
{
	Type _type;
	int _value;
};

void FunTest()
{
	Cell RPN[] = {
		{OP_NUM,12},
		{OP_NUM,3},
		{OP_NUM,4},
		{OP_SYMBOL,ADD},
		{OP_SYMBOL,MUL},
		{OP_NUM,6},
		{OP_SYMBOL,SUB},
		{OP_NUM,8},
		{OP_NUM,2},
		{OP_SYMBOL,DIV},
		{OP_SYMBOL,ADD}
	};
	stack<int> s;
	for(size_t i = 0; i < sizeof(RPN)/sizeof(RPN[0]);++i)
	{
		if(RPN[i]._type == OP_NUM)
		{
			s.push(RPN[i]._value);
		}
		else if(RPN[i]._type == OP_SYMBOL)
		{
			int second = s.top();
			s.pop();
			int first = s.top();
			s.pop();
			switch(RPN[i]._value)
			{
			case ADD:
				s.push(first+second);
				break;
			case SUB:
				s.push(first-second);
				break;
			case MUL:
				s.push(first*second);
				break;
			case DIV:
				s.push(first/second);
				break;
			default:
				assert(false);
			}
		}
		else
		{
			assert(false);
		}
	}
	cout<<s.top()<<endl;
}