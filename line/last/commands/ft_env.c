#include "../minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		ft_putendl_fd(envp[i], 1);
	}
	return (0);
}
