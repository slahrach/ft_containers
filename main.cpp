/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:15:04 by slahrach          #+#    #+#             */
/*   Updated: 2023/02/07 19:16:51 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Vector.hpp"
#include "stack.hpp"
#include <vector>
int main()
{
    try
    {
		//size_t n = 7;
		// //v.push_back(5);
		// //std::cout << v1[70] << std::endl;
		// std::vector<int, std::allocator<int> > v1;
		// std::cout << v.capacity() << std::endl;
		// //v1.push_back(5);
		// //std::cout << v1.capacity() << std::endl;
		// v1.assign(15, 9);
		// std::vector<int>::iterator be = v1.begin();
		// v.assign(be, be + 8);
		//std::cout << v[80] << std::endl;
		ft::vector<int, std::allocator<int> > v;
		ft::vector<int, std::allocator<int> > another;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		// ft::stack<int> s(v);
		// std::cout << s.top() << std::endl;
		// s.push(9);
		// std::cout << s.top() << std::endl;
		// v.push_back(7);
		// v.push_back(8);
		// another.push_back(1);
		// another.push_back(2);
		// ft::vector<int>::iterator b = v.begin();
		// //v.insert(b + 8, 45, 13);
		// v.insert(b + 8, another.end(), another.begin());
		// swap(v, another);
		// //iterators are still valid
		// std::cout << *b << std::endl;
		// //
		for (ft::vector<int>::iterator it = another.begin(); it<another.end(); it++)
			std::cout << *it << std::endl;
		// std::cout << std::endl << v.capacity() << " " << v.size() << std::endl;
		// std::cout << *b << std::endl;
		// std::vector<int> foo (3,100);   // three ints with a value of 100
		// std::vector<int> bar (2,200);   // two ints with a value of 200

		// if (foo==bar) std::cout << "foo and bar are equal\n";
		// if (foo!=bar) std::cout << "foo and bar are not equal\n";
		// if (foo< bar) std::cout << "foo is less than bar\n";
		// if (foo> bar) std::cout << "foo is greater than bar\n";
		// if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		// if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
		
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}