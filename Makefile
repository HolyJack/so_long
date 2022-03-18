NAME			=	so_long

INC_DIR	= include/
SRC_DIR	= src/
OBJ_DIR	= obj/

INC_DIR_G = /usr/include
MLX_DIR	  = mlx/
MLX		  = mlx
MLX_LINUX = mlx_Linux

NAMES   = 	so_long sl_field sl_game sl_render\
			sl_inputs sl_arrlen sl_arrchr\
			get_next_line get_next_line_utils\
			sl_free_field\
			ft_putnbr_fd ft_putstr_fd ft_putchar_fd

SRC		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(NAMES)))
OBJ 	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(NAMES)))

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
OPFLAGS	= -O3

RM		= rm -f
MD		= mkdir -p

all : $(NAME)

$(NAME): $(OBJ) Makefile
		@$(CC) $(CFLAGS) $(OPFLAGS) $(OBJ) -L$(MLX_DIR) -l$(MLX_LINUX) -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o ${NAME}
		@echo "\033[32mCompiled"

mlx/mlx_Linux:
		 @$(MAKE) -C $(MLX_DIR) --silent

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c | mlx/mlx_Linux
		@$(MD) $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(OPFLAGS) -c -I$(INC_DIR) -I$(INC_DIR_G) -I$(MLX_DIR) $< -L$(MLX_DIR) -l$(MLX_LINUX) -o $@

clean:
		@$(RM) $(OBJ)
fclean: clean
		@$(MAKE) -C $(MLX_DIR) --silent clean
		@$(RM) $(NAME)

re: fclean all
	
.PHONY: clean fclean re all
