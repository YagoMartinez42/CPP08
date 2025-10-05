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
	std::cout << TSTH << "=======================" << TSTR << std::endl;
	std::cout << TSTH << "|   Tests with list   |" << TSTR << std::endl;
	std::cout << TSTH << "=======================" << TSTR << std::endl;
	{
		std::list<int> lst;
		int distance;
		int target = 22;

		std::cout << TSTL << "Using Easy find on empty list" << TSTR << std::endl;
		try
		{
			distance = easyfind(lst, target);
			std::cout << "Target `" << target << "` found (won't happen)." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		lst.push_back(-1);
		lst.push_back(22);
		lst.push_back(33);
		std::cout << TSTL << "Using Easy find on 3-element list." << TSTR << std::endl;
		try
		{
			distance = easyfind(lst, target);
			std::cout << "Target `" << target << "` found on element count " << distance + 1 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}
/*	std::cout << std::endl;
	std::cout << TSTH << "=======================" << TSTR << std::endl;
	std::cout << TSTH << "|    Tests with map   |" << TSTR << std::endl;
	std::cout << TSTH << "=======================" << TSTR << std::endl;
	{
		std::map<std::string, int> mmap;
		std::map<std::string, std::string> pamm;
		mmap["one"] = 1;
		mmap["minus three"] = -3;
		mmap["twelve"] = 12;
		pamm["one"] = "uno";
		pamm["minus three"] = "menos tres";
		pamm["twelve"] = "doce";
	}
	std::cout << std::endl;
	std::cout << TSTH << "=======================" << TSTR << std::endl;
	std::cout << TSTH << "|  Tests with vector  |" << TSTR << std::endl;
	std::cout << TSTH << "=======================" << TSTR << std::endl;
	{
		std::vector<int> vec;
		vec.push_back(4);
		vec.push_back(6);
		vec.push_back(-11);
	}
*/
	return (0);
}
