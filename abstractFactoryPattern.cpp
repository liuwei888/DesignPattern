/*************************************************************************
    > File Name: abstractFactoryPattern.cpp
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年08月18日 星期二 14时18分11秒
    > 抽象工厂模式
 ************************************************************************/

#include<iostream>
using namespace std;

//海尔产品抽象类
class HaierProduct
{
	public:
		virtual void Show() = 0;
};

//下面是三个海尔产品的具体类
class HaierTV : public HaierProduct
{
	public:
		void Show()
		{
			cout << "I am Haier TV." << endl;
		}
};

class HaierFridge : public HaierProduct
{
	public:
		void Show()
		{
			cout << "I am Haier fridge." << endl;
		}
};

class HaierAirConditioner : public HaierProduct
{
	public:
		void Show()
		{
			cout << "I am Haier air conditioner." << endl;
		}
};

//美的产品抽象类
class MeidiProduct
{
	public:
		virtual void Show() = 0;
};

//下面是三个美的产品具体类
class MeidiTV : public MeidiProduct
{
	public:
		void Show()
		{
			cout << "I am Meidi TV." << endl;
		}
};

class MeidiFridge : public MeidiProduct
{
	public:
		void Show()
		{
			cout << "I am Meidi fridge." << endl;
		}
};

class MeidiAirConditioner : public MeidiProduct
{
	public:
		void Show()
		{
			cout << "I am Meidi air conditioner." << endl;
		}
};

//抽象工厂类
class Factory
{
	public:
		//生成haier的产品
		virtual HaierProduct *CreateHaierProduct() = 0;
		//生成meidi的产品
		virtual MeidiProduct *CreateMeidiProduct() = 0;
};

//生成TV的具体工厂
class TVFactory : public Factory
{
	public:
		HaierProduct *CreateHaierProduct()
		{
			return new HaierTV;
		}

		MeidiProduct *CreateMeidiProduct()
		{
			return new MeidiTV;
		}
};

//生成fridge的具体工厂
class FridgeFactory : public Factory
{
	public:
		HaierProduct *CreateHaierProduct()
		{
			return new HaierFridge;
		}

		MeidiProduct *CreateMeidiProduct()
		{
			return new MeidiFridge;
		}
};

//生成air conditioner的具体工厂
class AirConditionerFactory : public Factory
{
	public:
		HaierProduct *CreateHaierProduct()
		{
			return new HaierAirConditioner;
		}

		MeidiProduct *CreateMeidiProduct()
		{
			return new MeidiAirConditioner;
		}
};

int main()
{
	//创建一个生成TV的工厂对象
	Factory *tv = new TVFactory;
	//用创建的工厂对象创建产品对象
	MeidiProduct *meiditv = tv->CreateMeidiProduct();
	meiditv->Show();

	Factory *air = new AirConditionerFactory;
	HaierProduct *haierair = air->CreateHaierProduct();
	haierair->Show();

	return 0;
}
