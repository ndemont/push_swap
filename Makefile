NAME				= push_swap
LIBFT				= libft.a
CHECK				= checker
CLEAR				= \033[2K\c
CC					= clang
RM					= rm -rf

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
					${MAKE} --silent -C ${LIBFT_DIR}

${NAME}:			${OBJS}
					${CC} ${CFLAGS} ${IFLAGS} push_swap.c -o $@ $^ ${LFLAGS}
					${CC} ${CFLAGS} ${IFLAGS} checker.c -o ${CHECK} $^ ${LFLAGS}

${OBJS_DIR}/%.o:	%.c
					@echo "${CLEAR}"
					@echo "compiling $<\r\c"
					@${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@
	
clean:
					${RM} ${OBJS_DIR}
					${MAKE} clean --silent -C ${LIBFT_DIR}

fclean:
					${RM} ${NAME}
					${RM} ${CHECK}
					${MAKE} fclean --silent -C ${LIBFT_DIR}

re:					fclean all

norme:
					~/.norminette/norminette.rb ${SRCS_DIR}
					~/.norminette/norminette.rb ${INC_DIR}

.SUFFIXES:			.c .o .h
.PHONY:				all clean fclean re
