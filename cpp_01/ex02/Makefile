NAME = ex02

SRC_FILES = main

OBJS_DIR = ./objs
SRCS_DIR = ./srcs

SRCS = $(foreach src,$(SRC_FILES), $(SRCS_DIR)/$(src).cpp)
OBJS = $(addprefix $(OBJS_DIR)/, $(SRC_FILES:=.o))
DEPS = $(OBJS:.o=.d)

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -std=c++98  -MMD -MP

#--------------------------------------------------------------------------#

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	c++ $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(CPPFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	rm -rf $(OBJS_DIR)
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re