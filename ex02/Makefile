# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 09:31:18 by rmarquar          #+#    #+#              #
#    Updated: 2024/04/17 16:21:27 by rmarquar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name	:= program
CXX		:= c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98
SRC		:= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJDIR	:= obj
OBJS	:= $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(Name): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(Name)

# Colors
YELLOW := "\033[0;33m"
CYAN := "\033[0;36m"
BLUE := "\033[0;34m"
GREEN := "\033[0;32m"
RED := "\033[0;31m"
RESET := "\033[0m"

all: $(Name)
	@echo -e $(GREEN) "Compilation of $(Name) is finished and ready" $(RESET)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(Name)
	@clear
	@echo -e $(YELLOW) "Executable $(Name) and all object files have been successfully removed" $(RESET)

re: fclean all

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: all clean fclean re
