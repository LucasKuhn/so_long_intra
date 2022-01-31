NAME		=	so_long
NAME_BONUS	=	so_long_bonus
LIBFT_DIR	=	./libft
LIBFT_A		=	$(LIBFT_DIR)/libft.a
CC			=	gcc
MLXFLAGS	=	-lmlx -Ilmlx -lXext -lX11
ifeq ($(shell uname),Darwin) # MacOS
	MLXFLAGS	+=	-framework OpenGL -framework AppKit
	LEAK_FLAGS	=	-g3 -fsanitize=address
endif
LIBFT_FLAGS	=	-L./libft -lft
CFLAGS		=	-Wall -Wextra -Werror
FLAGS		=	$(LIBFT_FLAGS) $(MLXFLAGS) $(LEAK_FLAGS)
OBJ_DIR		=	obj
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
SRCS_BONUS	=	movement_bonus.c \
				map_loader_bonus.c \
				utils_bonus.c \
				map_validator_bonus.c \
				load_images_bonus.c \
				draw_sprites_bonus.c \
				draw_player_bonus.c \
				misc_bonus.c \
				main_bonus.c \
				close_game_bonus.c
OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=$(OBJ_DIR)/%.o)
VPATH		=	src src_bonus

all: $(NAME)

bonus: $(NAME_BONUS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@ -I ./

$(NAME):  $(OBJ_DIR) $(OBJS) $(LIBFT_A)
	$(CC) $(OBJS) $(FLAGS) -o $(NAME) $(LIBFT_FLAGS)

$(NAME_BONUS): $(OBJ_DIR) $(OBJS_BONUS) $(LIBFT_A)
	$(CC) $(OBJS_BONUS) $(FLAGS) -o $(NAME_BONUS) $(LIBFT_FLAGS)

$(LIBFT_A):
	make --directory=$(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p obj

clean:
	make -C ./libft clean
	@rm -rf obj
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean