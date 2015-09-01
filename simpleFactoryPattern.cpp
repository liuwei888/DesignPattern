/*************************************************************************
    > File Name: simpleFactory.cpp 
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年08月18日 星期二 00时47分31秒
    > 简单工厂模式
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

//抽象类
class Product 
{
	public:
		virtual void Show() = 0;
};

//下面是三个具体类,实现上面定义的抽象类
class ProductA : public Product
{
	public:
		void Show()
		{
			cout << "I am product A." << endl;
		}
};

class ProductB : public Product
{
	public:
		void Show()
		{
			cout << "I am product B." << endl;
		}
};

class ProductC : public Product
{
	public:
		void Show()
		{
			cout << "I am product C." << endl;
		}
};

class Factory
{
	public:
		Product *CreateProduct(const char *type)
		{
			if(strcmp(type, "productA") == 0)
			{
				return new ProductA;
			}
			else if(strcmp(type, "productB") == 0)
			{
				return new ProductB;
			}
			else if(strcmp(type, "productC") == 0)
			{
				return new ProductC;
			}
			else
			{
				return NULL;
			}
		}
};

int main()
{
	//首先定义一个工厂对象
	Factory *fac = new Factory();

	//然后使用上面定义的工厂对象创建产品对象
	Product *productA = fac->CreateProduct("productA");
	Product *productB = fac->CreateProduct("productB");
	Product *productC = fac->CreateProduct("productC");

	productA->Show();
	productB->Show();
	productC->Show();

	return 0;
}
