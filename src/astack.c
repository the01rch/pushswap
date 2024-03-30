/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:55:44 by redrouic          #+#    #+#             */
/*   Updated: 2024/03/30 18:44:55 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"

t_stack	*init_astack(int ac, char **av)
{
	t_stack	*astack;
	t_stack	*tmp;
	int		i;

	i = ac - 1;
	astack = NULL;
	while (i > 0)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->data = ft_atoi(av[i]);
		tmp->next = astack;
		astack = tmp;
		i--;
	}
	return (astack);
}

int	is_smallest(t_stack *stack, int value)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->data < value)
		return (1);
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_a(t_stack **astack)
{
	t_stack	*ptr;
	int		smallest;

	if (*astack == NULL || (*astack)->next == NULL)
		return ;
	smallest = (*astack)->data;
	ptr = *astack;
	while (ptr != NULL)
	{
		if (ptr->data < smallest)
			smallest = ptr->data;
		ptr = ptr->next;
	}
	while ((*astack)->data != smallest)
	{
		if ((*astack)->next->data == smallest)
			ra(astack);
		else
			rra(astack);
	}
	if ((*astack)->data > (*astack)->next->data)
		sa(astack);
}

#include <stdio.h>
void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		printf("%d-data: %d\n", i, stack->data);
		stack = stack->next;
		i++;
	}
}

void	move2b(t_stack *astack, t_stack *bstack)
{
	int	mid;
	int	len;
	int	i;

	i = 0;
	mid = midpoint(astack);
	len = stack_len(astack);
	while (1)
	{
		if (len == 3 || len == 0)
			break ;
		if (astack->data < mid)
		{
			pb(&astack, &bstack);
			i++;
		}
		else if (astack->data >= mid && is_smallest(astack, mid))
			rra(&astack);
		else if (astack->data >= mid)
			ra(&astack);
		if ((i == len / 2 && i % 2 == 0) || (i == len / 2 + 1 && i % 2 == 1))
		{
			i = 0;
			mid = midpoint(astack);
			len = stack_len(astack);
		}
		{
			i = 0;
			mid = midpoint(astack);
			len = stack_len(astack);
		}
		{
			i = 0;
			mid = midpoint(astack);
			len = stack_len(astack);
		}
	}
	sort_a(&astack);
	ft_putstr("astack\n");
	print_stack(astack);
	ft_putstr("----------------\n");
	ft_putstr("bstack\n");
	print_stack(bstack);
}
