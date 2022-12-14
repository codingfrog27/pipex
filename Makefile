# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mde-cloe <mde-cloe@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/19 17:10:41 by mde-cloe      #+#    #+#                  #
#    Updated: 2022/11/27 14:33:03 by mde-cloe      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#-------General----------#

NAME 			:= pipex
CC				= gcc
COMPIL_FLAGS	?= -Wall -Wextra -g -o $@
#-Werror
LINKFLAGS 		?= -I include -I LIBFT

#-----sources-+-objects-----$

SOURCEFILES	:= 	pipex.c \
				path.c

OFILES	:=	$(SOURCEFILES:.c=.o)
SRC_DIR	:=	sources/
OBJ_DIR	:=	objects/
SOURCES	:=	$(addprefix $(SRC_DIR), $(SOURCEFILES))
OBJS	:=	$(addprefix $(OBJ_DIR), $(OFILES))


#-----------------targets---------------#

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(SRCS)
	@$(CC) $(OBJS) $(COMPIL_FLAGS) $(LINKFLAGS) LIBFT/libft.a
	@printf "\n$(C_GREEN)compiling! $(C_ORANGE)$@\n\n **$(C_BOLD)$(C_CYAN)all done <3$(C_ORANGE)s**\n$(C_RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) -c $< $(COMPIL_FLAGS) $(LINKFLAGS) && printf "$(C_GREEN)Compiling $(C_CYAN)$(notdir $<) \n$(C_RESET)"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@printf "$(C_RED)Files cleaned\n$(C_RESET)"

fclean: clean
	@rm -f $(NAME)

re: fclean all


#-----------testing--------------#

run: $(NAME)
	./pipex hey.txt "cat" "wc -l" doei.txt

#------------colours---------------#

C_RED		= \x1b[38;2;255;0;0m
C_LRED		= \x1b[38;2;255;128;128m
C_DRED		= \x1b[38;2;128;0;0m
C_LORANGE	= \x1b[38;2;255;192;128m
C_ORANGE	= \x1b[38;2;255;128;0m
C_DORANGE	= \x1b[38;2;128;64;0m
C_LYELLOW	= \x1b[38;2;255;255;128m
C_YELLOW	= \x1b[38;2;255;255;0m
C_DYELLOW	= \x1b[38;2;128;128;0m
C_LCHRT		= \x1b[38;2;192;255;128m
C_CHRT		= \x1b[38;2;128;255;0m
C_DCHRT		= \x1b[38;2;64;128;0m
C_LGREEN	= \x1b[38;2;128;255;128m
C_GREEN		= \x1b[38;2;0;255;0m
C_LCYAN		= \x1b[38;2;128;255;255m
C_CYAN		= \x1b[38;2;0;255;255m
C_DCYAN		= \x1b[38;2;0;128;128m
C_LAZURE	= \x1b[38;2;0;192;255m
C_AZURE		= \x1b[38;2;0;128;255m
C_DAZURE	= \x1b[38;2;0;64;128m
C_LBLUE		= \x1b[38;2;128;128;255m
C_BLUE		= \x1b[38;2;0;0;255m
C_DBLUE		= \x1b[38;2;0;0;128m
C_LVIOLET	= \x1b[38;2;192;0;255m
C_VIOLET	= \x1b[38;2;128;0;255m
C_DVIOLET	= \x1b[38;2;64;0;255m

C_RESET	= \x1b[0m
C_BOLD	= \x1b[1m