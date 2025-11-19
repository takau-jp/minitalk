# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 19:52:15 by stanaka2          #+#    #+#              #
#    Updated: 2025/11/19 21:18:08 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------- #
#      Makefile Setting      #
# -------------------------- #

MAKEFLAGS += --no-print-directory

# -------------------------- #
# 　　　　　　Target　　　      #
# -------------------------- #
NAME = minitalk
NAME_1 = client
NAME_2 = server

# -------------------------- #
# 　　　Compiler Flags        #
# -------------------------- #
CFLAGS  = -Wall -Wextra -Werror

ifeq ($(filter asan,$(MAKECMDGOALS)),asan)
CFLAGS += -g -fsanitize=address
else ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
CFLAGS += -g
endif

# -------------------------- #
# 　　     　LIBFT            #
# -------------------------- #
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
LIBFT_INCLUDE = -I ${LIBFT_DIR}/include

# -------------------------- #
#    Dependency & Include    #
# -------------------------- #
DEPFLAGS = -MMD
INCLUDE = -I include ${LIBFT_INCLUDE}

# -------------------------- #
#     Source Directories     #
# -------------------------- #
SRCDIRS = mandatory/client mandatory/server
SRCDIRS += bonus/client bonus/server bonus/utf8

# -------------------------- #
#        Source Files        #
# -------------------------- #

# mandatory
CLIENT_SRCS =	client.c check_pid.c errors.c
SERVER_SRCS =	server.c print_server_pid.c receive_bit.c process_byte.c

# bonus
B_CLIENT_SRCS =	client_bonus.c check_pid_bonus.c errors_bonus.c utf8_validation_bonus.c
B_SERVER_SRCS =	server_bonus.c print_server_pid_bonus.c receive_bit_bonus.c process_byte_bonus.c
B_UTF8_SRCS +=	append_utf8_byte_sequence_bonus.c \
				utf8_byte_validation_bonus.c utf8_codepoint_validation_bonus.c \
				utf8_utils_bonus.c validate_utf8_byte_sequence_bonus.c
B_CLIENT_SRCS += $(B_UTF8_SRCS)
B_SERVER_SRCS += $(B_UTF8_SRCS)

# -------------------------- #
#    ANSI Escape Sequence    #
# -------------------------- #
GREEN  = \033[0;32m
BLUE   = \033[0;34m
RED    = \033[0;31m
YELLOW = \033[0;33m
NC     = \033[0m
MOVE_LINE_TOP = \033[1G
MOVE_ABOVE_LINE_TOP = \033[1F
CLEAR_LINE = \033[2K

# -------------------------- #
#        VPATH Setup         #
# -------------------------- #
$(foreach dir,$(SRCDIRS), $(eval vpath %.c $(dir)))

# -------------------------- #
#  Object & Dependency Setup #
# -------------------------- #
OBJDIR = objs
# mandatory
CLIENT_OBJS   := $(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(CLIENT_SRCS)))
SERVER_OBJS   := $(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SERVER_SRCS)))
CLIENT_DEPS := $(patsubst %.c, $(OBJDIR)/%.d, $(notdir $(CLIENT_SRCS)))
SERVER_DEPS := $(patsubst %.c, $(OBJDIR)/%.d, $(notdir $(SERVER_SRCS)))
# bonus
B_CLIENT_OBJS   := $(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(B_CLIENT_SRCS)))
B_SERVER_OBJS   := $(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(B_SERVER_SRCS)))
B_CLIENT_DEPS := $(patsubst %.c, $(OBJDIR)/%.d, $(notdir $(B_CLIENT_SRCS)))
B_SERVER_EPS := $(patsubst %.c, $(OBJDIR)/%.d, $(notdir $(B_SERVER_SRCS)))

# -------------------------- #
#       Bonus Switching      #
# -------------------------- #
ifeq ($(filter bonus,$(MAKECMDGOALS)),bonus)
CLIENT_OBJS = ${B_CLIENT_OBJS}
SERVER_OBJS = ${B_SERVER_OBJS}
CLIENT_DEPS	= ${B_CLIENT_DEPS}
SERVER_DEPS	= ${B_SERVER_DEPS}
endif

# -------------------------- #
#        Main Targets        #
# -------------------------- #
all: $(NAME)

$(NAME): ${NAME_1} ${NAME_2}

${NAME_1}: ${CLIENT_OBJS} ${LIBFT}
	@${CC} $(CFLAGS) $^ -o $@  
	@echo "[MINITALK] $(GREEN)Build Complete:$(NC) $@"

${NAME_2}: ${SERVER_OBJS} ${LIBFT}
	@${CC} $(CFLAGS) $^ -o $@  
	@echo "[MINITALK] $(GREEN)Build Complete:$(NC) $@"

# -------------------------- #
#         LIBFT Rule         #
# -------------------------- #
${LIBFT}:
	@echo "[MINITALK] $(YELLOW)Build:$(NC) $@"
ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
	@$(MAKE) -C $(LIBFT_DIR) debug
else ifeq ($(filter asan,$(MAKECMDGOALS)),asan)
	@$(MAKE) -C $(LIBFT_DIR) asan
else
	@$(MAKE) -C $(LIBFT_DIR)
endif

# -------------------------- #
#         Bonus Rules        #
# -------------------------- #

bonus: $(NAME)

# -------------------------- #
#         Debug Rules        #
# -------------------------- #

asan: $(NAME)
debug:  $(NAME)

# -------------------------- #
#        Build Rules         #
# -------------------------- #
$(OBJDIR):
	@-mkdir -p $@

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) -c $< -o $@

# -------------------------- #
#       Cleanup Rules        #
# -------------------------- #
clean:
	@make -C ${LIBFT_DIR} clean
	@${RM} ${CLIENT_OBJS} ${SERVER_OBJS} ${CLIENT_DEPS} ${SERVER_DEPS}
	@echo "[MINITALK] $(BLUE)Deleted Compiled Files$(NC): *.o *.d"

fclean:
	@make -C ${LIBFT_DIR} fclean
	@${RM} ${CLIENT_OBJS} ${SERVER_OBJS} ${CLIENT_DEPS} ${SERVER_DEPS}
	@echo "[MINITALK] $(BLUE)Deleted Compiled Files$(NC): *.o *.d"
	@${RM} -r ${NAME_1} ${NAME_2} ${OBJDIR}
	@echo "[MINITALK] $(BLUE)Deleted Target File and Object File Dir$(NC): ${NAME_1} ${NAME_2} $(OBJDIR)"

re: fclean all

# -------------------------- #
#  Include Dependency Files  #
# -------------------------- #
-include $(CLIENT_DEPS) $(SERVER_DEPS)

# -------------------------- #
#       Phony Targets        #
# -------------------------- #
.PHONY: all asan debug clean fclean re

