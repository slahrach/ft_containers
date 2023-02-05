/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:15:04 by slahrach          #+#    #+#             */
/*   Updated: 2023/02/05 18:21:21 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

int main()
{
    try
    {
		//size_t n = 7;
		// //v.push_back(5);
		// //std::cout << v1[70] << std::endl;
		// ft::vector<int, std::allocator<int> > v1;
		// std::cout << v.capacity() << std::endl;
		// //v1.push_back(5);
		// //std::cout << v1.capacity() << std::endl;
		// v1.assign(15, 9);
		// ft::vector<int>::iterator be = v1.begin();
		// v.assign(be, be + 8);
		// std::cout << v.capacity() << std::endl << std::endl;
		// //std::cout << v[80] << std::endl;
		ft::vector<int, std::allocator<int> > v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		std::cout << v.capacity() << " " << v.size() << std::endl;
		ft::vector<int>::iterator e = v.end();
		ft::vector<int>::iterator b = v.begin();
		v.erase(b);
		while (b != e)
		{
			std::cout << *b << std::endl;
			b++;
		}
		
		// std::cout << *b << std::endl;
		
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}