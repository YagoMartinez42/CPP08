/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-23 12:44:51 by samartin          #+#    #+#             */
/*   Updated: 2025-10-23 12:44:51 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

class Span : public std::vector<int>
{
	public:
		Span();
		Span(const Span& orig);
		Span(const unsigned int maxSize);
		~Span();
		Span&			operator=(const Span& orig);
		void			addNumber(int n);
		void			addRange(const std::list<int> range);
		void			addRange(const std::vector<int> range);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
	private:
		unsigned int _maxSize;
};

#endif
