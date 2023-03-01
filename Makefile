# Project: cub3D
NAME	:= cub3D

LIBS		:= ft
LIBS_TARGET :=	\
	lib/libft/libft.a		\


INCS		:= \
	include					\
	lib/libft/include		\

SRC_DIR		:= src
SRCS		:=	\
	core/main.c				\
	core/ft_exit_program.c	\
	parser/parser.c			\
	parser/check_args.c		\
	parser/check_double.c \
	parser/check_file_line.c \
	parser/parse_identifier.c \
	parser/parse_rgb.c \
	parser/error_empty_line.c \
	parser/parse_texture.c \
	parser/parse_raw_map.c \
	parser/fill_map.c \
	utils/usefull_func.c \
	game/run_game.c \
	game/handle_key.c \
	game/render.c \
	game/math_utils.c \
	game/raycast.c \
	game/draw.c \

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l,$(LIBS))

RM			:= rm -f
MAKEFLAGS	+= --silent --no-print-directory
DIR_DUP		= mkdir -p $(@D)

all: libft $(NAME) 

libft:
	@$(MAKE) -C lib/libft

#			LINUX		##############################################################################################
#$(NAME): $(OBJS) $(LIBS_TARGET)
#	@$(CC) $(LDFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LDLIBS) -o $(NAME)
#	$(info CREATED $(NAME))

#$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
#	@$(DIR_DUP)
#	@$(CC) $(CFLAGS) $(CPPFLAGS) -I/usr/include -Imlx_linux -O3  -c -o $@ $<
#	$(info CREATED $@)
######################################################################################################################


#			MACOS		##############################################################################################
$(NAME): $(OBJS) $(LIBS_TARGET)
	@$(CC) $(LDFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit $(LDLIBS) -o $(NAME)
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -Imlx -c -o $@ $<
	$(info CREATED $@)
######################################################################################################################

-include $(DEPS)

clean:
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	@$(RM) $(OBJS) $(DEPS)

fclean: clean
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	@$(RM) $(NAME) $(MINILIBX_DIR)$(MINILIBX)

re:
	@$(MAKE) fclean
	@$(MAKE) all

git:
	git add .
	git commit -m "auto update cub3D"
	git push

.PHONY: all clean fclean re libft
