# COLORS
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

# SYMBOLS
INFO = $(WHITE)[$(BLUE)ℹ️ $(WHITE)] 
SUCCESS = $(WHITE)[$(GREEN)✅$(WHITE)] $(GREEN)
WARNING = $(WHITE)[$(YELLOW)⚠️$(WHITE)] $(YELLOW)
ERROR = $(WHITE)[$(RED)❌$(WHITE)] $(RED)

# Binary
NAME=philo

# Path
SRC_PATH = ./
OBJ_PATH = ./objs/
INCDIR = includes

# Name
SRC_NAME = main.c          \
		   ft_atoi.c       \
		   ft_init_info.c  \
		   ft_init_philo.c \
		   ft_clear_philo.c\
		   ft_launcher.c   \
		   ft_utils.c      \
		   ft_routine.c    \
		   ft_check_philo.c 

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror


all: obj $(NAME)

obj:
	@echo "$(INFO)Creating objects folder... $(NOC)"
	@mkdir -p $(OBJ_PATH)
	@echo "$(SUCCESS)Objects folder created successfully$(NOC)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): obj $(OBJ)
	@echo "$(INFO)Building $(NAME)...$(NOC)"
	@$(CC) $(OBJ) -o $@
	@echo "$(SUCCESS)$(NAME) built successfully!$(NOC)"

clean:
	@echo "$(INFO)Deleting .o files...$(NOC)"
	@rm -rf $(OBJ_PATH)
	@echo "$(SUCCESS).o files deleted successfully!$(NOC)"

fclean: clean
	@echo "$(INFO)Deleting $(NAME)...$(NOC)"
	@rm -rf $(NAME)
	@echo "$(SUCCESS)$(NAME) deleted successfully!$(NOC)"

re: fclean all

.PHONY: all obj clean fclean re