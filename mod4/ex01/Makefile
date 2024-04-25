# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janraub <janraub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 12:14:47 by jberay            #+#    #+#              #
#    Updated: 2024/04/25 10:16:10 by janraub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	animal

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -g -fsanitize=address
RM				=	rm -rf

SRCS 			=	main.cpp \
					Animal.cpp \
					Dog.cpp \
					Cat.cpp \
					WrongAnimal.cpp \
					WrongCat.cpp \
					Brain.cpp
						
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