NAME = ex02

OBJS_DIR = ./objs
SRCS_DIR = ./srcs

SRCS = $(shell find $(SRCS_DIR) -name *.cpp)
OBJS := $(patsubst $(SRCS_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(SRCS))
SHRUB_FILES = $(shell find . -type f -name *_shrubbery)
DEPS = $(OBJS:.o=.d)

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -std=c++98 -MMD -MP -pedantic
INCLUDES = -I ./includes

#--------------------------------------------------------------------------#

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	c++ $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(CPPFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS_DIR) $(SHRUB_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re