# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/23 17:10:27 by ahandsom          #+#    #+#              #
#    Updated: 2020/02/23 17:23:29 by ahandsom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# files
SRC	= main.c draw.c read_map.c set.c utils.c deal_key.c
OBJ = $(SRC:.c=.o)

# directories

SRC_DIR = ./src/
OBJ_DIR = ./obj/
MLX_DIR = ./libs/minilibx_macos/
LIB_DIR = ./libs/libft/

# files with their paths
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))

# compile
CC = gcc
HEADERS = -I includes -I $(LIB_DIR)/includes -I $(MLX_DIR)
CFLAGS = -c -Wall -Werror -Wextra
LIBS = -L $(LIB_DIR) -lft -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "[$(CC)] - $<"
	@$(CC) $(CFLAGS) $(HEADERS) $< -o $@

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIB_DIR)
	@$(CC) $(OBJS) $(LIBS) -o $@
	@echo "\033[92m ------- $(NAME) built and ready ------- \033[0m"

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(MLX_DIR) clean
	@make -C $(LIB_DIR) clean
	@echo "\033[92m ------- $(NAME) cleaned ------- \033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_DIR) fclean
	@echo "\033[92m ------- $(NAME) fcleaned ------- \033[0m"

re: fclean all