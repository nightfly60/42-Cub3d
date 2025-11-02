NAME = cub3D
MLX = mlx_linux

LIBFT_DIR = libft
OBJDIR = obj
LIBFT := $(LIBFT_DIR)/libft.a

MINIMAP_FILES = minimap/minimap_data.c minimap/position_data.c minimap/create_image.c minimap/update_player_data.c

GAME =	game/display_fisheye.c game/display_game.c game/display_fps.c game/display_game_bg.c game/display_crosshair.c \
		game/init_textures.c

UTILS_FILES = utils/ft_color.c utils/ft_drawline.c utils/exit_game.c utils/put_pixel.c utils/close_game.c utils/init_game.c

KEYS_FILES = keys/ft_key_hook.c keys/ply_directions.c keys/ply_movements.c

LIBFT_SRCS := libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
			libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c \
			libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
			libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c \
			libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c \
			libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_lstadd_front_bonus.c \
			libft/ft_lstnew_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstlast_bonus.c libft/ft_lstadd_back_bonus.c \
			libft/ft_lstdelone_bonus.c libft/ft_lstclear_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c \
			libft/ft_putnbr_unsigned.c libft/ft_printf.c libft/get_next_line/get_next_line.c \
			libft/get_next_line/get_next_line_utils.c libft/ft_freeall.c libft/ft_lstget.c libft/ft_lstget.c libft/ft_maxf.c

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(FILES))

FILES = main.c $(MINIMAP_FILES) $(UTILS_FILES) $(KEYS_FILES) $(GAME)

INCLUDES = includes
INCLUDE_FILES = includes/cub3d.h

RESET = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;90m
LIGHTBLUE = \033[1;94m

all: $(MLX) $(LIBFT) $(NAME)

$(MLX):
	@wget https://cdn.intra.42.fr/document/document/42054/minilibx-linux.tgz
	@tar -xf minilibx-linux.tgz
	@rm minilibx-linux.tgz
	@mv minilibx-linux mlx_linux
	@cd mlx_linux && ./configure
	@echo "$(YELLOW) 🔨 MinilibX Configured$(RESET)"

$(LIBFT): $(LIBFT_SRCS)
	$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -Lmlx_linux -lmlx -lXext -lX11 -lm -lz -L$(LIBFT_DIR) -lft

$(OBJDIR)/%.o: %.c $(INCLUDE_FILES)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BNAME)
	$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: fclean clean all re
