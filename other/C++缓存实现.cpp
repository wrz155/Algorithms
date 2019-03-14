#include <string>
#include <map>
#include <time.h>

/*设置缓存时间, 设置为5分钟*/
uint64_t expire_time = 300;

typedef struct _Value
{
	std::string key; //键值
					 /*这里包含需要定义额值*/
	uint32_t value;//这里用一个int的value代替
	uint64_t create_time; //创建时间
}Value;
//	现在定义我们的缓存数据结构，缓存为全局对象：
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
// 对缓存进行查询
// 通过形参返回数据
int QueryMyCache(const std::string& key, Value& value )
{
	if (key.empty())
		return -1;

	auto cache_iter = my_cache.find(key);
	if (cache_iter != my_cache.end())/*缓存里面存在值*/
	{
		const Value& value_t = cache_iter->second;
		/*判断缓存是否已过期*/
		if ((time(NULL) - value_t.create_time) < expire_time)
		{   /*未过期则返回值*/
			SetValue(value_t, value);
			return 0;
		}
	}
	/*已过期或不存在缓存中,通过DB去查询需要的Value*/
	if (0 != QueryDB(key, value))
	{
		/*DB查询失效*/
		return -2;
	}
	/*设置时间，并放入存储*/
	value.create_time = time(NULL);
	my_cache[key] = value;
	return 0;
}

int main()
{

	getchar();
	return 0;
}