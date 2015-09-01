/*************************************************************************
    > File Name: adapter2.cpp
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年08月19日 星期三 16时05分16秒
    > 对象适配器模式
 ************************************************************************/

#include<iostream>
using namespace std;

class Target
{
	public:
		virtual void Request()
		{

		}
};

class Adaptee
{
	public:
		void SpecificRequest()
		{
			cout << "Called SpecificRequest()" << endl;
		}
};

//对象适配器模式只继承Target类
class Adapter : public Target
{
	private:
		Adaptee *adaptee;
	public:
		Adapter()
		{
			adaptee = new Adaptee;
		}

		void Request()
		{
			adaptee->SpecificRequest();
		}
};

int main()
{
	Target *t = new Adapter;
	t->Request();

	return 0;
}
