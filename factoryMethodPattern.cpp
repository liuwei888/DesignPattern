/*************************************************************************
    > File Name: factoryMethodPattern.cpp
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年08月18日 星期二 02时50分53秒
    > 工厂方法模式
 ************************************************************************/

#include<iostream>
using namespace std;

class Product
{
	public:
		virtual void Show() = 0;
};

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

//工厂抽象类
class Factory
{
	public:
		virtual Product *CreateProduct() = 0;
};

//生成产品A的具体工厂
class FactoryA : public Factory
{
	public:
		Product *CreateProduct()
		{
			return new ProductA;
		}
};

class FactoryB : public Factory
{
	public:
		Product *CreateProduct()
		{
			return new ProductB;
		}
};

int main()
{
	//创建一个A工厂的对象
	Factory *factoryA = new FactoryA;
	//用A工厂的对象创建A产品
	Product *productA = factoryA->CreateProduct();
	productA->Show();

	Factory *factoryB = new FactoryB;
	Product *productB = factoryB->CreateProduct();
	productB->Show();

	if(factoryA != NULL)
	{
		delete factoryA;
		factoryA = NULL;
	}

	if(productA != NULL)
	{
		delete productA;
		productA = NULL;
	}

	if(factoryB != NULL)
	{
		delete factoryB;
		factoryB = NULL;
	}

	if(productB != NULL)
	{
		delete productB;
		productB = NULL;
	}
}
