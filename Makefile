NAME = fract_ol

NAME_BONUS = fract_ol_bonus

SRC = main.c \
	mandelbrot.c \
	julia.c \
	init.c \
	utils.c \
	ft_atof.c \
	mouse.c

SRC_BONUS = main_bonus.c \
		mandelbrot_bonus.c \
		julia_bonus.c \
		init_bonus.c \
		utils_bonus.c \
		ft_atof_bonus.c \
		mouse_bonus.c

LIBRARIES = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm 

INC_HEADER = includes

DIR_S = srcs

SRCS = $(addprefix ${DIR_S}/, ${SRC})

OBJS = $(SRCS:.c=.o)

CFLAGS = -I$(INC_HEADER) -Wall -Wextra -Werror

INC_HEADER_BONUS = includes

DIR_S_BONUS = srcs_bonus

SRCS_BONUS = $(addprefix ${DIR_S_BONUS}/, ${SRC_BONUS})

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CFLAGS_BONUS = -I$(INC_HEADER_BONUS) -Wall -Wextra -Werror

$(NAME) : $(OBJS)
			gcc -o $(NAME) $(SRCS) $(LIBRARIES) $(CFLAGS)

$(NAME_BONUS) : $(OBJS_BONUS)
			gcc -o $(NAME_BONUS) $(SRCS_BONUS) $(LIBRARIES) $(CFLAGS_BONUS) 

all	: $(NAME)

bonus	: $(NAME_BONUS)

clean	:
			rm -rf $(OBJS) $(OBJS_BONUS)

fclean	: clean

			rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: re clean fclean all