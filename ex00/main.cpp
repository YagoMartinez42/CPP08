/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:54:58 by samartin          #+#    #+#             */
/*   Updated: 2025/09/25 15:35:04 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "easyfind.hpp"
#include <list>
#include <map>
#include <vector>

int main(void) {
	//Probar dos o tres tipos distintos de container
	//Probar cero elementos, encontrar elemento que existe y elemento que no, probar con container que no tiene enteros
	std::cout << std::endl;
	std::cout << TSTH << "=======================" << TSTR;
	std::cout << TSTH << "|   Tests with list   |" << TSTR;
	std::cout << TSTH << "=======================" << TSTR;
	{
		std::list<int> lst;
		std::list<int>::const_iterator it;
		int target = 22;

		std::cout << TSTL << "Using Easy find on empty list" << TSTR;
		try
		{
			it = easyfind(lst, target);
			std::cout << TSTL << "Found " << *it << " in list. (Won't happen)" << TSTR;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		lst.push_back(-1);
		lst.push_back(22);
		lst.push_back(33);
		std::cout << TSTL << "Using Easy find on 3-element list." << TSTR;
		try
		{
			it = easyfind(lst, target);
			std::cout << TSTL << "Found " << *it << " in list." << TSTR;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << TSTH << "=======================" << TSTR;
	std::cout << TSTH << "|  Tests with vector  |" << TSTR;
	std::cout << TSTH << "=======================" << TSTR;
	{
		std::vector<int>::const_iterator it;
		std::vector<int> vec;
		vec.push_back(4);
		vec.push_back(6);
		vec.push_back(-11);
		std::cout << TSTL << "Using Easy find on 3-element vector." << TSTR;
		try
		{
			it = easyfind(vec, 5);
			std::cout << TSTL << "Found " << *it << " in vector (Won't happen)." << TSTR;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			it = easyfind(vec, -11);
			std::cout << TSTL << "Found " << *it << " in vector." << TSTR;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	return (0);
}
