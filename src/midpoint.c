/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:41:04 by redrouic          #+#    #+#             */
/*   Updated: 2024/03/14 17:01:57 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"

int	*create_arr(int size, t_stack *stack)
{
	int	*new;
	int	i;

	new = malloc(sizeof(int) * size - 1);
	if (!new)
		return (0);
	i = 0;
	while (stack)
	{
		new[i] = stack->data;
		stack = stack->next;
		i++;
	}
	return (new);
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

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

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	midpoint(t_stack *stack)
{
	int	*new;	
	int	mid;
	int	len;

	new = NULL;
	len = stack_len(stack);
	new = create_arr(len, stack);
	sort_arr(new, len);
	mid = new[(len / 2)];
	free(new);
	return (mid);
}
