/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_r_a.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:31:59 by slahrach          #+#    #+#             */
/*   Updated: 2023/01/30 09:32:41 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_R_A_HPP
 #define ITERATOR_R_A_HPP
 #include "iterator_t.hpp"
 namespace ft
 {
	template <typename T>
	class RaIterator
	{
		public :
		typedef typename T::value_type		value_type;
		typedef typename T::defference_type	difference_type;
		typedef value_type*					pointer;
		typedef value_type&					reference;
		RaIterator(pointer ptr_) : ptr(ptr_)
		{};
		template <typename it>
		RaIterator&(RaIterator<it>& copy)
		{
			*this = copy;
			return (*this);
		};
		~RaIterator() {};
		template <typename it>
		RaIterator& operator=(RaIterator<it>& obj)
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
		RaIterator& operator++(void)
		{
			ptr++;
			return (*this);
		}
		RaIterator operator++(int)
		{
			RaIterator iter = *this;
			++(*this);
			return (iter);
		}
		RaIterator& operator--(void)
		{
			ptr--;
			return (*this);
		}
		RaIterator operator--(int)
		{
			RaIterator iter = *this;
			--(*this);
			return (iter);
		}
		RaIterator operator +(difference_type n)
		{
			RaIterator it = *this;
			it.get_ptr()+= n;
			return (it);
		}
		RaIterator operator -(difference_type n)
		{
			RaIterator it = *this;
			it.get_ptr()-= n;
			return (it);
		}
		RaIterator& operator+=(difference_type n)
		{
			ptr+=n;
			return (*this);
		}
		RaIterator& operator-=(difference_type n)
		{
			ptr-=n;
			return (*this);
		}
		template <class T>
		friend RaIterator operator==(RaIterator<T>& __x, RaIterator<T>& __y)
		{
			return __x.ptr == __y.ptr;
		}
		template <class T>
		friend RaIterator<T> operator +(difference_type n, RaIterator<T> __x)
		{
			__x += n;
			return (__x);
		}
		// comparaison
		template <class T>
		friend bool operator==(RaIterator<T>& __x, RaIterator<T>& __y)
		{
			return __x.ptr == __y.ptr;
		}
		template <class T>
		friend bool operator<(RaIterator<T>& __x, RaIterator<T>& __y)
		{
			return (__x.ptr < __y.ptr);
		}
		template <class T>
		friend bool operator>(RaIterator<T>& __x, RaIterator<T>& __y)
		{
			return (__y < __x);
		}
		template <class T>
		friend bool operator!=(RaIterator<T>& __x, RaIterator<T>& __y)
		{
			return !(__x == __y)
		}
		template <class T>
		friend bool operator>=(RaIterator<T>& __x, RaIterator<T>& __y)
		{
			return !(__x < __y);
		}
		template <class T>
		friend bool operator<=(RaIterator<T>& __x, RaIterator<T>& __y)
		{
			return !(__y < __x);
		}
		template <class T>
		friend difference_type operator-(RaIterator<T>& __x, RaIterator<T>& __y)
		{
			return (__x.ptr - __y.ptr);
		}
		private :
		value_type	*ptr;
		
	}
 }
#endif 