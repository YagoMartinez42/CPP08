/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:54:58 by samartin          #+#    #+#             */
/*   Updated: 2025/09/12 14:24:43 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "MutantStack.hpp"

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
	std::cout << TSTH << "===========================================================" << TSTR;
	std::cout << TSTH << "|  More tests  |" << TSTR;
	std::cout << TSTH << "===========================================================" << TSTR;
	{

	}
	return (0);
}
