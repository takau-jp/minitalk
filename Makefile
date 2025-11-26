# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 19:52:15 by stanaka2          #+#    #+#              #
#    Updated: 2025/11/21 19:52:57 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------- #
#        Phony Rules         #
# -------------------------- #

.PHONY: all bonus asan debug clean fclean re

# -------------------------- #
#      Makefile Setting      #
# -------------------------- #

SHELL =	/bin/bash

ifeq ($(filter re,$(MAKECMDGOALS)),re)
MAKEFLAGS += --no-print-directory
else
MAKEFLAGS += --no-print-directory -j
endif

RM = rm -f

# -------------------------- #
# 　　　　　　Target　　　      #
# -------------------------- #

NAME = minitalk
NAME_1 = client
NAME_2 = server

# -------------------------- #
# 　　     　LIBFT            #
# -------------------------- #

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE_DIR = $(LIBFT_DIR)/include

# -------------------------- #
# 　　　Compiler Flags        #
# -------------------------- #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

ifeq ($(filter asan,$(MAKECMDGOALS)),asan)
CFLAGS += -g -fsanitize=address
else ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
CFLAGS += -g
endif

# -------------------------- #
#          Include           #
# -------------------------- #

INCLUDE_DIR = include
INCLUDE		= -I $(INCLUDE_DIR) -I $(LIBFT_INCLUDE_DIR)

# -------------------------- #
#     Source Directories     #
# -------------------------- #

SRCDIRS = $(addprefix mandatory/, client server common)
SRCDIRS += $(addprefix bonus/, client server common utf8)

# -------------------------- #
#        Source Files        #
# -------------------------- #

# mandatory
CLIENT_SRCS =	client.c check_pid.c errors.c
SERVER_SRCS =	server.c print_server_pid.c receive_bit.c process_byte.c
COMMON_SRCS =	set_signal_handler.c
CLIENT_SRCS += $(COMMON_SRCS)
SERVER_SRCS += $(COMMON_SRCS)

# bonus
B_CLIENT_SRCS =	client_bonus.c check_pid_bonus.c errors_bonus.c utf8_validation_bonus.c
B_SERVER_SRCS =	server_bonus.c print_server_pid_bonus.c receive_bit_bonus.c process_byte_bonus.c
B_COMMON_SRCS =	set_signal_handler_bonus.c
B_UTF8_SRCS +=	append_utf8_byte_sequence_bonus.c \
				utf8_byte_validation_bonus.c utf8_codepoint_validation_bonus.c \
				utf8_utils_bonus.c validate_utf8_byte_sequence_bonus.c
B_CLIENT_SRCS += $(B_COMMON_SRCS) $(B_UTF8_SRCS)
B_SERVER_SRCS += $(B_COMMON_SRCS) $(B_UTF8_SRCS)

# -------------------------- #
#        VPATH Setup         #
# -------------------------- #

$(foreach dir,$(SRCDIRS), $(eval vpath %.c $(dir)))

# -------------------------- #
#     Object & Dependency    #
# -------------------------- #

OBJ_DIR		=	.obj
# mandatory
CLIENT_OBJS	:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(CLIENT_SRCS)))
SERVER_OBJS	:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SERVER_SRCS)))
# bonus
B_CLIENT_OBJS	:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(B_CLIENT_SRCS)))
B_SERVER_OBJS   := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(B_SERVER_SRCS)))

DEP_DIR		=	.dep
DEPFLAGS	=	-MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
# mandatory
CLIENT_DEPS		:= $(patsubst %.c, $(DEP_DIR)/%.d, $(notdir $(CLIENT_SRCS)))
SERVER_DEPS		:= $(patsubst %.c, $(DEP_DIR)/%.d, $(notdir $(SERVER_SRCS)))
# bonus
B_CLIENT_DEPS	:= $(patsubst %.c, $(DEP_DIR)/%.d, $(notdir $(B_CLIENT_SRCS)))
B_SERVER_DEPS	:= $(patsubst %.c, $(DEP_DIR)/%.d, $(notdir $(B_SERVER_SRCS)))

# -------------------------- #
#       Bonus Switching      #
# -------------------------- #

ifeq ($(filter bonus,$(MAKECMDGOALS)),bonus)
CLIENT_OBJS = $(B_CLIENT_OBJS)
SERVER_OBJS = $(B_SERVER_OBJS)
CLIENT_DEPS	= $(B_CLIENT_DEPS)
SERVER_DEPS	= $(B_SERVER_DEPS)
endif

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
#        Main Targets        #
# -------------------------- #

all:	$(NAME_1) $(NAME_2)

bonus:	$(NAME_1) $(NAME_2)

$(NAME): $(NAME_1) $(NAME_2)

$(NAME_1): $(CLIENT_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@  
	@echo -e "[MINITALK] $(GREEN)Build Complete:$(DEF_COLOR) $@"

$(NAME_2): $(SERVER_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@  
	@echo -e "[MINITALK] $(GREEN)Build Complete:$(DEF_COLOR) $@"

# -------------------------- #
#        Build Rules         #
# -------------------------- #

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@-mkdir -p $@

$(DEP_DIR):
	@-mkdir -p $@

# -------------------------- #
#         LIBFT Rule         #
# -------------------------- #

$(LIBFT):
	@echo -e "[MINITALK] $(YELLOW)Build:$(DEF_COLOR) $@"
ifeq ($(filter asan,$(MAKECMDGOALS)),asan)
	@$(MAKE) -C $(LIBFT_DIR) asan
else ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
	@$(MAKE) -C $(LIBFT_DIR) debug
else
	@$(MAKE) -C $(LIBFT_DIR)
endif

# -------------------------- #
#         Debug Rules        #
# -------------------------- #

asan:	$(NAME)

debug:  $(NAME)

sbuild:
	@$(MAKE) fclean
	/usr/lib/llvm-12/bin/scan-build make
	@$(MAKE) fclean
	/usr/lib/llvm-12/bin/scan-build make bonus
	@$(MAKE) fclean

norm:
	@norminette -o mandatory bonus $(LIBFT_DIR) $(INCLUDE_DIR) | grep Error || true

# -------------------------- #
#       Cleanup Rules        #
# -------------------------- #

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_DEPS) $(SERVER_DEPS) $(B_CLIENT_OBJS) $(B_SERVER_OBJS) $(B_CLIENT_DEPS) $(B_SERVER_DEPS)
	@echo -e "[MINITALK] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"

fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_DEPS) $(SERVER_DEPS) $(B_CLIENT_OBJS) $(B_SERVER_OBJS) $(B_CLIENT_DEPS) $(B_SERVER_DEPS)
	@echo -e "[MINITALK] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"
	@$(RM) -r $(NAME_1) $(NAME_2) $(OBJ_DIR) $(DEP_DIR)
	@echo -e "[MINITALK] $(BLUE)Deleted Target File and Object File Dir$(DEF_COLOR): $(NAME_1) $(NAME_2) $(OBJ_DIR) $(DEP_DIR)"

re:	fclean all

# -------------------------- #
#  Include Dependency Files  #
# -------------------------- #

-include $(CLIENT_DEPS) $(SERVER_DEPS)
