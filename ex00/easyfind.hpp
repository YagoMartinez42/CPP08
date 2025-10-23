/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:51:30 by samartin          #+#    #+#             */
/*   Updated: 2025/09/25 15:33:33 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>

template < typename T >
typename T::const_iterator easyfind(const T& a, const int b)
{
    typename T::const_iterator it;

    it = std::find(a.begin(), a.end(), b);
    if (it == a.end())
        throw std::out_of_range("Value not found");
    std::cout << "Found " << b << " value in container." << std::endl;
    return (it);
}

#endif
