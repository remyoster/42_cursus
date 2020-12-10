#include <iostream>
#include <ctime>
#include <cstdlib>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

std::string gen_random(const int len)
{
	std::string tmp_s;
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i)
		tmp_s += alphanum[std::rand() % 63];
	return tmp_s;
}

void *serialize(void)
{
	Data *data = new Data;
	data->s1 = gen_random(8);
	data->n = std::rand();
	data->s2 = gen_random(8);
	return (reinterpret_cast<void *>(data));
}

Data *deserialize(void *raw)
{
	Data *data = reinterpret_cast<Data *>(raw);
	return (data);
}

int main()
{
	std::srand(std::time(NULL));
	void *p;
	Data *data;

	p = serialize();

	std::cout << "addr of p: " << p << std::endl;
	data = deserialize(p);

	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;

	delete data;

	return (0);
}