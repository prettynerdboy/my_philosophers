# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anakin <anakin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 19:50:41 by anakin            #+#    #+#              #
#    Updated: 2025/01/09 19:50:45 by anakin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = 	src/main.c\
		src/error.c\
		src/init.c\
		src/philo_utils.c\
		src/event_start.c\
		src/monitor.c\
		src/philo_event.c\
		src/message.c\
		src/monitor_utils.c\
		src/init_utils.c\
		src/event_utils.c
OBJDIR = ./obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
INCLUDE = -I ./include
CC	= cc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o : %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
