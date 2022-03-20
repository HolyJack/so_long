NAME			=	so_long

INC_DIR	= include/
SRC_DIR	= src/
OBJ_DIR	= obj/

INC_DIR_G = /usr/include
MLX_DIR	  = mlx/
MLX		  = mlx
MLX_LINUX = mlx_Linux

NAMES   = 	so_long			sl_field		sl_game\
			sl_inputs		sl_arrlen		sl_arrchr\
			get_next_line	sl_error_exit	get_next_line_utils\
			sl_free_field	sl_render		ft_strncmp\
			ft_putnbr_fd 	ft_putstr_fd	ft_putchar_fd\

SRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(NAMES)))
OBJ 	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(NAMES)))
D_FILES	=	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(NAMES)))


CC		= cc
CFLAGS	= -Wall -Wextra -Werror -O3

MD		= mkdir -p

all : $(NAME)

$(MLX_DIR)$(MLX):
			@$(MAKE) -C $(MLX_DIR)

$(NAME):	$(OBJ) Makefile | $(MLX_DIR)$(MLX)
			$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) -l$(MLX_LINUX) -lXext -lX11 -lm -lz -o ${NAME}

$(OBJ_DIR):
			@$(MD) $(OBJ_DIR)

$(OBJ):		$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -c -I$(INC_DIR) -I$(INC_DIR_G) -I$(MLX_DIR) $< -L$(MLX_DIR) -l$(MLX_LINUX) -o $@ -MD
include $(wildcard $(D_FILES))

clean:
		@$(RM) $(OBJ) ${D_FILES}
	
fclean: clean
		@$(MAKE) -C $(MLX_DIR) --silent clean
		@$(RM) $(NAME)

re: fclean all
	
.PHONY: clean fclean re all
