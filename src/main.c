/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:24:23 by redrouic          #+#    #+#             */
/*   Updated: 2024/02/06 18:40:02 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
	int				nb_sign;

	b = 0;
	sign = 1;
	nb_sign = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nb_sign++;
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
		if (*str >= '0' && *str <= '9') 
			(void)str;
		else
			return (0);
		str++;
	}
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
