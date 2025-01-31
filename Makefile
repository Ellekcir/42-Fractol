#============    COMPILATION        ============
CC          = cc
CFLAGS      = -Wall -Werror -Wextra 
OS          = $(shell uname)
MAKE        = make -s
MKDIR       = mkdir -p
RM          = rm -rf

#============    STRUCTURE          ============
NAME        = fractol

#============    LIBFT LIBRARY      ============
LIBFT_DIR   = inc/libft
LIBFT       = $(LIBFT_DIR)/libft.a
LIBFT_NAME  = LIBFT
LIBFT_MAKE  = $(MAKE) -C $(LIBFT_DIR)

#============    MINILIBX LIBRARY   ============
ifeq ($(OS), Linux)
    MLX_DIR     = inc/mlx_linux
    MLX         = $(MLX_DIR)/libmlx.a
    MLX_LINK    = -lmlx -lm -lz -lXext -lX11 -L$(MLX_DIR)
else
    MLX_DIR     = inc/mlx_opengl
    MLX         = $(MLX_DIR)/libmlx.a
    MLX_LINK    = -lmlx -lm -framework OpenGL -framework AppKit -L$(MLX_DIR)
endif
MLX_NAME    = MLX
MLX_MAKE    = $(MAKE) -C $(MLX_DIR)

#============    DIRECTORIES        ============
INC_DIR     = inc
SRC_DIR     = src
OBJ_DIR     = obj

#============    FILES              ============
SRC_FILES   = main.c \
              error_handling.c \
              init.c \
              utils_maths.c \
              utils_string.c \
              render.c \
              events.c
SRC         = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ         = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
INC         = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

#============    COLORS             ============
PURPLE      = \033[0;35m
CYAN        = \033[36m
GREEN       = \033[0;32m
RED         = \033[0;31m
RESET       = \033[0m

#============    BUILD TARGETS      ============
all: $(LIBFT) $(MLX) $(OBJ_DIR) $(NAME)

$(LIBFT):
	@echo "$(CYAN)$(LIBFT_NAME): Building...$(RESET)"
	@$(LIBFT_MAKE)
	@echo "$(GREEN)$(LIBFT_NAME): Built successfully!$(RESET)"

$(MLX):
	@echo "$(CYAN)$(MLX_NAME): Building...$(RESET)"
	@$(MLX_MAKE)
	@echo "$(GREEN)$(MLX_NAME): Built successfully!$(RESET)"

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/fractol.h
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@


$(NAME): $(OBJ)
	@echo "$(CYAN)$(NAME): Linking...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_LINK) -o $(NAME)
	@echo "$(GREEN)$(NAME): Built successfully!$(RESET)"
	@echo "$(GREEN)Run with ./$(NAME) mandelbrot or ./$(NAME) julia <x> <y>$(RESET)"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)Object files cleaned!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(LIBFT_MAKE) fclean
	@$(MLX_MAKE) clean
	@echo "$(RED)All files cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re


