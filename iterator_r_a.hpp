/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_r_a.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:31:59 by slahrach          #+#    #+#             */
/*   Updated: 2023/02/05 17:58:00 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_R_A_HPP
 #define ITERATOR_R_A_HPP
 #include "iterator_t.hpp"
 namespace ft
 {
	template <typename Iter>
	class RaIterator
	{
		public :
		typedef typename iterator_traits<Iter>::value_type		value_type;
		typedef typename iterator_traits<Iter>::difference_type			difference_type;
		typedef value_type*								pointer;
		typedef value_type&								reference;
		RaIterator() : iter(){};
		RaIterator(Iter iter_) : iter(iter_){};
		template <typename it>
		RaIterator(RaIterator<it>& copy) : iter(copy.get_iter()){};
		~RaIterator() {};
		template <typename it>
		RaIterator& operator=(RaIterator<it>& obj)
		{
			this->iter = obj.get_iter();
			return (*this);
		};
		pointer get_iter(void) const
		{
			return (iter);
		}
		//operations overloading
		reference operator *(void) const
		{
			return (*iter);
		}
		reference operator[](difference_type n) const
		{
			return (iter[n]);
		}
		pointer operator ->(void) const
		{
			return (iter);
		}
		RaIterator& operator++(void)
		{
			iter++;
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
			iter--;
			return (*this);
		}
		RaIterator operator--(int)
		{
			RaIterator iter = *this;
			--(*this);
			return (iter);
		}
		RaIterator& operator+=(difference_type n)
		{
			iter+=n;
			return (*this);
		}
		RaIterator& operator-=(difference_type n)
		{
			iter-=n;
			return (*this);
		}
		RaIterator operator +(difference_type n)
		{
			RaIterator it = *this;
			it+= n;
			return (it);
		}
		RaIterator operator -(difference_type n)
		{
			RaIterator it = *this;
			it-= n;
			return (it);
		}
		template <class T>
		friend RaIterator<T> operator +(difference_type n, RaIterator<T> __x)
		{
			__x += n;
			return (__x);
		}
		// comparaison
		template <class T>
		friend bool operator==(RaIterator<T> __x, RaIterator<T> __y)
		{
			return __x.iter == __y.iter;
		}
		template <class T>
		friend bool operator<(RaIterator<T> __x, RaIterator<T> __y)
		{
			return (__x.iter < __y.iter);
		}
		template <class T>
		friend bool operator>(RaIterator<T> __x, RaIterator<T> __y)
		{
			return (__y < __x);
		}
		template <class T>
		friend bool operator!=(RaIterator<T> __x, RaIterator<T> __y)
		{
			return !(__x == __y);
		}
		template <class T>
		friend bool operator>=(RaIterator<T> __x, RaIterator<T> __y)
		{
			return !(__x < __y);
		}
		template <class T>
		friend bool operator<=(RaIterator<T> __x, RaIterator<T> __y)
		{
			return !(__y < __x);
		}
		template <class T>
		friend difference_type operator-(RaIterator<T> __x, RaIterator<T> __y)
		{
			return (__x.iter - __y.iter);
		}
		template <class T, class U>
		friend difference_type operator-(RaIterator<T> __x, RaIterator<U> __y)
		{
			return (__x.iter - __y.iter);
		}
		private :
		Iter	iter;
		
	};
 }
#endif 