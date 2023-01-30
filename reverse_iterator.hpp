/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:04:57 by slahrach          #+#    #+#             */
/*   Updated: 2023/01/30 10:18:56 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
 #define REVERSE_ITERATOR_HPP
 namespace ft
 {
	template <typename T>
	class reverse_iterator
	{
		public :
		typedef typename T::value_type		value_type;
		typedef typename T::defference_type	difference_type;
		typedef value_type*					pointer;
		typedef value_type&					reference;
		reverse_iterator(pointer ptr_) : ptr(ptr_)
		{};
		template <typename it>
		reverse_iterator&(reverse_iterator<it>& copy)
		{
			*this = copy;
			return (*this);
		};
		~reverse_iterator() {};
		template <typename it>
		reverse_iterator& operator=(reverse_iterator<it>& obj)
		{
			this->ptr = obj.get_ptr();
			return (*this);
		};
		pointer get_ptr(void) const
		{
			return (ptr);
		}
		//operations overloading
		reference operator *(void) const
		{
			return (*ptr);
		}
		const value_type& operator *(void) const
		{
			return (*ptr);
		}
		reference operator[](difference_type n) const
		{
			return (ptr[n]);
		}
		pointer operator ->(void) const
		{
			return (ptr);
		}
		reverse_iterator& operator++(void)
		{
			ptr--;
			return (*this);
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator iter = *this;
			--(*this);
			return (iter);
		}
		reverse_iterator& operator--(void)
		{
			ptr++;
			return (*this);
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator iter = *this;
			++(*this);
			return (iter);
		}
		reverse_iterator operator +(difference_type n)
		{
			return (reverse_iterator(ptr - n));
		}
		reverse_iterator operator -(difference_type n)
		{
			return (reverse_iterator(ptr + n));
		}
		reverse_iterator& operator+=(difference_type n)
		{
			ptr-=n;
			return (*this);
		}
		reverse_iterator& operator-=(difference_type n)
		{
			ptr+=n;
			return (*this);
		}
		template <class T>
		friend reverse_iterator operator==(reverse_iterator<T>& __x, reverse_iterator<T>& __y)
		{
			return __x.ptr == __y.ptr;
		}
		template <class T>
		friend reverse_iterator<T> operator +(difference_type n, reverse_iterator<T> __x)
		{
			__x += n;
			return (__x);
		}
		// comparaison
		template <class T>
		friend bool operator==(reverse_iterator<T>& __x, reverse_iterator<T>& __y)
		{
			return __x.ptr == __y.ptr;
		}
		template <class T>
		friend bool operator<(reverse_iterator<T>& __x, reverse_iterator<T>& __y)
		{
			return (__x.ptr > __y.ptr);
		}
		template <class T>
		friend bool operator>(reverse_iterator<T>& __x, reverse_iterator<T>& __y)
		{
			return (__y > __x);
		}
		template <class T>
		friend bool operator!=(reverse_iterator<T>& __x, reverse_iterator<T>& __y)
		{
			return !(__x == __y)
		}
		template <class T>
		friend bool operator>=(reverse_iterator<T>& __x, reverse_iterator<T>& __y)
		{
			return (__x.ptr <= __y.ptr);
		}
		template <class T>
		friend bool operator<=(reverse_iterator<T>& __x, reverse_iterator<T>& __y)
		{
			return !(__x.ptr >= __y.ptr);
		}
		template <class T>
		friend difference_type operator-(reverse_iterator<T>& __x, reverse_iterator<T>& __y)
		{
			return (__y.ptr - __x.ptr);
		}
		private :
		value_type	*ptr;
		
	}
 }
#endif 