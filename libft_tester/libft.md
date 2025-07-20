# Libft – Guia Rápido de Estudo

## Parte 1: Funções da libc (reimplementações)

| Função         | Protótipo                                            | Descrição                               |
|----------------|------------------------------------------------------|-----------------------------------------|
| ft_isalpha     | int ft_isalpha(int c)                                | Verifica se é uma letra (A-Z, a-z)      |
| ft_isdigit     | int ft_isdigit(int c)                                | Verifica se é um dígito (0-9)           |
| ft_isalnum     | int ft_isalnum(int c)                                | Letra ou número                         |
| ft_isascii     | int ft_isascii(int c)                                | Valor entre 0 e 127                     |
| ft_isprint     | int ft_isprint(int c)                                | Valor imprimível (32-126)              |
| ft_strlen      | size_t ft_strlen(const char *s)                      | Comprimento da string                   |
| ft_memset      | void *ft_memset(void *s, int c, size_t n)            | Preenche memória com byte `c`          |
| ft_bzero       | void ft_bzero(void *s, size_t n)                     | Zera `n` bytes                          |
| ft_memcpy      | void *ft_memcpy(void *d, const void *s, size_t n)    | Copia memória (sem sobreposição)       |
| ft_memmove     | void *ft_memmove(void *d, const void *s, size_t n)   | Cópia segura (com sobreposição)        |
| ft_strlcpy     | size_t ft_strlcpy(char *d, const char *s, size_t n)  | Cópia segura de string                 |
| ft_strlcat     | size_t ft_strlcat(char *d, const char *s, size_t n)  | Concatenação segura                    |
| ft_toupper     | int ft_toupper(int c)                                | Minúscula para maiúscula               |
| ft_tolower     | int ft_tolower(int c)                                | Maiúscula para minúscula               |
| ft_strchr      | char *ft_strchr(const char *s, int c)                | Primeiro caractere `c` em `s`         |
| ft_strrchr     | char *ft_strrchr(const char *s, int c)               | Último caractere `c` em `s`           |
| ft_strncmp     | int ft_strncmp(const char *s1, const char *s2, n)    | Compara duas strings                  |
| ft_memchr      | void *ft_memchr(const void *s, int c, size_t n)      | Busca byte em memória                 |
| ft_memcmp      | int ft_memcmp(const void *s1, const void *s2, n)     | Compara `n` bytes                     |
| ft_strnstr     | char *ft_strnstr(haystack, needle, len)              | Busca substring                       |
| ft_atoi        | int ft_atoi(const char *nptr)                        | Converte string em int                |
| ft_calloc      | void *ft_calloc(size_t nmemb, size_t size)           | Aloca e zera memória                  |
| ft_strdup      | char *ft_strdup(const char *s)                       | Duplicação de string                  |

---

## Parte 2: Funções adicionais

| Função         | Protótipo                                             | Descrição                                 |
|----------------|-------------------------------------------------------|-------------------------------------------|
| ft_substr      | char *ft_substr(const char *s, unsigned int start, size_t len) | Substring de `s`               |
| ft_strjoin     | char *ft_strjoin(const char *s1, const char *s2)     | Junta duas strings                        |
| ft_strtrim     | char *ft_strtrim(const char *s1, const char *set)    | Remove caracteres de `set`                |
| ft_split       | char **ft_split(const char *s, char c)               | Divide string em tokens                   |
| ft_itoa        | char *ft_itoa(int n)                                 | Int para string                           |
| ft_strmapi     | char *ft_strmapi(const char *s, char (*f)(unsigned int, char)) | Aplica função e cria nova string |
| ft_striteri    | void ft_striteri(char *s, void (*f)(unsigned int, char *)) | Aplica função na string            |
| ft_putchar_fd  | void ft_putchar_fd(char c, int fd)                   | Escreve caractere em fd                   |
| ft_putstr_fd   | void ft_putstr_fd(char *s, int fd)                   | Escreve string em fd                      |
| ft_putendl_fd  | void ft_putendl_fd(char *s, int fd)                  | Escreve string + newline                  |
| ft_putnbr_fd   | void ft_putnbr_fd(int n, int fd)                     | Escreve número                            |

---

## Parte bônus: Listas encadeadas

| Função           | Protótipo                                                   | Descrição                                |
|------------------|-------------------------------------------------------------|------------------------------------------|
| ft_lstnew        | t_list *ft_lstnew(void *content)                            | Cria novo nó                             |
| ft_lstadd_front  | void ft_lstadd_front(t_list **lst, t_list *new)             | Adiciona no início                       |
| ft_lstsize       | int ft_lstsize(t_list *lst)                                 | Conta nós                                |
| ft_lstlast       | t_list *ft_lstlast(t_list *lst)                             | Último nó                                |
| ft_lstadd_back   | void ft_lstadd_back(t_list **lst, t_list *new)              | Adiciona no fim                          |
| ft_lstdelone     | void ft_lstdelone(t_list *lst, void (*del)(void *))         | Libera conteúdo + nó                     |
| ft_lstclear      | void ft_lstclear(t_list **lst, void (*del)(void *))         | Limpa lista                              |
| ft_lstiter       | void ft_lstiter(t_list *lst, void (*f)(void *))             | Aplica f no conteúdo                     |
| ft_lstmap        | t_list *ft_lstmap(t_list *lst, f, del)                      | Nova lista com transformação             |

# teste com valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./binario
