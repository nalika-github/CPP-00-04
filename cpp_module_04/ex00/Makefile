# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 15:30:08 by ptungbun          #+#    #+#              #
#    Updated: 2023/11/29 10:18:28 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Animal
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

# Variable declaration of directory

BUILD_DIR	=	./build

# Variable declaration of file

SRCS		=	main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
OBJS		=	$(SRCS:%.cpp=$(BUILD_DIR)/%.o)

all: $(NAME)

# Build step for CPP source

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

bonus: all

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME) $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
