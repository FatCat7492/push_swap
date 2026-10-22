*Ce projet a été réalisé dans le cadre du cursus 42 par crgrandj.*

# Version française

## Description

`ft_printf` est un projet du cursus 42 dont l’objectif est de recréer la fonction standard `printf()` de la bibliothèque C. Il permet de mieux comprendre les fonctions variadiques, la gestion des arguments de types différents et la conversion de valeurs en texte.

La bibliothèque produite, `libftprintf.a`, contient la fonction `ft_printf()` et ses fonctions auxiliaires. La partie obligatoire prend en charge les conversions `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` et `%%`. La gestion du tampon interne de la fonction originale `printf()` n’est pas demandée. Le projet privilégie une organisation claire, des fonctions réutilisables et une gestion correcte des erreurs et de la mémoire.

## Instructions

### Compilation

À la racine du dépôt, lancez :

```sh
make
```

Le Makefile compile les fichiers sources et crée la bibliothèque statique `libftprintf.a`. Il utilise les options `-Wall -Wextra -Werror` afin de signaler les avertissements comme des erreurs. Le projet utilise `libft`, le Makefile de cette bibliothèque est exécuté avant la création de la bibliothèque finale.

Commandes disponibles :

```sh
make        # Compile le projet
make clean  # Supprime les fichiers objets
make fclean # Supprime les fichiers objets et la bibliothèque
make re     # Recompile entièrement le projet
```

### Utilisation

Pour utiliser la bibliothèque dans un programme C, incluez `ft_printf.h` et liez `libftprintf.a` à la compilation. Par exemple :

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Nombre : %d, texte : %s\\n", 42, "bonjour");
    return (0);
}
```

Compilez le programme de test depuis la racine du dépôt :

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf && ./a.out
```

La bibliothèque doit être présente à la racine du dépôt. Elle est créée avec `ar`, conformément aux exigences du sujet.

## Algorithme et choix techniques

`ft_printf()` parcourt la chaîne de format caractère par caractère. Lorsqu’il rencontre un caractère ordinaire, il l’écrit directement. Lorsqu’il rencontre `%`, il examine le caractère suivant et sélectionne la fonction adaptée à la conversion demandée. Les fonctions auxiliaires traitent les caractères, les chaînes, les nombres décimaux, les entiers non signés et les valeurs hexadécimales. Pour `%p`, l’adresse est affichée en hexadécimal avec le préfixe approprié.

Cette approche sépare l’analyse du format de l’affichage des valeurs : chaque fonction auxiliaire gère une tâche précise, ce qui rend le code plus facile à tester et à maintenir. Le nombre de caractères écrits est comptabilisé afin que `ft_printf()` renvoie le nombre de caractères affichés, comme la fonction originale. La liste d’arguments variadiques est parcourue avec `va_start`, `va_arg` et `va_end`. Aucune structure de données complexe n’est nécessaire : la chaîne de format et la liste d’arguments suffisent.

## Ressources

- Sujet officiel du projet `ft_printf` de 42.
- Pages de manuel : `printf(3)`, `stdarg(3)`, `write(2)`, `malloc(3)` et `free(3)`.
- Documentation du langage C sur les fonctions variadiques et les conversions numériques.
- Tests personnels comparant les sorties et les valeurs de retour de `ft_printf()` avec celles de `printf()`.

**Utilisation de l’IA :** l’IA a principalement été utilisé pour expliquer les fonctions variadiques, verifier le main de test main.c et leur edge case principalement, et pour les quelque erreur restante.

<br>

##

<br>
<br>

*This project has been created as part of the 42 curriculum by crgrandj.*

# English Version

## Description

`ft_printf` is a project from the 42 curriculum whose goal is to recreate the standard C library function `printf()`. It helps develop an understanding of variadic functions, handling arguments of different types, and converting values into text.

The resulting static library, `libftprintf.a`, contains `ft_printf()` and its helper functions. The mandatory part supports the conversions `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`. Reimplementing the original `printf()` buffer management is not required. The project emphasizes clear code structure, reusable functions, and proper error and memory handling.

## Instructions

### Compilation

From the repository root, run:

```sh
make
```

The Makefile compiles the source files and creates the static library `libftprintf.a`. It uses `-Wall -Wextra -Werror` to treat compiler warnings as errors. The project uses `libft`, its Makefile is run before the final library is created.

Available commands:

```sh
make        # Build the project
make clean  # Remove object files
make fclean # Remove object files and the library
make re     # Rebuild the project from scratch
```

### Usage

To use the library in a C program, include `ft_printf.h` and link `libftprintf.a` during compilation. For example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Number: %d, text: %s\\n", 42, "hello");
    return (0);
}
```

Compile the test program from the repository root:

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf && ./a.out
```

The library must be located at the repository root. It is created with `ar`, as required by the project subject.

## Algorithm and Technical Choices

`ft_printf()` scans the format string one character at a time. Ordinary characters are written directly. When it encounters `%`, it checks the following character and selects the helper function for that conversion. Helper functions handle characters, strings, decimal numbers, unsigned integers, and hexadecimal values. For `%p`, the address is printed in hexadecimal with the appropriate prefix.

This design separates format parsing from value output: each helper function has a specific responsibility, making the code easier to test and maintain. The number of characters written is counted so that `ft_printf()` returns the number of characters printed, like the original function. The variadic argument list is traversed using `va_start`, `va_arg`, and `va_end`. No complex data structure is needed; the format string and argument list are sufficient.

## Resources

- The official 42 `ft_printf` project subject.
- Manual pages: `printf(3)`, `stdarg(3)`, `write(2)`, `malloc(3),` and `free(3)`.
- C language documentation about variadic functions and numeric conversions.
- Personal tests comparing `ft_printf()` output and return values with those of `printf()`.

**Use of AI:** AI may has been used explain variadic functions, verify the main.c to make sure all edge case were done, and help understand error.
