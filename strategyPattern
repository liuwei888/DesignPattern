/*************************************************************************
    > File Name: strategy.cpp
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年08月21日 星期五 01时21分42秒
    > 使用策略模式实现电影票价规则的选取
 ************************************************************************/

#include<iostream>
using namespace std;

//折扣算法的抽象类
class Discount
{
	public:
		virtual float Calculate(float price) = 0;
};

//学生票
class StudentDiscount : public Discount
{
	public:
		float Calculate(float price)
		{
			cout << "--------学生票--------" << endl;
			return price * 0.8;  //学生证打八折
		}
};

//儿童票
class ChildrenDiscount : public Discount
{
	public:
		float Calculate(float price)
		{
			cout << "--------儿童票--------" << endl;
			return price - 10;  //儿童票减10元
		}
};

//vip票
class VIPDiscount : public Discount
{
	public:
		float Calculate(float price)
		{
			cout << "--------VIP票---------" << endl;
			return price * 0.5;
		}
};

class MovieTicket
{
	private:
		float price;
		Discount *discount; //选取哪种折扣

	public:
		//设置票的原价
		void SetPrice(float originalPrice)
		{
			price = originalPrice;
		} 

		//设计折扣方法
		void SetDiscount(Discount *dis)
		{
			discount = dis;
		}

		float GetPrice()
		{
			return discount->Calculate(price);
		}
};


int main()
{
	MovieTicket *mt1 = new MovieTicket;
	MovieTicket *mt2 = new MovieTicket;
	float originalPrice = 60;
	mt1->SetPrice(originalPrice);
	mt2->SetPrice(originalPrice);
	cout << "原价为：" << originalPrice << endl;
	cout << "-------------------------" << endl;

	//儿童票
	Discount *cd = new ChildrenDiscount;
	mt1->SetDiscount(cd);
	cout << "折后票价为：" << mt1->GetPrice() << endl;

	//学生票
	Discount *sd = new StudentDiscount;
	mt2->SetDiscount(sd);
	cout << "折后票价为：" << mt2->GetPrice() << endl;
}
