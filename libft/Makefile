# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 21:27:03 by stanaka2          #+#    #+#              #
#    Updated: 2025/11/21 20:14:56 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------- #
#       Phony Targets        #
# -------------------------- #

.PHONY: all clean fclean re asan debug

# -------------------------- #
#      Makefile Setting      #
# -------------------------- #

OS		=	$(shell uname -s)

SHELL	=	/bin/bash

MAKEFLAGS += --no-print-directory

RM = rm -f

# -------------------------- #
# 　　    　 Target           #
# -------------------------- #

NAME =	libft.a

# -------------------------- #
# 　　　Compiler Flags        #
# -------------------------- #

CFLAGS  =	-Wall -Wextra -Werror

ifeq ($(MAKECMDGOALS), asan)
CFLAGS +=	-g -fsanitize=address
endif

ifeq ($(MAKECMDGOALS), debug)
CFLAGS +=	-g
endif

# -------------------------- #
#          Include           #
# -------------------------- #

INCLUDE_DIR	=	./include
INCLUDE  	=	-I $(INCLUDE_DIR)

# -------------------------- #
#     Source Directories     #
# -------------------------- #

SRC_DIR  =	src
SRC_DIRS =	$(addprefix $(SRC_DIR)/, ctype stdio stdlib string lst math)
SRC_DIRS +=	get_next_line
SRC_DIRS +=	printf \
			$(addprefix printf/, \
				read_conversion \
				print_conversion \
				print_conversion/binary64 \
				print_conversion/80bit \
				print_conversion/float_common_utils \
				print_conversion/wchar_to_utf8 \
			)

# -------------------------- #
#        Source Files        #
# -------------------------- #

# ctype
SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c \
	   ft_iscntrl.c ft_isdigit.c ft_isgraph.c ft_islower.c \
	   ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c \
	   ft_isxdigit.c ft_tolower.c ft_toupper.c

# stdio
SRCS += ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_putchar_fd_bytes.c ft_putendl_fd_bytes.c ft_putnbr_fd_bytes.c ft_putstr_fd_bytes.c

# stdlib
SRCS += ft_abs_uint.c ft_abs_ulong.c ft_atoi.c ft_calloc.c ft_itoa.c 

# string
SRCS += ft_bzero.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_split.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnlen.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_split_set.c

# lst
SRCS += ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

# math
SRCS += ft_fabs.c ft_round.c ft_sqrt.c

# get_next_line
SRCS += get_next_line.c get_next_line_utils.c

# printf
ifeq ($(OS), Darwin)
SRCS += ft_dprintf_darwin.c ft_printf_darwin.c ft_snprintf_darwin.c \
		ft_sprintf_darwin.c ft_xprint_format_darwin.c
else
SRCS += ft_dprintf.c ft_printf.c ft_snprintf.c ft_sprintf.c ft_xprint_format.c
endif
SRCS += ft_xprintf_utils.c

# printf/read_conversion
ifeq ($(OS), Darwin)
SRCS += ft_read_conversion_darwin.c
else
SRCS += ft_read_conversion.c
endif
SRCS += ft_read_conversion_utils.c

# printf/print_conversion
SRCS += ft_conv_a.c ft_conv_d_i.c ft_conv_f_e_g.c ft_conv_n.c ft_conv_o.c ft_conv_u.c \
		ft_conv_x.c ft_print_conversion.c ft_print_conversion_utils.c
ifeq ($(OS), Darwin)
SRCS += ft_conv_c_darwin.c ft_conv_s_darwin.c ft_conv_p_darwin.c ft_conv_percent_darwin.c
else
SRCS += ft_conv_c.c ft_conv_s.c ft_conv_p.c ft_conv_percent.c
endif

# printf/print_conversion/binary64
SRCS += ft_conv_e_binary64.c ft_conv_f_binary64.c ft_conv_g_binary64.c \
		ft_convert_to_decimal_binary64.c ft_convert_to_hex_binary64.c \
		ft_decode_binary64.c ft_decode_hex_binary64.c \
		ft_get_decimal_exponent_binary64.c ft_my_double_utils_binary64.c \
		ft_print_g_exp_notation_binary64.c ft_print_g_fixed_point_binary64.c \
		ft_round_binary64.c ft_round_exp_notation_binary64.c ft_round_hex_binary64.c
ifeq ($(OS), Darwin)
SRCS += ft_conv_a_binary64_darwin.c ft_print_nan_inf_binary64_darwin.c ft_normalize_hex_binary64_darwin.c
else
SRCS += ft_conv_a_binary64.c ft_print_nan_inf_binary64.c
endif

# printf/print_conversion/80bit
SRCS += ft_conv_e_80bit.c ft_conv_f_80bit.c ft_conv_g_80bit.c \
		ft_convert_to_decimal_80bit.c ft_decode_80bit.c \
		ft_get_decimal_exponent_80bit.c ft_my_double_utils_80bit.c \
		ft_print_g_exp_notation_80bit.c ft_print_g_fixed_point_80bit.c \
		ft_round_80bit.c ft_round_exp_notation_80bit.c
ifeq ($(OS), Darwin)
SRCS += ft_print_nan_inf_80bit_darwin.c
else
SRCS += ft_print_nan_inf_80bit.c
endif

# printf/print_conversion/float_common_utils
SRCS += ft_array_calc.c ft_print_exponent.c

# printf/print_conversion/wchar_to_utf8
ifeq ($(OS), Darwin)
SRCS += ft_conv_lc_darwin.c ft_conv_ls_darwin.c
else
SRCS += ft_conv_lc.c ft_conv_ls.c
endif
SRCS += ft_utf8_utils.c

# -------------------------- #
#    ANSI Escape Sequence    #
# -------------------------- #

DEF_COLOR	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA 	= \033[0;95m
CYAN 		= \033[0;96m
WHITE 		= \033[0;97m

# -------------------------- #
#        VPATH Setup         #
# -------------------------- #

$(foreach dir,$(SRC_DIRS), $(eval vpath %.c $(dir)))

# -------------------------- #
#     Object & Dependency    #
# -------------------------- #

OBJ_DIR	=	.obj
OBJS	=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))

DEP_DIR		=	.dep
DEPFLAGS	=	-MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
DEPS		=	$(patsubst %.c, $(DEP_DIR)/%.d, $(notdir $(SRCS)))

# -------------------------- #
#         Main Targets       #
# -------------------------- #

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) rcs $@ $?
	@echo -e "[LIBFT] $(GREEN)Build Complete:$(DEF_COLOR) $@"

# -------------------------- #
#         Debug Rules        #
# -------------------------- #

asan: $(NAME)
debug:  $(NAME)

# -------------------------- #
#        Build Rules         #
# -------------------------- #

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) $(DEPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@-mkdir -p $@

$(DEP_DIR):
	@-mkdir -p $@

# -------------------------- #
#       Cleanup Rules        #
# -------------------------- #

clean:
	@$(RM) $(OBJS) $(DEPS)
	@echo -e "[LIBFT] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"

fclean:
	@$(RM) $(OBJS) $(DEPS)
	@echo -e "[LIBFT] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"
	@$(RM) -r $(NAME) $(OBJ_DIR) $(DEP_DIR)
	@echo -e "[LIBFT] $(BLUE)Deleted Target File and Object File Dir$(DEF_COLOR): $(NAME) $(OBJ_DIR) $(DEP_DIR)"

re: fclean all

# -------------------------- #
#  Include Dependency Files  #
# -------------------------- #

-include $(DEPS)
