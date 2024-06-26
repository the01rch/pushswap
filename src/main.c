/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:24:23 by redrouic          #+#    #+#             */
/*   Updated: 2024/05/31 15:47:10 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"

/*
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
		}
		y++;
		x = 0;
	}
	if (sign > 1)
		return (0);
	return (1);
}

*/
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
//	if (!sign_valid(ac, av))
//		return (1);
	while (i < ac)
	{
		while (av[i][j])
		{
			if (!is_format(av[i][j]))
				return (1);
			j++;
		}
		j = 0;
		tmp = ft_atoi(av[i]);
		if (tmp == 0)	
			return (1);
		if (is_double(ac, av, tmp, i))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	**arr;

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
		write(2, "Error\n", 6);
		return (0);
	}
	algo(ac, arr);
	return (1);
}
