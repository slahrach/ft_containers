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
	template <class T, class _Allocator>
	class vector
	{
		private :
		typedef T														value_type;
		typedef T&													reference;
		typedef const T&											const_reference;
		typedef typename allocator_traits<_Allocator>::difference_type	difference_type;
		typedef T*														pointer;
		typedef const T*												const_pointer;
		typedef RaIterator<pointer>										iterator;
		typedef RaIterator<const_pointer>								const_iterator;
		typedef ft::reverse_iterator<iterator>         reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>   const_reverse_iterator;
		pointer															begin;
		pointer															end;
		pair<pointer, _Allocator>										end_cap;
	}
 }
#endif 