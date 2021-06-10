#pragma once
#include <memory>

using namespace std;

template <typename T>
class CMyStack
{
	class Elem
	{
	public:
		Elem(const T& value, const shared_ptr<Elem>& nextElemPtr = nullptr)
			: value(value)
			, nextElemPtr(nextElemPtr){};

		T value;

		shared_ptr<Elem> nextElemPtr;
	};

public:
	CMyStack() = default;

	CMyStack(const CMyStack& other)
	{
		;
	}

	CMyStack(CMyStack&& other)
	{
		;
	}

	~CMyStack()
	{
		;
	};

	CMyStack& operator=(const CMyStack& right)
	{
		return *this;
	}

	CMyStack& operator=(CMyStack&& right)
	{
		return *this;
	}


	void Push(const T& element)
	{
		;
	}

	void Pop()
	{
		;
	}

	const T& GetTopElem() const
	{
		return m_top->value;
	}

	bool isEmpty() const 
	{
		return false;
	}

	void Clear()
	{
		;
	}

private:
	shared_ptr<Elem> m_top = nullptr;
	size_t m_size = 0;
};
