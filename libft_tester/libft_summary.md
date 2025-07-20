
# 📚 Libft - Resumo das Funções

## ✅ ft_atoi
- 📌 Converte uma string em um número inteiro (`int`).
- 🧪 Ex: `"42"` → `42`, `"   -123"` → `-123`
- 🚨 Ignora espaços em branco antes dos números.

## ✅ ft_bzero
- 📌 Zera um bloco de memória (define todos os bytes como 0).
- 🧪 Ex: útil para limpar buffers.
- 🚨 Usa `unsigned char *` internamente.

## ✅ ft_calloc
- 📌 Aloca memória e já inicializa com 0.
- 🧪 Útil para criar arrays zerados.
- 🚨 Proteção contra overflow: `nmemb * size`.

## ✅ ft_isalnum, ft_isalpha, ft_isascii, ft_isdigit, ft_isprint
- 📌 Checam se um caractere pertence a determinada categoria (letra, número, etc).
- 🧪 Ex: `ft_isdigit('3')` → `1`, `ft_isalpha('@')` → `0`.

## ✅ ft_itoa
- 📌 Converte um `int` para uma string.
- 🧪 Ex: `-42` → `"-42"`.
- 🚨 Lida com valores negativos e `INT_MIN`.

## ✅ ft_memchr, ft_memcmp, ft_memcpy, ft_memmove, ft_memset
- 📌 Manipulação de memória:
  - `memchr` → procura um byte
  - `memcmp` → compara blocos
  - `memcpy` → copia blocos
  - `memmove` → copia com segurança para sobreposição
  - `memset` → preenche com um valor

## ✅ ft_putchar_fd, ft_putendl_fd, ft_putnbr_fd, ft_putstr_fd
- 📌 Escrita de caracteres, strings e números em um `file descriptor`.
- 🧪 Útil para redirecionar saídas (ex: arquivos, `stderr` etc).

## ✅ ft_split
- 📌 Divide uma string em várias substrings com base em um separador.
- 🧪 `"bom dia mundo"` com `' '` → `[bom, dia, mundo]`
- 🚨 Lida com múltiplos separadores consecutivos e aloca dinamicamente.

## ✅ ft_strchr, ft_strrchr
- 📌 Localiza a primeira ou última ocorrência de um caractere.

## ✅ ft_strdup
- 📌 Duplica uma string alocando nova memória.

## ✅ ft_striteri, ft_strmapi
- 📌 Aplica uma função a cada caractere da string.
- `striteri` altera a original, `strmapi` cria uma nova.

## ✅ ft_strjoin
- 📌 Junta duas strings alocando uma nova.

## ✅ ft_strlcat, ft_strlcpy
- 📌 Copiam/juntam strings com limite de tamanho (proteção contra overflow).

## ✅ ft_strlen
- 📌 Retorna o comprimento de uma string.

## ✅ ft_strncmp
- 📌 Compara até `n` caracteres de duas strings.

## ✅ ft_strnstr
- 📌 Procura por uma substring dentro de outra, com limite.

## ✅ ft_strtrim
- 📌 Remove caracteres indesejados do início e fim de uma string.

## ✅ ft_substr
- 📌 Extrai uma substring a partir de um índice e tamanho.

## ✅ ft_tolower, ft_toupper
- 📌 Converte letras para minúsculas/maiúsculas.
