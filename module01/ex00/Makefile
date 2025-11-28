NAME = ex00

SRC_FILES = main\
			Zombie\
			newZombie\
			randomChump\

OBJS_DIR = ./objs
SRCS_DIR = ./srcs

SRCS = $(foreach src,$(SRC_FILES), $(SRCS_DIR)/$(src).cpp)
OBJS = $(addprefix $(OBJS_DIR)/, $(SRC_FILES:=.o))
DEPS = $(OBJS:.o=.d)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -fsanitize=address -g3
CPPFLAGS = -MMD -MP -I ./includes
LDFLAGS = -fsanitize=address -g3

#--------------------------------------------------------------------------#

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
