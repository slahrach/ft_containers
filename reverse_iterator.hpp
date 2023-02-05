/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:04:57 by slahrach          #+#    #+#             */
/*   Updated: 2023/02/04 11:49:00 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
 #define REVERSE_ITERATOR_HPP
 namespace ft
 {
	template <typename Iter>
	class reverse_iterator
	{
		public :
		typedef typename Iter::value_type		value_type;
		typedef typename Iter::defference_type	difference_type;
		typedef value_type*						pointer;
		typedef value_type&						reference;
		reverse_iterator() : current() {}
		reverse_iterator(Iter __x) : current(__x) {};
		~reverse_iterator() {};
		Iter getCurrent(void) const
		{
			return current;
		}
		template <typename it>
		reverse_iterator(reverse_iterator<it>& copy) : current(copy.getCurrent()){};
		template <typename it>
		reverse_iterator& operator=(reverse_iterator<it>& obj)
		{
			this->current = obj.getCurrent();
			return (*this);
		};
		//operations overloading
		reference operator *(void) const
		{
			Iter	tmp = current;
			--tmp;
			return (*tmp);
		}
		reference operator[](difference_type n) const
		{
			return (current[n]);
		}
		pointer operator ->(void) const
		{
			return (current);
		}
		reverse_iterator& operator++(void)
		{
			current--;
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
			current++;
			return (*this);
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator iter = *this;
			++(*this);
			return (iter);
		}
		reverse_iterator operator +(difference_type n) const
		{
			return (reverse_iterator(current - n));
		}
		reverse_iterator operator -(difference_type n) const
		{
			return (reverse_iterator(current + n));
		}
		reverse_iterator& operator+=(difference_type n)
		{
			current-=n;
			return (*this);
		}
		reverse_iterator& operator-=(difference_type n)
		{
			current+=n;
			return (*this);
		}
		// non member functions
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
			return __x.getCurrent() == __y.getCurrent();
		}
		template <class T>
		friend bool operator<(reverse_iterator<T>& __x, reverse_iterator<T>& __y)
		{
			return (__x.getCurrent > __y.getCurrent);
		}
		template <class T>
		friend bool operator>(reverse_iterator<T>& __x, reverse_iterator<T>& __y)
		{
			return (__x.getCurrent < __y.getCurrent);
		}
		template <class T>
		friend bool operator!=(reverse_iterator<T>& __x, reverse_iterator<T>& __y)
		{
			return !(__x == __y);
		}
		template <class T>
		friend bool operator>=(reverse_iterator<T>& __x, reverse_iterator<T>& __y)
		{
			return (__x.getCurrent() <= __y.getCurrent());
		}
		template <class T>
		friend bool operator<=(reverse_iterator<T>& __x, reverse_iterator<T>& __y)
		{
			return (__x.getCurrent() >= __y.getCurrent());
		}
		template <class T>
		friend difference_type operator-(reverse_iterator<T>& __x, reverse_iterator<T>& __y)
		{
			return (__y.getCurrent() - __x.getCurrent());
		}
		template <class iter>
		friend reverse_iterator<iter> make_reverse_iterator(Iter i)
		{
			return (reverse_iterator<iter>(i));
		}
		private :
		Iter	current;
		
	};
 }
#endif 