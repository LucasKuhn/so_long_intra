NAME		= so_long
LIBFT_DIR	= ./libft
LIBFT_A		= $(LIBFT_DIR)/libft.a
CC			= gcc
MLXFLAGS	= -lmlx -Ilmlx -lXext -lX11
ifeq ($(shell uname),Darwin) # MacOS
	MLXFLAGS	+= -framework OpenGL -framework AppKit
	LEAK_FLAGS	= -g3 -fsanitize=address
endif
LIBFT_FLAGS	= -L./libft -lft
CFLAGS		= -g3 -Wall -Wextra -Werror
FLAGS		= $(LIBFT_FLAGS) $(MLXFLAGS) $(LEAK_FLAGS)
SRCS		=	movement.c \
				map_loader.c \
				utils.c \
				map_validator.c \
				load_images.c \
				draw_sprites.c \
				draw_player.c \
				misc.c \
				main.c \
				close_game.c
OBJS		= $(SRCS:%.c=%.o)

all: $(NAME)

bonus: $(NAME)

.c.o:
	$(CC) $(CFLAGS)  -c $< -o $(<:.c=.o)

$(NAME):  $(OBJS) $(LIBFT_A)
	$(CC) $(OBJS) $(FLAGS) -o $(NAME) $(LIBFT_FLAGS)

$(LIBFT_A):
	make --directory=$(LIBFT_DIR)

clean:
	@rm -rf *.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean