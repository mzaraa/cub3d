# Project: cub3d

NAME		:= icecream

#------------------------------------------------#
#					INGREDIENTS
#------------------------------------------------#
# SRCS		source files
# OBJS		object files
#
# CC		compiler
# CFLAGS	compiler flags
# CPPFLAGS	preprocessor flags

SRCS		:= test.c
OBJS		:= test.o

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I.

#------------------------------------------------#
#					UTENSILS
#------------------------------------------------#
# RM		force remove
# MAKEFLAGS	make flags


RM			:= rm -f
MAKEFLAGS	+= 

#------------------------------------------------#
#					RECIPES
#------------------------------------------------#
# all		default goal
# $(NAME)	linking .o -> binary
# clean		remove .o
# fclean	remove .o + binary
# re		remake default goal

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(info CREATED $(NAME))

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------------------------------#
#					SPEC
#------------------------------------------------#

.PHONY: clean fclean re
.SILENT: