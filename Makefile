NAME				= push_swap
CLEAR				= \033[2K\c
CC					= clang
RM					= rm -rf

CFLAGS				= -Wall -Wextra -Werror
IFLAGS				= -I${INC_DIR}

SRCS_DIR			= srcs
INC_DIR				= includes
OBJS_DIR			= objs

INC        		 	= $(shell find ${INC_DIR} -type f -name "*.h")
SRCS 				= $(notdir $(shell find ${SRCS_DIR} -type f -name "*.c"))
OBJS 				= $(addprefix ${OBJS_DIR}/, ${SRCS:.c=.o})
vpath				%.c $(shell find ${SRCS_DIR} -type d)
				
all: 				init ${NAME}

init:
					$(shell mkdir -p ${OBJS_DIR})

${NAME}:			${OBJS}
					${CC} ${CFLAGS} ${IFLAGS} -o $@ $^ 

${OBJS_DIR}/%.o:	%.c
					@echo "${CLEAR}"
					@echo "compiling $<\r\c"
					@${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@
	
clean:
					${RM} ${OBJS_DIR}

fclean:
					${RM} ${OBJS_DIR}
					${RM} ${NAME}

re:					fclean all

norme:
					~/.norminette/norminette.rb ${SRCS_DIR}
					~/.norminette/norminette.rb ${INC_DIR}

.SUFFIXES:			.c .o .h
.PHONY:				all clean fclean re
