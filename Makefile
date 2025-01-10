#============    COMPILATION        ============
CC          =   gcc
CFLAGS      =   -Wall -Werror -Wextra -DGL_SILENCE_DEPRECATION

#============    STRUCTURE          ============
NAME        =   fractol
HEADER      =   inc/fractol.h

SRC         =   main.c              \
                utils.c             \
                error_handling.c    \
                init.c

SRC_DIR     =   src
OBJ_DIR     =   obj
INC_DIR     =   inc

OBJ_FILES   =   $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

#============    MLX LIBRARY        ============
MLX_NAME    =   MLX
MLX_PATH    =   inc/mlx_linux
MLX         =   $(MLX_PATH)/libmlx.a

#============    LIBFT LIBRARY      ============
LIBFT_NAME  =   LIBFT
LIBFT_PATH  =   inc/libft
LIBFT       =   $(LIBFT_PATH)/libft.a

#============    COLOURS            ============
CYAN        =   \033[36m
GREEN       =   \033[0;32m
RED         =   \033[0;31m
RESET       =   \033[0m

#============    BUILD TARGETS      ============
all: $(LIBFT) $(MLX) $(NAME)

$(MLX):
	@make -C $(MLX_PATH)
	@echo "$(NAME): $(GREEN)Library $(MLX_NAME) created$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_PATH)
	@echo "$(NAME): $(GREEN)Library $(LIBFT_NAME) created$(RESET)"

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx_Linux \
		-lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(NAME): $(CYAN)Executable $(NAME) created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_PATH) -I$(MLX_PATH) -c $< -o $@
	@echo "$(NAME): $(GREEN)Compiled $< to $@$(RESET)"

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)Object files removed$(RESET)"

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)Executable $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
