# Get Next Line — 42

*This project has been created as part of the 42 curriculum by crgrandj.*

## Français

### Présentation

**Get Next Line (GNL)** est un projet du cursus 42 dont l'objectif est d'implémenter en C une fonction capable de lire un fichier **ligne par ligne**, à partir d'un descripteur de fichier (*file descriptor*). Chaque appel à `get_next_line()` renvoie la ligne suivante, en conservant le caractère `\n` lorsqu'il est présent. La fonction renvoie `NULL` lorsqu'il n'y a plus rien à lire ou en cas d'erreur.

Ce projet permet de travailler la lecture avec `read()`, l'allocation dynamique, la gestion de la mémoire, les variables `static` et les cas limites liés aux fichiers.

### Fonctionnement

La fonction principale possède le prototype suivant :

```c
char *get_next_line(int fd);
```

La lecture s'effectue par blocs de `BUFFER_SIZE` octets. Comme un bloc ne correspond pas nécessairement à une ligne complète, le programme conserve les caractères non encore retournés dans une zone mémoire appelée **stash**.

Le fonctionnement se déroule en trois étapes :

1. **Lire et accumuler** les caractères jusqu'à trouver un saut de ligne ou atteindre la fin du fichier.
2. **Extraire la ligne** à renvoyer, avec son `\n` s'il existe.
3. **Mettre à jour le stash** pour conserver les caractères nécessaires au prochain appel.

Les fonctions utilitaires assurent notamment la recherche du saut de ligne, le calcul des longueurs, la concaténation des chaînes et la libération de la mémoire.

### Partie obligatoire et bonus

La partie obligatoire gère la lecture ligne par ligne avec une variable statique permettant de conserver le texte entre les appels.

La partie bonus étend cette logique à **plusieurs descripteurs de fichier simultanément**. Chaque descripteur dispose de son propre stash, ce qui permet d'alterner les lectures de plusieurs fichiers sans mélanger leurs données.

Les fichiers du projet sont :

- `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h` : partie obligatoire ;
- `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, `get_next_line_bonus.h` : partie bonus.

### Compilation et utilisation

Un programme de test personnel peut appeler `get_next_line()` après avoir ouvert un fichier avec `open()`. Il doit **libérer chaque ligne retournée** avec `free()` et fermer le descripteur avec `close()`.

Compilation de la partie obligatoire avec un fichier de test `main.c` :

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    main.c get_next_line.c get_next_line_utils.c -o gnl_test
./gnl_test
```

Pour le bonus, remplacer les deux fichiers `.c` par leurs versions `_bonus.c` et utiliser le header bonus. `BUFFER_SIZE` peut être modifié à la compilation, par exemple avec `-D BUFFER_SIZE=1`.

### Tests et vérifications

Des tests personnels ont été réalisés avec plusieurs valeurs de `BUFFER_SIZE` (`1`, `2`, `4`, `42` et `10000`). Ils couvrent notamment les fichiers vides, les lignes sans saut de ligne final, les sauts de ligne consécutifs, les longues lignes, la fin de fichier et les descripteurs invalides. Pour le bonus, les tests comprennent des lectures alternées et plusieurs descripteurs ouverts simultanément.

Les vérifications ont également utilisé **Norminette**, **AddressSanitizer** et l'outil macOS `leaks`. Les tests effectués ont réussi, mais ils ne remplacent pas une vérification exhaustive de tous les cas d'erreur, notamment les échecs d'allocation mémoire.

### Utilisation de l'intelligence artificielle

**ChatGPT (OpenAI)** a été utilisé comme **outil d'accompagnement pédagogique**, principalement pour expliquer le rôle du stash et des variables statiques, discuter des choix d'implémentation, relire le code, repérer des erreurs de logique et proposer des cas limites. Il a également aidé à produire des programmes `main.c` de test, à interpréter les résultats de Norminette et des outils de vérification mémoire, ainsi qu'à rédiger et traduire ce README.

L'implémentation de GNL a été développée et ajustée par l'auteur, qui a exécuté les tests et intégré les corrections. L'IA a servi d'assistance à la compréhension et à la vérification, et non de substitut à l'apprentissage du projet.

---

## English

### Overview

**Get Next Line (GNL)** is a 42 curriculum project whose goal is to implement a C function that reads a file **one line at a time** from a file descriptor. Each call to `get_next_line()` returns the next line, including the `\n` character when present. The function returns `NULL` at end of file or on error.

The project focuses on `read()`, dynamic memory allocation, memory management, `static` variables, and file-reading edge cases.

### How it works

The main function has the following prototype:

```c
char *get_next_line(int fd);
```

The program reads chunks of `BUFFER_SIZE` bytes. Since a chunk may contain only part of a line—or several lines—unreturned characters are stored in a persistent buffer called the **stash**.

Each call follows three main steps:

1. **Read and accumulate** data until a newline is found or the file ends.
2. **Extract the next line**, including its newline when present.
3. **Update the stash** to preserve the remaining characters for the next call.

Helper functions handle newline detection, string lengths, string joining, and memory cleanup.

### Mandatory part and bonus

The mandatory implementation reads successive lines while retaining data between calls through a static variable.

The bonus implementation supports **multiple file descriptors at the same time**. Each descriptor has its own stash, allowing calls to alternate between files without mixing their contents.

Project files:

- `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`: mandatory part;
- `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, `get_next_line_bonus.h`: bonus part.

### Compilation and usage

A separate test program can open a file with `open()` and call `get_next_line()` repeatedly. The caller must **free every returned line** and close the file descriptor when finished.

Compile the mandatory part with a local `main.c` test file:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    main.c get_next_line.c get_next_line_utils.c -o gnl_test
./gnl_test
```

For the bonus, compile the `_bonus.c` source files instead and include the bonus header in the test program. The read size can be changed at compilation time, for example with `-D BUFFER_SIZE=1`.

### Testing and validation

Local tests were run using `BUFFER_SIZE` values of `1`, `2`, `4`, `42`, and `10000`. They covered empty files, final lines without newlines, consecutive newlines, long lines, end-of-file behavior, and invalid descriptors. Bonus tests also checked alternating reads and multiple simultaneously open descriptors.

**Norminette**, **AddressSanitizer**, and the macOS `leaks` utility were used during verification. The executed tests passed, although this does not guarantee coverage of every error path, particularly simulated allocation failures.

### Use of artificial intelligence

**ChatGPT (OpenAI)** was used as a **learning and debugging assistant**. Its role included explaining the stash and static variables, discussing implementation decisions, reviewing code, identifying logic mistakes, and suggesting edge cases. It also helped create test `main.c` programs, interpret Norminette and memory-checking output, and draft and translate this README.

The GNL implementation was developed and revised by the author, who ran the tests and applied changes. AI support was used to strengthen understanding and verification rather than replace the learning process.
