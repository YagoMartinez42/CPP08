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
#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>

int main(void) {
	std::cout << std::endl;
	std::cout << TSTH << "===========================" << TSTR;
	std::cout << TSTH << "|    Test from subject    |" << TSTR;
	std::cout << TSTH << "===========================" << TSTR;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	std::cout << TSTH << "================================" << TSTR;
	std::cout << TSTH << "|  Less than 2 elements tests  |" << TSTR;
	std::cout << TSTH << "================================" << TSTR;
	{
		Span zero = Span();
		std::cout << TSTL << "Adding a number to a Span where none fits" << TSTR;
		try
		{
			zero.addNumber(6);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << TSTL << "Using shortestSpan() and longestSpan() on empty Span" << TSTR;
		try
		{
			std::cout << zero.shortestSpan() << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << zero.longestSpan() << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		Span one = Span(1);

		one.addNumber(6);
		std::cout << TSTL << "Using shortestSpan() and longestSpan() on a Span containing a single '6'" << TSTR;
		try
		{
			std::cout << zero.shortestSpan() << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << zero.longestSpan() << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	std::cout << TSTH << "===========================" << TSTR;
	std::cout << TSTH << "|  Loads of values tests  |" << TSTR;
	std::cout << TSTH << "===========================" << TSTR;
	{
		Span pan = Span(40000);
		std::list<int> added;
		unsigned int size;
		unsigned int i;
		std::ofstream aFile;

		std::cout << TSTL << "Filling a 40K max size span with a random (up to 20K, half size) amount of random values." << TSTR;
		srand(time(0));
		size = rand() % 20000;
		for (i = 0; i < size; i++)
			pan.addNumber(rand() - 1073741823); //RAND_MAX / 2 to allow negatives
		std::cout << TSTL << "Result is being printed into bigtest1.txt." << TSTR;
		std::cout << "Span original fill size: " << pan.size() << '\n';
		aFile.open ("bigtest1.txt");
		for (i = 0; i < pan.size(); i++)
			aFile << pan[i] << " ";
		aFile << std::endl;
		aFile.close();
		std::cout << TSTL << "Adding a full range (list type) of again a random amount of random values." << TSTR;
		size = rand() % 20000;
		for (i = 0; i < size; i++)
			added.push_back(rand() - 1073741823);
		std::cout << "Range size: " << added.size() << '\n';
		pan.addRange(added);
		std::cout << TSTL << "Result is being printed into bigtest2.txt." << TSTR;
		aFile.open ("bigtest2.txt");
		for (i = 0; i < pan.size(); i++)
			aFile << pan[i] << " ";
		aFile << std::endl;
		aFile.close();
		std::cout << TSTL << "With these figures, shortest span should be close to zero and longest should be close to max unsigned int." << TSTR;
		std::cout << "Span final fill size: " << pan.size() << '\n';
		std::cout << "Shortest: " << pan.shortestSpan() << '\n';
		std::cout << "Longest: " << pan.longestSpan() << '\n';
		std::cout << std::endl;

	}
	return (0);
}
