# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 15:30:08 by ptungbun          #+#    #+#              #
#    Updated: 2024/03/09 17:03:40 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	PmergeMe
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

# Variable declaration of directory

BUILD_DIR	=	./build

# Variable declaration of file

SRCS		=	main.cpp PmergeMe.cpp
HDFS		=	PmergeMe.hpp
OBJS		=	$(SRCS:%.cpp=$(BUILD_DIR)/%.o)

all: $(NAME)

# Build step for CPP source

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: %.cpp $(HDFS)
	@mkdir -p $(@D)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

bonus: all

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME) $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
