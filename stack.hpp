/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:32:41 by slahrach          #+#    #+#             */
/*   Updated: 2023/02/07 19:33:30 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
 #define STACK_HPP
 #include "Vector.hpp"
 namespace ft
 {
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public :
		typedef Container								container_type;
		typedef typename container_type::value_type      value_type;
		typedef typename container_type::size_type       size_type;
		protected :
		container_type c;
		public :
		explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}
		stack( const stack& other ) : c(other.c){};
		stack& operator=(const stack& __q) {c = __q.c; return *this;}
		T& top() {return c.back();}
		const T& top() const {return c.back();}
		bool empty() const {return c.empty();}
		size_type size() const {return c.size();}
		void push(const value_type& __v) {c.push_back(__v);}
		void pop() {c.pop_back();}
    };
	template <class _Tp, class _Container>
	bool operator==(const stack<_Tp, _Container>& f, const stack<_Tp, _Container>& s)
	{
		return f.c == s.c;
	}
	template <class _Tp, class _Container>
	bool operator!=(const stack<_Tp, _Container>& f, const stack<_Tp, _Container>& s)
	{
		return f.c != s.c;
	}
	template <class _Tp, class _Container>
	bool operator<(const stack<_Tp, _Container>& f, const stack<_Tp, _Container>& s)
	{
		return f.c == s.c;
	}
	template <class _Tp, class _Container>
	bool operator>(const stack<_Tp, _Container>& f, const stack<_Tp, _Container>& s)
	{
		return f.c == s.c;
	}
	template <class _Tp, class _Container>
	bool operator<=(const stack<_Tp, _Container>& f, const stack<_Tp, _Container>& s)
	{
		return f.c == s.c;
	}
	template <class _Tp, class _Container>
	bool operator>=(const stack<_Tp, _Container>& f, const stack<_Tp, _Container>& s)
	{
		return f.c == s.c;
	}
 }
 
#endif