*Ce projet a été réalisé dans le cadre du cursus 42 par crgrandj.*

# Version Francaise
English version below &darr;

# Libft

## Description
Libft est une bibliothèque personnalisée en C qui réimplémente des fonctions utiles de la bibliothèque standard du C et ajoute des fonctions pratiques pour les futurs projets de 42. L’objectif est de mieux comprendre la programmation bas niveau en C, la manipulation des chaînes de caractères et de la mémoire, l’allocation dynamique ainsi que les listes chaînées, en développant ces outils soi-même.

La bibliothèque est organisée en trois groupes de fonctions :

- **Réimplémentations de fonctions libc :** tests et conversions de caractères, opérations sur la mémoire, manipulation de chaînes et conversion numérique (par exemple, `ft_strlen`, `ft_memcpy`, `ft_strlcpy`, `ft_atoi` et `ft_calloc`).
- **Fonctions utilitaires supplémentaires :** création de sous-chaînes, concaténation et suppression de caractères en début/fin de chaîne, découpage de chaînes, conversion d’entiers en chaînes, application de fonctions aux caractères et écriture de caractères, chaînes ou nombres vers un descripteur de fichier.
- **Listes chaînées :** la structure `t_list` et les fonctions permettant de créer, ajouter, compter, parcourir, supprimer, vider et transformer les nœuds d’une liste.

Le résultat est une bibliothèque statique réutilisable appelée `libft.a`, destinée à être intégrée aux futurs projets en C.

## Instructions
Depuis la racine du dépôt, compilez la bibliothèque avec :

```sh
make
```

Le Makefile doit compiler les fichiers sources avec les options `-Wall -Wextra -Werror` et créer `libft.a` à l’aide de `ar`. Les commandes de maintenance courantes sont :

```sh
make clean   # supprime les fichiers objets
make fclean  # supprime les fichiers objets et libft.a
make re      # nettoie puis recompile la bibliothèque
```

Pour utiliser la bibliothèque dans un autre programme C, incluez `libft.h` et liez `libft.a` lors de la compilation. Par exemple :

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

Les fichiers `libft.h`, les fichiers sources des fonctions et le Makefile doivent se trouver à la racine du dépôt, conformément au sujet. Consultez les prototypes disponibles dans `libft.h` avant d’utiliser une fonction.

## Ressources
- Les pages de manuel (`man`) des fonctions standard correspondantes, par exemple `man strlen`, `man memcpy` et `man atoi`.
- La documentation du langage C et de sa bibliothèque standard, notamment sur la gestion de la mémoire, les chaînes de caractères et les caractères.
- Le sujet du projet Libft de 42, qui définit les fonctions demandées, leur comportement, les exigences de compilation et l’API des listes chaînées.

**Utilisation de l’IA :** L'IA a ete utilisee pour le README.md et pour quelque test main a travers le projet!

## Remarques
Ce README présente les exigences du projet et le contenu prévu de la bibliothèque. Vérifiez que les fonctions mentionnées correspondent bien à l’implémentation de ce dépôt et ajoutez les détails ou tests spécifiques réellement effectués.

<br>

##

<br>
<br>

*This project has been created as part of the 42 curriculum by crgrandj.*

# English version

# Libft

## Description
Libft is a custom C library that recreates useful functions from the C standard library and adds utility functions for future 42 projects. The goal is to understand low-level C programming, string and memory manipulation, dynamic allocation, and linked-list data structures by implementing these tools from scratch.

The library is organized around three groups of functions:

- **Libc reimplementations:** character checks and conversions, memory operations, string handling, and numeric conversion (for example, `ft_strlen`, `ft_memcpy`, `ft_strlcpy`, `ft_atoi`, and `ft_calloc`).
- **Additional utilities:** functions for creating substrings, joining and trimming strings, splitting strings, converting integers to strings, applying functions to characters, and writing characters, strings, or numbers to a file descriptor.
- **Linked lists:** the `t_list` structure and functions to create, add, count, access, delete, clear, iterate over, and map list nodes.

The result is a reusable static library named `libft.a`, intended to be included in later C projects.

## Instructions
Build the library from the root of the repository with:

```sh
make
```

The Makefile should compile the source files with `-Wall -Wextra -Werror` and create `libft.a` using `ar`. Common maintenance targets are:

```sh
make clean   # remove object files
make fclean  # remove object files and libft.a
make re      # clean and rebuild the library
```

To use the library in another C program, include `libft.h` and link `libft.a` when compiling. For example:

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

Make sure `libft.h`, the function source files, and the Makefile are in the repository root, as required by the project subject. Check the available function prototypes in `libft.h` before using a function.

## Resources
- The `man` pages for the corresponding standard functions (for example, `man strlen`, `man memcpy`, and `man atoi`).
- The C language and standard-library documentation for memory management, strings, and character handling.
- The 42 Libft project subject, which defines the required functions, behavior, build requirements, and linked-list API.

**AI usage:** AI was used for the README.md and for some of the test main across the project !

## Notes
This README describes the project requirements and intended library contents. Confirm that the functions listed above match the implementation in this repository, and add any project-specific details or tests that were actually completed.
