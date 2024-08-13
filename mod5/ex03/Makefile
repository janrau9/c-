# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberay <jberay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 12:14:47 by jberay            #+#    #+#              #
#    Updated: 2024/08/13 12:05:01 by jberay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	out

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

SRCS 			=	Bureaucrat.cpp \
					main.cpp \
					AForm.cpp \
					ShrubberyCreationForm.cpp \
					RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp \
					Intern.cpp
						
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