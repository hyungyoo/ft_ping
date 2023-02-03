########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized.
CC = gcc
# CXXFLAGS = -Wall -Werror -Wextra

# Makefile settings - Can be customized.
APPNAME = ft_ping
EXT = .c
SRCDIR = src
OBJDIR = obj

############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
# UNIX-based OS variables & settings
RM = rm

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(APPNAME)

# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) -f $(OBJ)

.PHONY: fclean
fclean: clean
	$(RM) -f $(APPNAME)


.PHONY: re
re: fclean all