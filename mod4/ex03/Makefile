# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberay <jberay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 12:14:47 by jberay            #+#    #+#              #
#    Updated: 2024/07/04 09:14:47 by jberay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	materia

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

SRCS 			=	main.cpp \
					AMateria.cpp \
					Character.cpp \
					Cure.cpp \
					Ice.cpp \
					LinkedList.cpp \
					MateriaSource.cpp \
					Node.cpp
						
OBJS			=	$(SRCS:%.cpp=%.o)

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 
					
%.o:%.cpp
					@$(CC) $(CFLAGS) -c $< -o $@		

clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)
					
re:					fclean all

.PHONY:				all clean fclean re