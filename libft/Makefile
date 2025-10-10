# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 21:27:03 by stanaka2          #+#    #+#              #
#    Updated: 2025/09/08 18:29:06 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OS = ${shell uname -s}
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./includes

# libft
SRCDIR = srcs
SRCS = ${addprefix ${SRCDIR}/ctype/, \
			ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c \
			ft_iscntrl.c ft_isdigit.c ft_isgraph.c ft_islower.c \
			ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c \
			ft_isxdigit.c ft_tolower.c ft_toupper.c \
		}
SRCS += ${addprefix ${SRCDIR}/stdio/, \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_putchar_fd_bytes.c ft_putendl_fd_bytes.c ft_putnbr_fd_bytes.c ft_putstr_fd_bytes.c \
		}
SRCS += ${addprefix ${SRCDIR}/stdlib/, \
			ft_abs_uint.c ft_abs_ulong.c ft_atoi.c ft_calloc.c ft_itoa.c \
		}
SRCS += ${addprefix ${SRCDIR}/string/, \
			ft_bzero.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_split.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
			ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
			ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnlen.c ft_strnstr.c \
			ft_strrchr.c ft_strtrim.c ft_substr.c \
		}
SRCS += ${addprefix ${SRCDIR}/lst/, \
			ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
			ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
		}
SRCS += ${addprefix ${SRCDIR}/math/, \
			ft_fabs.c ft_round.c ft_sqrt.c ft_square.c \
		}

# get_next_line
GNL_SRCDIR = get_next_line
SRCS += ${addprefix ${GNL_SRCDIR}/, get_next_line.c get_next_line_utils.c }

# dprintf / printf function
FPRINTF_SRCDIR = dprintf
ifeq ($(OS), Darwin)
	SRCS += ${addprefix ${FPRINTF_SRCDIR}/, ft_dprintf_darwin.c ft_printf_darwin.c }
else
	SRCS += ${addprefix ${FPRINTF_SRCDIR}/, ft_dprintf.c ft_printf.c }
endif
SRCS += ${addprefix ${FPRINTF_SRCDIR}/, ft_dprintf_utils.c }
# dprintf/srcs/read_conversion
ifeq ($(OS), Darwin)
	SRCS += ${addprefix ${FPRINTF_SRCDIR}/read_conversion/, ft_read_conversion_darwin.c }
else
	SRCS += ${addprefix ${FPRINTF_SRCDIR}/read_conversion/, ft_read_conversion.c }
endif
SRCS += ${addprefix ${FPRINTF_SRCDIR}/read_conversion/, ft_read_conversion_utils.c }
# dprintf/srcs//print_conversion
SRCS += ${addprefix ${FPRINTF_SRCDIR}/print_conversion/, \
			ft_conv_a.c \
			ft_conv_d_i.c \
			ft_conv_f_e_g.c \
			ft_conv_n.c \
			ft_conv_o.c \
			ft_conv_u.c \
			ft_conv_x.c \
			ft_print_conversion.c \
			ft_print_conversion_utils.c \
		}
ifeq ($(OS), Darwin)
	SRCS += ${addprefix ${FPRINTF_SRCDIR}/print_conversion/, \
				ft_conv_c_darwin.c \
				ft_conv_s_darwin.c \
				ft_conv_p_darwin.c \
				ft_conv_percent_darwin.c \
			}
else
	SRCS += ${addprefix ${FPRINTF_SRCDIR}/print_conversion/, \
				ft_conv_c.c \
				ft_conv_s.c \
				ft_conv_p.c \
				ft_conv_percent.c \
			}
endif
# dprintf/srcs/print_conversion/binary64
SRCS += ${addprefix ${FPRINTF_SRCDIR}/print_conversion/binary64/, \
			ft_conv_e_binary64.c \
			ft_conv_f_binary64.c \
			ft_conv_g_binary64.c \
			ft_convert_to_decimal_binary64.c \
			ft_convert_to_hex_binary64.c \
			ft_decode_binary64.c \
			ft_decode_hex_binary64.c  \
			ft_get_decimal_exponent_binary64.c \
			ft_my_double_utils_binary64.c \
			ft_print_g_exp_notation_binary64.c \
			ft_print_g_fixed_point_binary64.c \
			ft_round_binary64.c \
			ft_round_exp_notation_binary64.c \
			ft_round_hex_binary64.c \
		}
