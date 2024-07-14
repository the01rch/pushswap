/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:24:23 by redrouic          #+#    #+#             */
/*   Updated: 2024/06/17 17:10:28 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"

static int	sign_valid(int ac, char **av)
{
	int	sign;
	int	x;
	int	y;

	sign = 0;
	x = 0;
	y = 1;
	while (y < ac)
	{
		while (av[y][x])
		{
			if (av[y][x] == '-' || av[y][x] == '+')
				sign++;
			x++;
			if (sign > 1)
				return (0);
		}
		sign = 0;
		y++;
		x = 0;
	}
	return (1);
}

static int	is_double(int ac, char **av, int nb, int index)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (i != index && ft_atoi(av[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

static int	gest_err(int ac, char **av)
{
	long long int	tmp;
	int				i;
	int				j;

	i = 1;
	j = 0;
	if (!sign_valid(ac, av))
	{
		ft_putstr("sign valid\n");
		return (1);
	}
	while (i < ac)
	{
		while (av[i][j])
		{
			if (!is_format(av[i][j]))
			{
				ft_putstr("format\n");
				return (1);
			}
			j++;
		}
		j = 0;
		tmp = ft_atoi(av[i]);
		if (tmp == 0)
		{
			ft_putstr("tmp\n");
			return (1);
		}
		if (is_double(ac, av, tmp, i))
		{
			ft_putstr("double\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	main(int ac, char **av)
{
	t_stack *astack;
	t_stack *bstack;
	char	**arr;

	arr = NULL;
	if (ac > 2)
		arr = av;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		arr = str2arr(av[1]);
		if (!arr)
			return (0);
		ac = count_rows(av[1]);
	}
	if (gest_err(ac, arr))
	{
		write(2, "Errorrrr\n", 6);
		free_arr(arr);
		return (0);
	}
	astack = NULL;
	bstack = NULL;
	init_stack(ac, arr, &astack);
	algo(ac, &astack, &bstack);
	free_stack(&astack);
	free(bstack);
	//free_stack(&astack);
	free_arr(arr);
	return (1);
}
