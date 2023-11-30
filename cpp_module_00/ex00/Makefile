# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 15:30:08 by ptungbun          #+#    #+#              #
#    Updated: 2023/10/31 14:03:11 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

# Variable declaration of directory

BUILD_DIR	=	./build
SRC_DIR		=	./srcs

# Variable declaration of file

SRCS		=	megaphone.cpp
OBJS		=	$(SRCS:%.cpp=$(BUILD_DIR)/%.o)

all: $(NAME)

# Build step for CPP source

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

bonus: all

clean:
	rm -rf $(BUILD_DIR)

fclean:
	rm -rf $(NAME) $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
