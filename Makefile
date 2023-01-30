# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 04:00:20 by slahrach          #+#    #+#              #
#    Updated: 2023/01/28 04:00:38 by slahrach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CC = c++

CFLAGS = -Wall -Wextra -Werror

STDFLAGS = -std=c++98

SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${STDFLAGS} ${OBJS} -o ${NAME}

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

%.o : %.cpp
	${CC} ${CFLAGS} ${STDFLAGS} -c $<

.PHONY: clean all fclean re