# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 16:05:14 by minseok2          #+#    #+#              #
#    Updated: 2023/02/06 16:44:21 by minseok2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf

HEADER_DIR = includes

SRCS_DIR = srcs
SRCS = main.c \
	   init/init.c \
	   init/init_functions/init_rule.c \
	   init/init_functions/init_break_flag.c \
	   init/init_functions/init_start_mutex.c \
	   init/init_functions/init_fork_arr.c \
	   init/init_functions/init_philo_arr.c \
	   init/init_functions/init_tid_arr.c \
	   create_thread/create_thread.c \
	   create_thread/dining_routine.c \
	   create_thread/dining_routine_functions/eat.c \
	   create_thread/dining_routine_functions/pickup_left_fork.c \
	   create_thread/dining_routine_functions/pickup_right_fork.c \
	   create_thread/dining_routine_functions/putdown_left_fork.c \
	   create_thread/dining_routine_functions/putdown_right_fork.c \
	   create_thread/dining_routine_functions/go_sleep.c \
	   create_thread/dining_routine_functions/think.c \
	   create_thread/dining_routine_functions/utils/is_break_flag_on.c \
	   monitoring/monitoring.c \
	   join_thread/join_thread.c \
	   error/error.c \
	   utils/ascii_to_ull.c \
	   utils/convert_to_ms_time.c \
	   utils/ft_malloc.c \
	   utils/ft_pthread_mutex_init.c \
	   utils/ft_usleep.c \
	   utils/get_current_time.c \
	   utils/print_msg.c

OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS_DIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re:
	make fclean
	make all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)/{init/init_functions,create_thread/dining_routine_functions/utils,monitoring,join_thread,error,utils,}
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_DIR)

.PHONY : all clean fclean re
