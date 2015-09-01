/************************************************************************* 
   > File Name: facade.cpp 
   > Author: liuwei 
   > Mail: 271551048@qq.com 
   > Created Time: 2015年08月20日 星期四 19时11分34秒 
   > 外观模式的简单实现 
 ************************************************************************/ 
#include<iostream> 
using namespace std; 
class SubSystemA 
{ 
	public: 
		void MethodA() 
		{
			cout << "This is method A." << endl; 
		} 
}; 
class SubSystemB 
{ 
	public: 
		void MethodB() 
		{ 
			cout << "This is method B." << endl; 
		} 
}; 
class SubSystemC 
{ 
	public: 
		void MethodC() 
		{
			cout << "This is method C." << endl; 
		} 
}; 
class Facade 
{ 
	private: 
		SubSystemA *objA; 
		SubSystemB *objB; 
		SubSystemC *objC; 
	public: 
		Facade() 
		{ 
			objA = new SubSystemA; 
			objB = new SubSystemB;
			objC = new SubSystemC;
		}
		void Method()
		{
			objA->MethodA();
			objB->MethodB();
			objC->MethodC();
		}
};

int main()
{
	Facade *fa = new Facade;
	fa->Method();
}
