NAME		:= libft.a

SRC_DIR		:= src
SRCS		:= \
			convert/ft_atoi.c 				\
			manip_memory/ft_bzero.c 				\
			manip_memory/ft_calloc.c 				\
			ctype/ft_isalnum.c 				\
			ctype/ft_isalpha.c 				\
			ctype/ft_isascii.c 				\
			ctype/ft_isdigit.c 				\
			ctype/ft_isprint.c 				\
			convert/ft_itoa.c 				\
			manip_memory/ft_memchr.c 				\
			manip_memory/ft_memcmp.c 				\
			manip_memory/ft_memcpy.c 				\
			manip_memory/ft_memmove.c 				\
			manip_memory/ft_memset.c 				\
			iostream/ft_putchar_fd.c 				\
			iostream/ft_putendl_fd.c 				\
			iostream/ft_putnbr_fd.c 				\
			iostream/ft_putstr_fd.c 				\
			cstring/ft_split.c 				\
			cstring/ft_strchr.c 				\
			cstring/ft_strdup.c 				\
			cstring/ft_striteri.c 				\
			cstring/ft_strjoin.c 				\
			cstring/ft_strlcat.c 				\
			cstring/ft_strlcpy.c 				\
			cstring/ft_strlen.c 				\
			cstring/ft_strmapi.c 				\
			cstring/ft_strncmp.c 				\
			cstring/ft_strcmp.c 				\
			cstring/ft_strnstr.c 				\
			cstring/ft_strrchr.c 				\
			cstring/ft_strtrim.c 				\
			cstring/ft_substr.c 				\
			ctype/ft_tolower.c 				\
			ctype/ft_toupper.c 				\
			linked_list/ft_lstadd_back.c 				\
			linked_list/ft_lstadd_front.c 				\
			linked_list/ft_lstclear.c 				\
			linked_list/ft_lstdelone.c 				\
			linked_list/ft_lstiter.c 				\
			linked_list/ft_lstlast.c 				\
			linked_list/ft_lstmap.c 				\
			linked_list/ft_lstnew.c 				\
			linked_list/ft_lstsize.c 				\
			iostream/gnl/get_next_line.c 			\
			iostream/gnl/get_next_line_utils.c 		\

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -MMD -MP -I include
AR			:= ar
ARFLAGS		:= -r -c -s

RM			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	@$(RM) $(OBJS) $(DEPS)

fclean: clean
	@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re