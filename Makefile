# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memam <memam@student.42mulhouse.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 16:56:37 by memam             #+#    #+#              #
#    Updated: 2022/08/12 16:37:00 by memam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = philo 
SRCS  = srcs/philo_utils.c srcs/philo_main.c srcs/thread_routine.c  srcs/init_structures.c srcs/check_error.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

NONE = '\033[0m'
GREEN = '\033[92m'
GRAY = '\033[90m'
RED = '\033[91m'
CURSIVE = '\033[3m'

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY)" -- Making philo --"$(NONE)
	gcc $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was created !$(NONE)"

clean:
	@echo $(CURSIVE)$(GRAY)" -- Deleting objects --"$(NONE)
	rm -rf $(OBJS)
	@echo "$(RED) objects was deleted !$(NONE)"

fclean: clean
	@echo $(CURSIVE)$(GRAY)" -- Deleting philo --"$(NONE)
	@rm -rf $(NAME)
	@echo "$(RED) philo was deleted !"$(NONE)

re: fclean all 

.PHONY: all clean fclean re 