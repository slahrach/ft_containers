/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:01:45 by slahrach          #+#    #+#             */
/*   Updated: 2023/02/01 00:42:30 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pair<pointer, allocator type> end_cap
///alloc() returns _Allocator    and end_cap() returns end ptr
///clear destruct begin
///capacity() end - begin
#ifndef VECTOR_HPP
 #define VECTOR_HPP
 #include <iostream>
 #include "iterator_r_a.hpp"
 #include "reverse_iterator.hpp"
 namespace ft
 {
	template <class T, class _Allocator = std::allocator<T>>
	class vector
	{
		public :
		typedef	_Allocator												allocator_type;
		typedef	size_t													size_type;
		typedef T														value_type;
		typedef T&														reference;
		typedef const T&												const_reference;
		typedef typename allocator_traits<_Allocator>::difference_type	difference_type;
		typedef T*														pointer;
		typedef const T*												const_pointer;
		typedef ft::RaIterator<pointer>									iterator;
		typedef ft::RaIterator<const_pointer>							const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		private :
		pointer															begin;
		pointer															end;
		pointer															end_cap;
		allocator_type													alloc;

		size_type	capacity() const {return static_cast<size_type>(end_cap - begin);}
		void		vallocate(size_type n)
		{
			if (n > alloc.max_size())
				throw("length error");
			this->begin = this->end = alloc.allocate(n, 0);
			this->end_cap = this->begin + n;
		}
		void	construct_at_end(size_type n, const_reference x)
		{
			while (n > 0)
			{
				alloc.construct(this->end, x);
				n--;
				this->end++;
			}
		}
		explicit vector (const allocator_type& alloc) : begin(0), end(0), end_cap(0, std::move(alloc)) {};
		explicit vector (size_type n, const value_type& val, const allocator_type& alloc) begin(0), end(0), end_cap(0, std::move(alloc))
		{
			if (n > 0)
			{
				vallocate(n);
				construct_at_end(n, x);
			}
		}
		
	}
 }
#endif 