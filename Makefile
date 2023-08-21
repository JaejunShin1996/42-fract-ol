NAME	= 	fractol

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror
LINK	=	-lmlx  -framework OpenGL -framework AppKit

SRCS	= 	sources/*.c \
			libft/libft.a

$(NAME):
	@make all -C libft
	@$(CC) $(CFLAGS) $(LINK) -L ./minilibx $(SRCS) -o $(NAME)
	@echo "Fractol has been created"

all: $(NAME)

clean:
	@make clean -C libft
	@rm -f $(NAME)
	@echo "Fractol has been cleaned"

fclean: clean
	@make fclean -C libft
	@echo "Fractol has been fcleaned"

re: fclean all

.PHONY: all, clean, fclean, re
