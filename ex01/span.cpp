/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-23 13:02:43 by samartin          #+#    #+#             */
/*   Updated: 2025-10-23 13:02:43 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() : _maxSize(0) {}
Span::Span(const Span& orig) : std::vector<int>(orig), _maxSize(orig._maxSize) {}
Span::Span(const unsigned int maxSize) : _maxSize(maxSize) {}
Span::~Span() {}

Span& Span::operator=(const Span& orig)
{
	if (this != &orig)
	{
		this->_maxSize = orig._maxSize;
		this->assign(orig.begin(), orig.end());
	}
	return(*this);
}

void Span::addNumber(int n)
{
	if (this->size() < this->_maxSize)
		this->insert(this->end(), n);
	else
		throw std::out_of_range("Span is full");
}
void Span::addRange(const std::list<int> range){ (void)range;}
void Span::addRange(const std::vector<int> range){ (void)range;}
unsigned int Span::shortestSpan() const
{
	std::vector<int> sorted(*this);
	std::vector<int>::iterator it;
	unsigned int span = 4294967295U;
	unsigned int dist;

	if (this->size() < 2)
		throw std::out_of_range("At least 2 elements needed to get a span value");
	std::sort(sorted.begin(), sorted.end());
	for (it = sorted.begin(); it != sorted.end() - 1; it++)
	{
		dist = *(it + 1) - *it;
		if (dist < span)
			span = dist;
	}
	return(span);
}

unsigned int Span::longestSpan() const
{
	std::vector<int>::const_iterator min;
	std::vector<int>::const_iterator max;
	if (this->size() < 2)
		throw std::out_of_range("At least 2 elements needed to get a span value");
	min = std::min_element(this->begin(), this->end());
	max = std::max_element(this->begin(), this->end());
	return(max - min);
}
