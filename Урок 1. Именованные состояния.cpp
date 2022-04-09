#include <iostream>
#include <cstdint>

class Power
{
	double gravity = 2;
	double weight = 16;
public:
	void setValues(double gravity, double weight)
	{
		this->gravity = gravity;
		this->weight = weight;
	}
	double calculate();
};
double Power::calculate()
{
	int w = weight;
	double result = 1;
	while (w)
	{
		if (w % 2)
		{
			result *= gravity;
			w -= 1;
		}
		else
		{
			gravity *= gravity;
			w /= 2;
		}
	}
	return result;
}

class RGBA
{
	std::uint8_t m_red;
	std::uint8_t m_green;
	std::uint8_t m_blue;
	std::uint8_t m_alpha;
public:
	RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255) {}
	RGBA(std::uint8_t red, std::uint8_t blue, std::uint8_t green, std::uint8_t alpha) :
		m_red(red), m_green(blue), m_blue(green), m_alpha(alpha) {}
	void print();
};
void RGBA::print()
{
	printf("RGBA: r=%d, g=%d, b=%d, a=%d\n", m_red, m_green, m_blue, m_alpha);
}

class Stack
{
#define STACK_LENGTH 10
	int arr[STACK_LENGTH] = {0};
	int capacity = 0;
public:
	Stack()
	{
		for (int i = 0; i < STACK_LENGTH; i++)
		{
			arr[i] = 0;
		}
	}
	void reset();
	bool push(int e);
	int pop();
	void print();
};
void Stack::reset()
{
	while (capacity > 0)
	{
		arr[capacity--] = 0;
	}
}
bool Stack::push(int e)
{
	if (capacity < STACK_LENGTH)
	{
		arr[capacity++] = e;
		return true;
	}
	else
	{
		return false;
	}
}
int Stack::pop()
{
	if (capacity >= 0)
	{
		arr[capacity--];
			return false;
	}
}