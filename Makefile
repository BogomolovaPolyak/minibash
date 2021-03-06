# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkarliah <lkarliah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 19:26:13 by natali            #+#    #+#              #
#    Updated: 2021/09/02 20:44:26 by lkarliah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= minibash

CFLAGS		= -lreadline -Wall -Wextra -Werror

LIBFT_FLAGS = -L./libft -lft

TERMCAP		= -ltermcap

SRCS_DIR	= srcs/

HEADER_DIR	= includes

SRC			= main.c \
			builtins/ft_echo.c \
			builtins/ft_cd.c \
			builtins/ft_pwd.c \
			builtins/ft_export.c \
			builtins/ft_export_print.c \
			builtins/ft_unset.c \
			builtins/ft_env.c \
			builtins/ft_exit.c \
			builtins/shlvl.c \
			cmd/cmd_utils.c \
			cmd/exec_cmd.c \
			cmd/path_utils.c \
			pipes_and_redirects/redirect.c \
			pipes_and_redirects/heredoc_redirect.c \
			pipes_and_redirects/add_pipe.c \
			parser/parser.c \
			parser/parse_utils.c \
			parser/parse_builtins.c \
			parser/parse_dollar.c \
			term/setup_term.c \
			term/signals.c \
			term/prompt.c \
			term/input_1.c \
			term/input_2.c \
			term/keys.c \
			history/double_list.c \
			history/hist.c \
			envp/env_1.c \
			envp/env_2.c \
			envp/env_3.c

SRCS 		= $(addprefix $(SRCS_DIR), $(SRC))

OBJS		= $(SRCS:.c=.o)

DEPENDS 	= $(SRCS:.c=.d)

INC			= includes/

LIB_DIR 	= libft/

RM			= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C ./libft
			gcc $(CFLAGS) -I $(INC) $(LIBFT_FLAGS) $(TERMCAP) $^ -o $(NAME)

%.o:		%.c Makefile
			gcc -I $(INC) -MMD -MP -c $< -o $@

bonus:		all

clean:
			@make clean -C ./libft
			@$(RM) $(OBJS) $(DEPENDS)

fclean:		clean
			@make fclean -C ./libft
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean
