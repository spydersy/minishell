clear && clang -Wall -Werror -Wextra  -g3 -fsanitize=address *.c ./*/*.c  -o minishell && ./minishell
