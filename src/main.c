/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:24:23 by redrouic          #+#    #+#             */
/*   Updated: 2024/02/06 20:26:18 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define MAX_INT 2147483647
#define MAX_NEG -2147483648

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long long int	ft_atoi(const char *nptr)
{
	long long int	b;
	int				sign;

	b = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		b = b * 10 + (*nptr - 48);
		nptr++;
	}
	return (b * sign);
}

int	is_digit(char *str)
{
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || *str == '-' || *str == '+') 
			(void)str;
		else
			return (0);
		str++;
	}
	return (1);
}

int	sign_valid(int ac, char **av)
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

int	is_double(int ac, char **av, int nb, int index)
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

int	gest_err(int ac, char **av)
{
	long long int	tmp;
	int				i;

	i = 1;
	if (!sign_valid(ac, av))
		return (1);
	while (i < ac)		
	{
		if (is_digit(av[i]) == 0)
			return (1);
		tmp = ft_atoi(av[i]);
		if (tmp > MAX_INT || tmp < MAX_NEG)
			return (1);
		if (is_double(ac, av, tmp, i))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (gest_err(ac, av) == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (0);
}
