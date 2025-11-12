/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:54:58 by samartin          #+#    #+#             */
/*   Updated: 2025/11/12 14:54:24 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "MutantStack.hpp"
#include <list>
#include <deque>

int main(void) {
	std::cout << std::endl;
	std::cout << TSTH << "===========================" << TSTR;
	std::cout << TSTH << "|    Test from subject    |" << TSTR;
	std::cout << TSTH << "===========================" << TSTR;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	std::cout << TSTH << "==========================" << TSTR;
	std::cout << TSTH << "|  Comparison with list  |" << TSTR;
	std::cout << TSTH << "==========================" << TSTR;
	{
		std::list<int> lst;
		std::list<int>::iterator li;
		std::list<int>::reverse_iterator rli;
		MutantStack<int> mstack;
		MutantStack<int>::iterator mi;
		MutantStack<int>::reverse_iterator rmi;
		mstack.push(5);
		mstack.push(-17);
		mstack.push(-3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		mstack.push(1000);
		lst.push_back(5);
		lst.push_back(-17);
		lst.push_back(-3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		lst.push_back(1000);
		std::cout << TSTL << "Printing mutant stack from begin to end" << TSTR;
		for (mi = mstack.begin(); mi != mstack.end(); mi++)
			std::cout << *mi << "\n";
		std::cout << std::endl;
		std::cout << TSTL << "Printing list from begin to end" << TSTR;
		for (li = lst.begin(); li != lst.end(); li++)
			std::cout << *li << "\n";
		std::cout << std::endl;
		std::cout << TSTL << "Printing mutant stack reversely" << TSTR;
		for (rmi = mstack.rbegin(); rmi != mstack.rend(); rmi++)
			std::cout << *rmi << "\n";
		std::cout << std::endl;
		std::cout << TSTL << "Printing list reversely" << TSTR;
		for (rli = lst.rbegin(); rli != lst.rend(); rli++)
			std::cout << *rli << "\n";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << TSTH << "=====================" << TSTR;
	std::cout << TSTH << "|  Const iterators  |" << TSTR;
	std::cout << TSTH << "=====================" << TSTR;
	{
		MutantStack<bool>::const_iterator mi;
		MutantStack<bool>::const_reverse_iterator rmi;
		MutantStack<bool> mstack;

		mstack.push(true);
		mstack.push(false);
		mstack.push(true);
		mstack.push(true);
		mstack.push(false);

		std::cout << TSTL << "Printing mutant stack from begin to end" << TSTR;
		for (mi = mstack.begin(); mi != mstack.end(); mi++)
			std::cout << *mi << "\n";
		std::cout << std::endl;
		std::cout << TSTL << "Printing mutant stack reversely" << TSTR;
		for (rmi = mstack.rbegin(); rmi != mstack.rend(); rmi++)
			std::cout << *rmi << "\n";
		std::cout << std::endl;
	}
	return (0);
}
