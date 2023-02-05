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
///clear destruct _begin
///capacity() end - begin
#ifndef VECTOR_HPP
 #define VECTOR_HPP
 #include <iostream>
 #include "iterator_r_a.hpp"
 #include "reverse_iterator.hpp"
 #include <vector>
 namespace ft
 {
	template <class T, class _Allocator = std::allocator<T> >
	class vector
	{
		public :
		typedef	_Allocator												allocator_type;
		typedef	typename std::allocator_traits<_Allocator>::size_type		size_type;
		typedef T														value_type;
		typedef T&														reference;
		typedef const T&												const_reference;
		typedef typename std::allocator_traits<_Allocator>::difference_type	difference_type;
		typedef typename std::allocator_traits<_Allocator>::pointer			pointer;
		typedef typename std::allocator_traits<_Allocator>::const_pointer	const_pointer;
		typedef ft::RaIterator<pointer>									iterator;
		typedef ft::RaIterator<const_pointer>							const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		private :
		pointer															_begin;
		pointer															_end;
		pointer															_end_cap;
		allocator_type													alloc;

		public :
		allocator_type get_allocator() const {return this->alloc;}
		//capacity
		size_type	capacity() const {return static_cast<size_type>(_end_cap - _begin);}
		size_type	size() const {return static_cast<size_type>(_end - _begin);}
		size_type	max_size() const {return alloc.max_size();}
		bool		empty() {return (this->_begin == this->_end);}
		void		reserve(size_type newSize)
		{
			if (newSize <= capacity())
				return ;
			vector v(*this);
			vdeallocate();
			vallocate(newSize);
			this->assign(v.begin(), v.end());
		}
		void resize( size_type count, T value = T() )
		{
			if (count == size())
				return ;
			if (count < size())
				destroy_from(_begin + count);
			else
				construct_at__end(size() - count, value);
		}
		void		vallocate(size_type n)
		{
			if (n > alloc.max_size())
				throw("length error");
			this->_begin = this->_end = alloc.allocate(n, 0);
			this->_end_cap = this->_begin + n;
		}
		void		vdeallocate()
		{
			if (this->_begin != 0)
			{
				clear();
				alloc.deallocate(this->_begin, capacity());
				this->_begin = this->_end = this->_end_cap = 0;
			}
		}
		void	construct_at__end(size_type n, const_reference x)
		{
			while (n > 0)
			{
				alloc.construct(this->_end, x);
				n--;
				this->_end++;
			}
		}
		void	destroy_from(pointer newEnd)
		{
			pointer previousEnd = this->_end;
			while (newEnd != previousEnd)
			{
				alloc.destroy(previousEnd);
				previousEnd--;
			}
			this->_end = newEnd;
		}
		// constructions
		explicit vector (const allocator_type& alloca = allocator_type()) : _begin(0), _end(0), _end_cap(0), alloc(alloca) {}
		explicit vector (size_type n, const value_type& val, const allocator_type& alloca = allocator_type()) : _begin(0), _end(0), _end_cap(0), alloc(alloca)
		{
			if (n > 0)
			{
				vallocate(n);
				construct_at__end(n, val);
			}
		}
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloca = allocator_type()) : _begin(0), _end(0), _end_cap(0), alloc(alloca)
		{
			assign(first, last);
		}
		vector (const vector& x) : _begin(0), _end(0), _end_cap(0), alloc(x.get_allocator())
		{
			size_type n = x.size();
			if (n > 0)
			{
				vallocate(n);
				size_type i = 0;
				while (i < n)
				{
					alloc.construct(this->_end, x[i]);
					this->_end++;
					i++;
				}
			}
		}
		vector& operator = (const vector& x)
		{
			if (this != &x)
			{
				assign(x._begin, x._end);
			}
			return (*this);
		}
		~vector()
		{
			vdeallocate();
		}


		//iterators
		iterator begin() {return (iterator(this->_begin));}
		const_iterator cbegin() {return (iterator(this->_begin));}
		iterator end() {return (iterator(this->_end));}
		const_iterator cend() {return (iterator(this->_end));}
		reverse_iterator rbegin() {return (reverse_iterator(begin()));}
		const_reverse_iterator crbegin() {return (const_reverse_iterator(begin()));}
		reverse_iterator rend() {return (reverse_iterator(end()));}
		const_reverse_iterator crend() {return (const_reverse_iterator(end()));}

		//access
		reference operator[](size_type n)
		{
			if (n >= size())
				std::cout << "vector[] index out of bounds" << std::endl;
			return (this->_begin[n]);
		}
		const_reference operator[](size_type n) const
		{
			if (n >= size())
				std::cout << "vector[] index out of bounds" << std::endl;
			return (this->_begin[n]);
		}
		reference at(size_type n)
		{
			if (n >= size())
				throw std::out_of_range ("vector");
			return (this->_begin[n]);
		}
		const_reference at(size_type n) const
		{
			if (n >= size())
				throw std::out_of_range ("vector");
			return (this->_begin[n]);
		}
		reference front()
		{
			if (empty())
				std::cout << "front() called on an empty vector" << std::endl;
			return (*this->_begin);
		}
		const_reference front() const
		{
			if (empty())
				std::cout << "front() called on an empty vector" << std::endl;
			return (*this->_begin);
		}
		reference back()
		{
			if (empty())
				std::cout << "back() called on an empty vector" << std::endl;
			return (*(this->_end - 1));
		}
		const_reference back() const
		{
			if (empty())
				std::cout << "back() called on an empty vector" << std::endl;
			return (*(this->_end - 1));
		}
		value_type* data() {return (this->_begin);}
		const value_type* data() const {return (this->_begin);}

		//modifiers
		void	clear()
		{
			destroy_from(this->_begin);
		}
		void assign (size_type n, const value_type& val)
		{
			if (n <= capacity())
			{
				std::fill(this->_begin, this->_end, val);
				if (n >= size())
					construct_at__end(n - size(), val);
				else
					destroy_from(this->_begin + n);
			}
			else
			{
				vdeallocate();
				vallocate(n);
				construct_at__end(n, val);
			}
		}
		/////////enable if heeeere	  
		void assign (iterator first, iterator last)
		{
			if (last - first < 0)
				throw std::out_of_range("vector");
			size_type	n = last - first;
			if (n <= capacity())
			{
				size_type	i = 0;
				while (first != last && i < size())
				{
					_begin[i++] = *first;
					first++;
				}
				if (n >= size())
				{
					for(;first != last; first++)
						construct_at__end(1, *first);
				}
				else
					destroy_from(this->_begin + n);
			}
			else
			{
				vdeallocate();
				vallocate(n);
				for (;first != last; first++)
					construct_at__end(1, *first);
			}
		}
		void	push_back(const value_type& val)
		{
			if (size() + 1 > alloc.max_size())
				throw std::length_error("vector");
			if (size() < capacity())
				construct_at__end(1, val);
			else
			{
				capacity() != 0 ? reserve(capacity() * 2) : reserve(1);
				construct_at__end(1, val);
			}
		}
		void	pop_back()
		{
			destroy_from(_end - 1);
		}
		iterator erase (iterator position)
		{
			difference_type pos1 = position - begin();
			difference_type pos = position - begin();
			vector v(*this);
			iterator b = v.begin() + pos + 1;
			iterator e = v.end();
			while (b != e)
			{
				*(_begin + pos) = *b;
				b++;
				pos++;
			}
			//pop_back();
			return(begin() + pos1);
		}
	};
 }

#endif 