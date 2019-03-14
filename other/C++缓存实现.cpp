#include <string>
#include <map>
#include <time.h>

/*���û���ʱ��, ����Ϊ5����*/
uint64_t expire_time = 300;

typedef struct _Value
{
	std::string key; //��ֵ
					 /*���������Ҫ�����ֵ*/
	uint32_t value;//������һ��int��value����
	uint64_t create_time; //����ʱ��
}Value;
//	���ڶ������ǵĻ������ݽṹ������Ϊȫ�ֶ���
typedef std::map<std::string, Value> MyCache;
MyCache my_cache;

void SetValue(const Value& value_t, Value& value)
{
	value.key = value_t.key;
	value.value = value_t.value;
	value.create_time = value_t.create_time;
}
int QueryDB(const std::string& key, Value& value)
{
	return 0;
}
// �Ի�����в�ѯ
// ͨ���βη�������
int QueryMyCache(const std::string& key, Value& value )
{
	if (key.empty())
		return -1;

	auto cache_iter = my_cache.find(key);
	if (cache_iter != my_cache.end())/*�����������ֵ*/
	{
		const Value& value_t = cache_iter->second;
		/*�жϻ����Ƿ��ѹ���*/
		if ((time(NULL) - value_t.create_time) < expire_time)
		{   /*δ�����򷵻�ֵ*/
			SetValue(value_t, value);
			return 0;
		}
	}
	/*�ѹ��ڻ򲻴��ڻ�����,ͨ��DBȥ��ѯ��Ҫ��Value*/
	if (0 != QueryDB(key, value))
	{
		/*DB��ѯʧЧ*/
		return -2;
	}
	/*����ʱ�䣬������洢*/
	value.create_time = time(NULL);
	my_cache[key] = value;
	return 0;
}

int main()
{

	getchar();
	return 0;
}