/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:55:44 by redrouic          #+#    #+#             */
/*   Updated: 2024/07/10 18:32:17 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"
#include <stdio.h>

void free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (stack)
	{
		while ((*stack) != NULL)
		{
			tmp = *stack;
			(*stack) = (*stack)->next;
			free(tmp);
		}
	}
}

void	init_stack(int ac, char **av, t_stack **astack)
{
	t_stack	*tmp;
	int		i;

	i = ac - 1;
	while (i > -1)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->data = ft_atoi(av[i]);
		tmp->next = *astack;
		*astack = tmp;
		i--;
	}
}

static int	is_smallest(t_stack *stack, int value)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->data < value)
		return (1);
	return (0);
}

int	is_sorted(t_stack *stack, int len)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (i < len && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	move2b(t_stack **astack, t_stack **bstack, int len)
{
	int	mid;
	int	size;
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	size = len;
	if (size > 2)
		mid = midpoint(*astack, len);
	while (size > 2)
	{
		if ((*astack)->data < mid)
		{
			push(astack, bstack, 'b');
			i++;
		}
		if ((*astack)->data >= mid)
		{
			if (is_smallest(*astack, mid))
			{
				rev_rotate(astack, 'a');
				cnt--;
			}
			else
			{
				rotate(astack, 'a');
				cnt++;
			}
		}
		if (i == size / 2)
		{
			size -= i;
			i = 0;
			if (size > 2)
				mid = midpoint(*astack, size);
		}
	}
	return (cnt);
}
