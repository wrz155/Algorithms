/*
首先将算术表达式（中缀表达式）转换为前缀表达式或者后缀表达式

利用前缀表达式来计算
	使用一个栈进行值的存储 
	从右向左扫描，如果是操作数，压入栈中；如果是运算符，取出栈顶的2个元素进行运算，将值压入栈中；
	直到结束，输出栈中的唯一元素。

利用后缀表达式来计算
	使用一个栈s来进行值的计算。 
	从左向右扫描后缀表达式，遇到操作数压入s栈，遇到运算符，将栈顶的2个元素出栈计算，再将结果压入s栈；
	直到结束，将栈中唯一的元素出栈。
	
前缀表达式和后缀表达式区别

对于+ - or × /这种优先级相同的运算符的处理。 
	在前缀表达式的转换中，遇到运算符优先级相等的情况是入栈的。 
	在后缀表达式的转换中，遇到运算符优先级相等的情况是出栈的。 
原因：
	后缀表达式是从左向右扫描的，在优先级相同的时候，是先进栈的运算符先运算；后缀表达式是从左向右扫描的，在优先级相同的时候，是先进栈的运算符先运算； 
	而前缀表达式是从右向左扫描的，在优先级相同的时候，是后进栈的运算符先运算。 
	所以，在运算符栈中的操作，对于后缀表达式来说，只要不大于栈顶元素，就要将栈顶元素出栈，而前缀表达式是不大于等于栈顶元素，才将栈顶元素出栈。

*/

string getPostfixExpression (string s)
{
    string temp;
    Stack operators;
    operators.Push('#');
    bool flag = true;
    for (int i = 0; flag; i++)
    {
        char t = s[i];
        //如果是操作符，就和栈顶元素比较，如果优先级高，就入栈，否则将栈顶元素输出，再将该操作符压入栈中
        //如果是操作数，就直接输出。
        switch(t)
		{
        case '(':
        {
            operators.Push(t);
            break;
        }
        case ')':
        {
            char c = operators.Pop();
            while (c != '(')
            {
                temp += c;
                c = operators.Pop();
            }
            break;
        }
        case '*':
        case '/':
        {
            //只要栈顶元素不是'*'和'/'，就要入栈
            char c = operators.Pop();
            while (c == '*' || c == '/')
            {
                temp += c;
                c = operators.Pop();
            }
            operators.Push(c);
            operators.Push(t);
            break;
        }
        case '+':
        case '-':
        {
            //只要栈顶元素不是'('和'#'，就要先将栈顶元素出栈
            char c = operators.Pop();
            while (c != '(' && c != '#')
            {
                temp += c;
                c = operators.Pop();
            }
            operators.Push(c);
            operators.Push(t);
            break;
        }
        case '#':
        {
            //输入结束，将栈中元素统统出栈
            char c = operators.Pop();
            while (c != '#')
            {
                temp += c;
                c = operators.Pop();
            }
            flag = false;
            break;
        }
        default:
        {
            //操作数
            temp += t;
            break;
        }
        }
    }
    return temp;
}


int Calculation (string s)
{
    Stack stack;
    for (int i = 0; s[i] != '#'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            stack.Push((int)(s[i] -48));
            continue;
        }
        else
        {
            int a, b;
            a = stack.Pop();
            b = stack.Pop();
            if (s[i] == '+')
                stack.Push(a+b);
            else if (s[i] == '-')
                stack.Push(b-a);
            else if (s[i] == '*')
                stack.Push(b*a);
            else if (s[i] == '/')
                stack.Push(b/a);
        }
    }
    return stack.Pop();
}