ifeq ($(OS), Darwin)
	SRCS += ${addprefix ${FPRINTF_SRCDIR}/print_conversion/binary64/, \
				ft_conv_a_binary64_darwin.c \
				ft_print_nan_inf_binary64_darwin.c \
				ft_normalize_hex_binary64_darwin.c \
			}
else
	SRCS += ${addprefix ${FPRINTF_SRCDIR}/print_conversion/binary64/, \
				ft_conv_a_binary64.c \
				ft_print_nan_inf_binary64.c \
			}
endif
# dprintf/srcs/print_conversion/80bit
SRCS += ${addprefix ${FPRINTF_SRCDIR}/print_conversion/80bit/, \
			ft_conv_e_80bit.c \
			ft_conv_f_80bit.c \
			ft_conv_g_80bit.c \
			ft_convert_to_decimal_80bit.c \
			ft_decode_80bit.c \
			ft_get_decimal_exponent_80bit.c \
			ft_my_double_utils_80bit.c \
			ft_print_g_exp_notation_80bit.c \
			ft_print_g_fixed_point_80bit.c \
			ft_round_80bit.c \
			ft_round_exp_notation_80bit.c \
		}
ifeq ($(OS), Darwin)
	SRCS += ${addprefix ${FPRINTF_SRCDIR}/print_conversion/80bit/, ft_print_nan_inf_80bit_darwin.c }
else
	SRCS += ${addprefix ${FPRINTF_SRCDIR}/print_conversion/80bit/, ft_print_nan_inf_80bit.c }
endif
# dprintf/srcs/print_conversion/float_common_utils
SRCS += ${addprefix ${FPRINTF_SRCDIR}/print_conversion/float_common_utils/, \
			ft_array_calc.c \
			ft_print_exponent.c \
		}
# dprintf/srcs/print_conversion/wchar_to_utf8
ifeq ($(OS), Darwin)
	SRCS += ${addprefix ${FPRINTF_SRCDIR}/print_conversion/wchar_to_utf8/, \
				ft_conv_lc_darwin.c \
				ft_conv_ls_darwin.c \
			}
else
	SRCS += ${addprefix ${FPRINTF_SRCDIR}/print_conversion/wchar_to_utf8/, \
				ft_conv_lc.c \
				ft_conv_ls.c \
			}
endif
SRCS += ${addprefix ${FPRINTF_SRCDIR}/print_conversion/wchar_to_utf8/, ft_utf8_utils.c }

OBJDIR = objs
OBJS = ${addprefix ${OBJDIR}/, ${notdir ${SRCS:.c=.o}}}

DEPSFLAGS	= -MMD
DEPS	= ${addprefix ${OBJDIR}/, ${notdir ${SRCS:.c=.d}}}

all: ${NAME}

${NAME} : ${OBJS}
	${AR} rcs $@ $?

${OBJDIR}:
	-mkdir -p ${OBJDIR}

# libft
${OBJDIR}/%.o: ${SRCDIR}/ctype/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/stdio/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/stdio/printf/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/stdlib/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/string/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/lst/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/math/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

# get_next_line
${OBJDIR}/%.o: ${GNL_SRCDIR}/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

# dprintf / printf function
${OBJDIR}/%.o: ${FPRINTF_SRCDIR}/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${FPRINTF_SRCDIR}/read_conversion/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${FPRINTF_SRCDIR}/print_conversion/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${FPRINTF_SRCDIR}/print_conversion/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${FPRINTF_SRCDIR}/print_conversion/binary64/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${FPRINTF_SRCDIR}/print_conversion/80bit/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${FPRINTF_SRCDIR}/print_conversion/float_common_utils/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${FPRINTF_SRCDIR}/print_conversion/wchar_to_utf8/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

clean:
	${RM} ${OBJS} ${DEPS}

fclean: clean
	${RM} -r $(NAME) ${OBJDIR}

re: fclean all

-include $(DEPS)

.PHONY: all bonus clean fclean re
