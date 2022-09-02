# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 18:34:29 by mbourgeo          #+#    #+#              #
#    Updated: 2022/09/02 03:52:56 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

MAND_SRCS	=	main.c initialize.c utils.c eating.c monitoring.c \
				time.c memory.c parsing.c actions.c
MAND_SRCDIR	=	mandatory/src
MAND_PATH	=	$(addprefix $(MAND_SRCDIR)/, $(MAND_SRCS))
MAND_OBJDIR	=	mandatory/obj
MAND_OBJS	=	$(patsubst $(MAND_SRCDIR)/%, $(MAND_OBJDIR)/%, $(MAND_PATH:.c=.o))

BONUS_SRCS	=
BONUS_SRCDIR	=	bonus/src
BONUS_PATH	=	$(addprefix $(BONUS_SRCDIR)/, $(BONUS_SRCS))
BONUS_OBJDIR	=	bonus/obj
BONUS_OBJS	=	$(patsubst $(BONUS_SRCDIR)/%, $(BONUS_OBJDIR)/%, $(BONUS_PATH:.c=.o))

MD_DEP_DIR	=	mandatory/dep
MAND_DEP	=	$(patsubst $(MAND_OBJDIR)/%.o, $(MD_DEP_DIR)/%.d, $(MAND_OBJS))
BN_DEP_DIR	=	bonus/dep
BONUS_DEP	=	$(patsubst $(BONUS_OBJDIR)/%.o, $(BN_DEP_DIR)/%.d, $(BONUS_OBJS))

#MD_HD_SRCS	=	philo.h
MD_HD_DIR	=	mandatory/inc
MD_HD_PATH	=	$(addprefix $(MD_HD_DIR)/, $(MD_HD_SRCS))
#BN_HD_SRCS	=	philo_bonus.h
BN_HD_DIR	=	bonus/inc
BN_HD_PATH	=	$(addprefix $(BN_HD_DIR)/, $(BN_HD_SRCS))

NAME		=	philo
NAME_BONUS	=	philo_bonus
CC			=	gcc
RM			=	rm -rvf
MK			=	mkdir -p
#DEBUG		=	-g -fsanitize=address
#DEBUG		=	-g -fsanitize=thread
DEBUG		=	-g
CFLAGS		=	-Wall -Wextra -Werror
LFLAGS		=	-lpthread
DFLAGS		=	-MMD -MF

#################################

all:		$(NAME)

$(NAME):	$(MAND_OBJS)
				$(CC) $(CFLAGS) $(DEBUG) $^ -I$(MD_HD_DIR) $(LFLAGS) -o $@

bonus:		$(BONUS_OBJS)
				$(CC) $(CFLAGS) $(DEBUG) $^ -I$(BN_HD_DIR) $(LFLAGS) -o $(NAME_BONUS)

-include $(MAND_DEP)
$(MAND_OBJDIR)/%.o:		$(MAND_SRCDIR)/%.c | $(MAND_OBJDIR) $(MD_DEP_DIR) $(MD_HD_PATH)
							$(CC) $(CFLAGS) $(DEBUG) $(DFLAGS) $(MD_DEP_DIR)/$*.d -I$(MD_HD_DIR) $(LFLAGS) -c $< -o $@

$(MAND_OBJDIR) $(MD_DEP_DIR):		;
				@$(MK) $@

-include $(BONUS_DEP)
$(BONUS_OBJDIR)/%.o:		$(BONUS_SRCDIR)/%.c | $(BONUS_OBJDIR) $(BN_DEP_DIR) $(MD_HD_PATH)
							$(CC) $(CFLAGS) $(DEBUG) $(DFLAGS) $(BN_DEP_DIR)/$*.d -I$(BN_HD_DIR) $(LFLAGS) -c $< -o $@

$(BONUS_OBJDIR) $(BN_DEP_DIR):		;
				@$(MK) $@

clean:		;
				@$(RM) $(MAND_OBJDIR) $(MD_DEP_DIR)
				@$(RM) $(BONUS_OBJDIR) $(BN_DEP_DIR)

fclean:		clean
				@$(RM) $(NAME)
				@$(RM) $(NAME_BONUS)

re:			fclean all

.PHONY:		all clean fclean re
