# SuffixExpression
此仓库是通过栈来实现后缀表达式，思想是将后缀表达式中的数据部分存入栈中，当遇到操作符时，就取出栈中的两个数据进行运算，运算结果再压入栈中。直到运算完成，此时栈中只剩一个元素，取它的Top()，此值便为表达式的运算结果。