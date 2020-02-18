//------------------------------------------ BULID THE STACK ---------------------------------------
#include<iostream>
#include<string>
using namespace std;
const int Max_Length =100;//size of stack in array implementation
struct etype // the user defined data type of stack element 
{
	string name ;
	int age;
};
struct Stack 
{
	etype arrelement [Max_Length]; // array of elements(etype = structure) of size maxlength(100)
	int top ;
};
etype Top (Stack &s)//returned funtion with the top element(etype) in stack
{
	return s.arrelement[s.top]; // return the top element in the array of the stack
}
bool Is_Empty(Stack &s)
{
	if (s.top == Max_Length)
		return true;
	else 
		return false;
}
bool Is_Full(Stack &s)
{
	if (s.top == 0)
		return true;
	else 
		return false;
}
void Push (Stack &s,etype x)
{
	if(Is_Full(s)==true)
		cout<<"Stack overflow"<<endl;
	else
	{
		s.top--;
		//s.arrelement[s.top]=x;
		s.arrelement[s.top].name = x.name;
		s.arrelement[s.top].age = x.age;
	}
}
etype Pop (Stack &s)
{
	etype temp;
	temp.name="";
	temp.age=-1;
	if(Is_Empty(s)==true)
	{
		return temp;
	}
	else 
	{
		s.top++;
		return s.arrelement[s.top-1];
	}
}
void disp(Stack &s)
{
	if(Is_Empty(s)==true)
	{
		cout<<"empty stack"<<endl;
	}
	else
	{
		for(int i =s.top;i<Max_Length;i++)
		{
			cout<<"|--------------|"<<endl;
			cout<<"| "<<s.arrelement[i].name<<"   "<<s.arrelement[i].age<<" |"<<endl;
			cout<<"|--------------|"<<endl;
		}

	}
}
void input(Stack &s)
{
	int c;
	cout<<"Enter # of Elememts :";
	cin>>c;
	for(int i=0;i<c;i++)
	{
		etype xx;
		cout<<"Name is : ";
		cin>>xx.name ;
		cout<<" and age is : ";
		cin>>xx.age;
		Push(s,xx);
	}
}
bool check_op(string o)
{
	if((o=="+")||(o=="-")||(o=="*")||(o=="/")||(o=="^")||(o=="%"))
		return true;
	else
		return false;
}
etype eval(etype x,etype y, string o)
{
	etype z;
	if (o=="+")
	{
		z.age=y.age+x.age;
	}
	else if (o=="/")
	{
		z.age=y.age/x.age;
	}
	else if (o=="-")
	{
		z.age=y.age-x.age;
	}
	else if (o=="*")
	{
		z.age=y.age*x.age;
	}
	return z;
}
int eval_post(Stack &s,string exp[],int size)
{
	for(int i=0;i<size;i++)
	{
		if (check_op(exp[i]))
		{
			etype x,y;
			x=Pop(s);
			y=Pop(s);
			Push(s,eval(x,y,exp[i]));
		}
		else
		{
			etype temp;
			temp.age=stoi(exp[i]);
			Push(s,temp);
		}
	}
	return (Pop(s).age);
}
void main()
{
	/*Stack xx ;
	xx.top = Max_Length;
	etype a1;
	a1.name="tharwat";
	a1.age =55;
	etype a2;
	a2.name="Mohaned";
	a2.age =20;
	Push(xx,a1);
	Push(xx,a2);
	disp(xx);/*
	etype t1,t2;
	t1=Top(xx);
	cout<<t1.name<<"   "<<t1.age<<endl;
	t1=Pop(xx);
	t2=Pop(xx);
	cout<<t2.name<<"   "<<t2.age<<endl;*/
	string c[50];
	Stack xx;
	xx.top=Max_Length;
	int s;
	cout<<"enter # of numbers and operations = ";
	cin>>s;
	for(int i=0;i<s;i++)
	{	
		cout<<"c["<<i<<"]= ";
		cin>>c[i];
	}
	cout<<"the value of expression = "<<eval_post(xx,c,s)<<endl;
	system("pause");
}