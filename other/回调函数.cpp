/*
@ ��C++�Ľӿ�����ﳣ�����������������
	��Ҫ����ӿ���ע��ܶ಻ͬ�Ļص�������������Щ�ص������Ķ���͹����Ƚ����ң�
	�������ǿ��Խ���delegate��ĸ�������ôʵ�ֻص���

@ ���н����Test1 : 1    Test3 : 3
	���ڽӿ�ʹ���߶��ԣ���¶����IEvent����ӿڣ��ص��Ĺ���������ӿ��У������������������ҵ������
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