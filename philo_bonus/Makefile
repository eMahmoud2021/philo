# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memam <memam@student.42mulhouse.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 16:56:37 by memam             #+#    #+#              #
#    Updated: 2022/08/12 23:56:17 by memam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = philo_bonus
SRCS  = srcs/philo_utils_bonus.c srcs/philo_main_bonus.c srcs/process_routine_bonus.c   srcs/init_bonus.c srcs/check_error_bonus.c
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