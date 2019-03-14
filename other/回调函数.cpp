/*
@ 在C++的接口设计里常常会遇到这种情况：
	需要向类接口中注册很多不同的回调函数，这样这些回调函数的定义和管理便比较杂乱，
	这样我们可以借用delegate类的概念来这么实现回调。

@ 运行结果：Test1 : 1    Test3 : 3
	对于接口使用者而言，暴露出了IEvent这个接口，回调的管理都在这个接口中，避免了上述管理杂乱的情况。
*/

#include <iostream>
using namespace std;
class IEvent
{
public:
	virtual void Test1(int i) = 0;
	virtual void Test2(int i) = 0;
	virtual void Test3(int i) = 0;
};
class TestEvent :public IEvent
{
public:
	void Test1(int i) { cout << "Test1 : " << i << endl; }
	void Test2(int i) { cout << "Test2 : " << i << endl; }
	void Test3(int i) { cout << "Test3 : " << i << endl; }
private:
	int p;
};
class NotifyEvent
{
public:
	void Run(int flag)
	{
		switch (flag)
		{
		case 1:
			testEvent_->Test1(1);
			break;
		case 2:
			testEvent_->Test2(2);
			break;
		case 3:
			testEvent_->Test3(3);
			break;
		default:
			break;
		}
	}
	void SetMyEvent(IEvent* testEvent) { testEvent_ = testEvent; }
private:
	IEvent* testEvent_;
};

int main(int argc, char* argv[])
{
	IEvent* ptr_event = new TestEvent;
	NotifyEvent notifyEvent;
	notifyEvent.SetMyEvent(ptr_event);
	notifyEvent.Run(1);
	notifyEvent.Run(3);

	system("pause");
	return 0;
}