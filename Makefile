NAME				= push_swap
LIBFT				= libft.a
CHECK				= checker
CC					= clang
RM					= rm -rf

WHITE				= \033[0;37m
GREEN				= \033[0;92m
YELLOW				= \033[0;93m
BLUE				= \033[0;94m
CYAN 				= \033[0;96m
PURPLE				= \033[0;95m
RED 				= \033[0;91m
CLEAR				= \033[2K

CFLAGS				= -Wall -Wextra -Werror
IFLAGS				= -I${INC_DIR} -I${LIBFT_DIR}/includes
LFLAGS				= -L ${LIBFT_DIR} -lft

SRCS_DIR			= srcs
INC_DIR				= includes
OBJS_DIR			= objs
LIBFT_DIR			= libft

INC				 	= $(shell find ${INC_DIR} -type f -name "*.h")
SRCS 				= $(notdir $(shell find ${SRCS_DIR} -type f -name "*.c"))
OBJS 				= $(addprefix ${OBJS_DIR}/, ${SRCS:.c=.o})
vpath				%.c $(shell find ${SRCS_DIR} -type d)
				
all: 				init ${NAME}

init:
					$(shell mkdir -p ${OBJS_DIR})
					@${MAKE} --silent -C ${LIBFT_DIR}

${NAME}:			${OBJS}
					@printf "🔧 compiling...\t\t${YELLOW}objects${WHITE}\n"
					@${CC} ${CFLAGS} ${IFLAGS} push_swap.c -o $@ $^ ${LFLAGS}
					@${CC} ${CFLAGS} ${IFLAGS} checker.c -o ${CHECK} $^ ${LFLAGS}
					@printf "🔢 creating...\t\t${GREEN}${NAME}${WHITE}\n"
					@printf "🔍 creating...\t\t${GREEN}${CHECK}${WHITE}\n"


${OBJS_DIR}/%.o:	%.c
					@printf "🔧 compiling...\t\t${YELLOW}$<${WHITE}"
					@${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@
					@printf "\r${CLEAR}"
	
clean:
					@printf "🧽 cleaning... \t\t${RED}${NAME}${WHITE}\n"
					@${RM} ${OBJS_DIR}
					@${MAKE} clean --silent -C ${LIBFT_DIR}

fclean:				clean
					@printf "🧼 deep cleaning... \t${RED}${NAME}${WHITE}\n"
					@printf "🧼 deep cleaning... \t${RED}${CHECK}${WHITE}\n"
					@${RM} ${NAME}
					@${RM} ${CHECK}
					@${MAKE} fclean --silent -C ${LIBFT_DIR}

re:					fclean all

norme:
					~/.norminette/norminette.rb ${SRCS_DIR}
					~/.norminette/norminette.rb ${INC_DIR}

.SUFFIXES:			.c .o .h
.PHONY:				all clean fclean re
