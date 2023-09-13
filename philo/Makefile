### COMPILATION ###
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -pthread -g #-fsanitize=thread

### INCLUDES ###
INCLUDES	= -I ./
SRCS_PATH	= ./src
OBJS_PATH	= ./obj


### EXECUTABLE ###
NAME		= Philo

### SOURCES FILES ###
SOURCES		=	main.c \
				init.c \
				routine.c \
				utils.c \
				error.c \
				test.c \
				time.c \
				action.c \
				thread.c

### OBJECTS ###
SRCS 	= 	$(addprefix $(SRCS_PATH)/,$(SOURCE))
OBJS	=	$(addprefix $(OBJS_PATH)/,$(SOURCES:.c=.o))

### COLORS ###
_BLUE	=	\e[34m
_PURPLE	=	\e[35m
_CYAN	=	\e[36m
_RED	=	\e[91m
_GREEN	=	\e[92m
_END	=	\e[0m

all : 		tmp $(NAME)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
		 	@$(CC) $(CFLAGS) -c -o $@ $<
			@printf "$(_BLUE)Creating object file$(_END) $(_GREEN)-->>$(_END) $(WHITE)$(notdir $@)$(_END)	[$(_GREEN)✓$(_END)]\n"

$(NAME):	$(OBJS)
			@printf "Philosophers objects			[$(_GREEN)✓$(_END)]\n"
			@gcc $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)
			@printf "Philosophers				[$(_GREEN)✓$(_END)]\n"
			@printf "$(_GREEN)Philosophers$(_END) $(_RED)-------------------------------------->$(_END) [$(_GREEN)Ready to use$(_END)]\n"

tmp:
			@mkdir -p obj


### RULES ###


re:			fclean
			@$(MAKE) all

clean :
			@rm -rf $(OBJS_PATH)
			@printf "$(_PURPLE)Philosophers object	deleted$(_END)\n"

fclean :	clean
			@rm -rf $(NAME)
			@printf "$(_PURPLE)Philosophers		deleted$(_END)\n"

leaks :		all
			leaks --atExit -- ./$(NAME)
PHONY : re all clean fclean