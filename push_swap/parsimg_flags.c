#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s2[i] && s1[i] && s2[i] == s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	init_config(t_config *config)
{
	config->strategy = ADAPTIVE;
	config->bench = 0;
	config->numbers_start = 1;
}

int     is_strategy_flag(char *arg)
{
        if (!arg)
                return (0);
        if (ft_strcmp(arg, "--simple") == 0)
                return (1);
        if (ft_strcmp(arg, "--medium") == 0)
                return (1);
        if (ft_strcmp(arg, "--complex") == 0)
                return (1);
        if (ft_strcmp(arg, "--adaptive") == 0)
                return (1);
        return (0);
}


int	set_strategy(char *arg, t_config *config)
{
	if (!arg || !config)
		return (0);
	if (ft_strcmp(arg, "--simple") == 0)
	{
		config->strategy = SIMPLE;
		return (1);
	}
	else if (ft_strcmp(arg, "--medium") == 0)
	{
		config->strategy = MEDIUM;
		return (1);
	}
	else if (ft_strcmp(arg, "--complex") == 0)
	{
		config->strategy = COMPLEX;
		return (1);
	}
	else if (ft_strcmp(arg, "--adaptive") == 0)
	{
		config->strategy = ADAPTIVE;
		return (1);
	}
	return (0);
}

int	parse_bench(char *arg, t_config *config)
{
	if (!arg || !config)
		return (0);
	if (ft_strcmp(arg, "--bench") == 0)
	{
		config->bench = 1;
		return (1);
	}
	return (0);
}

int	handle_strategy(char *arg, t_config *config,
		int *strategy_selected)
{
	if (*strategy_selected)
		return (0);
	if (!set_strategy(arg, config))
		return (0);
	*strategy_selected = 1;
	return (1);
}

int	handle_bench(char *arg, t_config *config,
		int *bench_selected)
{
	if (*bench_selected)
		return (0);
	if (!parse_bench(arg, config))
		return (0);
	*bench_selected = 1;
	return (1);
}

int	parse_flags(int argc, char **argv, t_config *config)
{
	int	i;
	int	strategy_selected;
	int	bench_selected;

	if (!config || !argv)
		return (0);
	i = 1;
	strategy_selected = 0;
	bench_selected = 0;
	while (i < argc)
	{
		if (is_strategy_flag(argv[i]))
		{
			if (!handle_strategy(argv[i], config,
					&strategy_selected))
				return (0);
		}
		else if (ft_strcmp(argv[i], "--bench") == 0)
		{
			if (!handle_bench(argv[i], config, &bench_selected))
				return (0);
		}
		else
		{
			config->numbers_start = i;
			break ;
		}
		i++;
	}
	return (config->numbers_start < argc);
}
