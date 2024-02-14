/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:41:04 by redrouic          #+#    #+#             */
/*   Updated: 2024/02/14 17:54:31 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"

int *create_arr(int ac, char **av)
{
	int *new;
	int	i;

	new = malloc(sizeof(int) * ac - 1);
	if (!new)
		return (0);
	i = 1;
	while (i < ac)	
	{
		new[i-1] = ft_atoi((const char *)av[i]);
		i++;
	}
	return (new);	
}

void	sort_arr(int *arr, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	midpoint(int ac, char **av)
{
	int	*new;	
	int	mid;
	
	new = create_arr(ac, av);
	sort_arr(new, ac);
	mid = new[(ac/2) -1];
	free(new);	
	return (mid);
}
