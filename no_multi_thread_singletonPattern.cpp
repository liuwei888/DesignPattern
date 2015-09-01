/*************************************************************************
    > File Name: singleton.cpp
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年08月19日 星期三 01时57分26秒
	  > 最简单的单例模式，不考虑多线程
 ************************************************************************/

#include<iostream>
using namespace std;

class Singleton
{
	private:
		//私有构造函数
		Singleton()
		{
		}
		static Singleton *instance;
	public:
		//定义成static，可以通过类名直接访问
		static Singleton *GetInstance()
		{ 
			if(instance == NULL) 
				instance = new Singleton; 
			return instance;
		}

		static void DestoryInstance()
		{
			if(instance != NULL)
			{
				delete instance;
				instance == NULL;
			}
		}
};

Singleton *Singleton::instance = NULL;

int main()
{
	Singleton *singletonObj = Singleton::GetInstance();

	Singleton::DestoryInstance();

	return 0;
}
