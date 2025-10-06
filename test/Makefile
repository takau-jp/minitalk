# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 19:52:15 by stanaka2          #+#    #+#              #
#    Updated: 2025/09/08 16:06:46 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAME_1 = client
NAME_2 = server
CC = cc

# FLAGS
CFLAGS = -Wall -Wextra -Werror
DEPSFLAGS = -MMD

# libft
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
LIBFT_INCLUDE = -I ${LIBFT_DIR}/includes

# INCLUDE
INCLUDE = -I includes ${LIBFT_INCLUDE}

# srcs
CLIENT_SRCDIR = mandatory/client
SERVER_SRCDIR = mandatory/server
CLIENT_SRCS = ${addprefix ${CLIENT_SRCDIR}/, client.c}
CLIENT_SRCS += ${addprefix ${CLIENT_SRCDIR}/, \
				check_pid.c \
				errors.c \
			}
SERVER_SRCS = ${addprefix ${SERVER_SRCDIR}/, server.c}
SERVER_SRCS += ${addprefix ${SERVER_SRCDIR}/, \
				print_server_pid.c \
				receive_bit.c \
				process_byte.c \
			}

B_CLIENT_SRCDIR = bonus/client
B_SERVER_SRCDIR = bonus/server
B_UTF8_SRCDIR = bonus/utf8
B_UTF8_SRCS = ${addprefix ${B_UTF8_SRCDIR}/, utf8_validate_and_append_byte_bonus.c \
				utf8_utils_bonus.c \
				check_utf8_code_point_bonus.c \
			}
B_CLIENT_SRCS = ${addprefix ${B_CLIENT_SRCDIR}/, client_bonus.c}
B_CLIENT_SRCS += ${addprefix ${B_CLIENT_SRCDIR}/, \
				check_pid_bonus.c \
				errors_bonus.c \
				utf8_validation_and_replacement_bonus.c \
			}
B_CLIENT_SRCS += ${B_UTF8_SRCS}
B_SERVER_SRCS = ${addprefix ${B_SERVER_SRCDIR}/, server_bonus.c}
B_SERVER_SRCS += ${addprefix ${B_SERVER_SRCDIR}/, \
				print_server_pid_bonus.c \
				receive_bit_bonus.c \
				process_byte_bonus.c \
			}
B_SERVER_SRCS += ${B_UTF8_SRCS}

# objs
CLIENT_OBJDIR = objs_client
SERVER_OBJDIR = objs_server
CLIENT_OBJS = ${addprefix ${CLIENT_OBJDIR}/, ${notdir ${CLIENT_SRCS:.c=.o}}}
SERVER_OBJS = ${addprefix ${SERVER_OBJDIR}/, ${notdir ${SERVER_SRCS:.c=.o}}}

B_CLIENT_OBJS = ${addprefix ${CLIENT_OBJDIR}/, ${notdir ${B_CLIENT_SRCS:.c=.o}}}
B_SERVER_OBJS = ${addprefix ${SERVER_OBJDIR}/, ${notdir ${B_SERVER_SRCS:.c=.o}}}

# deps
CLIENT_DEPS	= ${addprefix ${CLIENT_OBJDIR}/, ${notdir ${CLIENT_SRCS:.c=.d}}}
SERVER_DEPS	= ${addprefix ${SERVER_OBJDIR}/, ${notdir ${SERVER_SRCS:.c=.d}}}

B_CLIENT_DEPS	= ${addprefix ${CLIENT_OBJDIR}/, ${notdir ${B_CLIENT_SRCS:.c=.d}}}
B_SERVER_DEPS	= ${addprefix ${SERVER_OBJDIR}/, ${notdir ${B_SERVER_SRCS:.c=.d}}}

# bonus
ifeq ($(MAKECMDGOALS), bonus)
CLIENT_OBJS = ${B_CLIENT_OBJS}
SERVER_OBJS = ${B_SERVER_OBJS}
CLIENT_DEPS	= ${B_CLIENT_DEPS}
SERVER_DEPS	= ${B_SERVER_DEPS}
endif

all: ${NAME}

${NAME}: ${NAME_1} ${NAME_2}

${NAME_1}: ${CLIENT_OBJS} ${LIBFT}
	${CC} $^ -o $@

${NAME_2}: ${SERVER_OBJS} ${LIBFT}
	${CC} $^ -o $@

${LIBFT}:
	@make -C $(LIBFT_DIR)

${CLIENT_OBJDIR}:
	-mkdir -p ${CLIENT_OBJDIR}

${SERVER_OBJDIR}:
	-mkdir -p ${SERVER_OBJDIR}

${CLIENT_OBJDIR}/%.o: ${CLIENT_SRCDIR}/%.c | ${CLIENT_OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${SERVER_OBJDIR}/%.o: ${SERVER_SRCDIR}/%.c | ${SERVER_OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${CLIENT_OBJDIR}/%.o: ${B_CLIENT_SRCDIR}/%.c | ${CLIENT_OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${CLIENT_OBJDIR}/%.o: ${B_UTF8_SRCDIR}/%.c | ${CLIENT_OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${SERVER_OBJDIR}/%.o: ${B_SERVER_SRCDIR}/%.c | ${SERVER_OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${SERVER_OBJDIR}/%.o: ${B_UTF8_SRCDIR}/%.c | ${SERVER_OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

bonus: ${NAME_1} ${NAME_2}

clean:
	@make -C ${LIBFT_DIR} clean
	${RM} ${CLIENT_OBJS} ${SERVER_OBJS} ${CLIENT_DEPS} ${SERVER_DEPS}

fclean: clean
	@make -C ${LIBFT_DIR} fclean
	${RM} -r ${NAME_1} ${NAME_2} ${CLIENT_OBJDIR} ${SERVER_OBJDIR}

re: fclean all

-include $(CLIENT_DEPS) $(SERVER_DEPS)

.PHONY: all bonus clean fclean re
