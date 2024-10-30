NAME = get_next_line

# Compilateur et flags
CC = cc
CFLAGS = #-Wall -Wextra -Werror

# Fichiers source
SRC =  main.c get_next_line.c get_next_line_utils.c

# Fichiers objets générés
OBJ = $(SRC:.c=.o)

# Règle par défaut (appelée lors de 'make' simple)
all: $(NAME)

# Règle pour générer l'exécutable final
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Compilation terminée ! Exécutable créé -> $(NAME)"

# Règle de compilation des fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)
	@echo "Fichiers objets supprimés."

# Nettoyage complet (objets + exécutable)
fclean: clean
	rm -f $(NAME)
	@echo "Exécutable supprimé."

# Recompilation complète
re: fclean all

# Indique que ces règles ne sont pas des fichiers réels
.PHONY: all clean fclean re
