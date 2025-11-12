#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack& orig) : std::stack<T>(orig) {}
	~MutantStack() {}

	MutantStack& operator=(const MutantStack& orig)
	{
		if (this != &orig)
		{
			this->c = orig.c;
		}
	return (*this);
	}

	typedef typename Container::iterator iterator;
	iterator begin()
	{
		return (this->c.begin());
	}
	iterator end()
	{
		return (this->c.end());
	}

	typedef typename Container::const_iterator const_iterator;
	const_iterator cbegin() const
	{
		return (this->c.cbegin());
	}
	const_iterator cend() const
	{
		return (this->c.cend());
	}

	typedef typename Container::reverse_iterator reverse_iterator;
	iterator rbegin()
	{
		return (this->c.rbegin());
	}
	iterator rend()
	{
		return (this->c.rend());
	}

	typedef typename Container::const_reverse_iterator const_reverse_iterator;
	iterator crbegin() const
	{
		return (this->c.crbegin());
	}
	iterator crend() const
	{
		return (this->c.crend());
	}
};
#endif