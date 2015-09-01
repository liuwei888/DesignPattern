/*************************************************************************
    > File Name: adapter1.cpp
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年08月19日 星期三 15时55分01秒
    > 类适配器模式
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
			cout << "Called SpectificRequest." << endl;
		}
};

//类适配器多继承于Target,Adaptee类
class Adapter : public Adaptee, public Target
{
	public:
		void Request()
		{
			this->SpecificRequest();
		}
};

int main()
{
	Target *t = new Adapter;
	t->Request();

	return 0;
}
