#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack& orig) : std::stack<T, Container>(orig) {}
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
	const_iterator begin() const
	{
		return (this->c.begin());
	}
	const_iterator end() const
	{
		return (this->c.end());
	}

	typedef typename Container::reverse_iterator reverse_iterator;
	reverse_iterator rbegin()
	{
		return (this->c.rbegin());
	}
	reverse_iterator rend()
	{
		return (this->c.rend());
	}

	typedef typename Container::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin() const
	{
		return (this->c.rbegin());
	}
	const_reverse_iterator rend() const
	{
		return (this->c.rend());
	}
};
#endif