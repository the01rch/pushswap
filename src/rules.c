/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:32:44 by redrouic          #+#    #+#             */
/*   Updated: 2024/04/05 01:36:34 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"

static void	print_ab(char c, char *s1, char *s2)
{
	if (c == 'a')
	{
		ft_putstr(s1);
		ft_putchar('\n');
	}
	else if (c == 'b')
	{
		ft_putstr(s2);
		ft_putchar('\n');
	}
}

void	swap(t_stack **stack, char c)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
	print_ab(c, "sa", "sb");
}

void	push(t_stack **stack1, t_stack **stack2, char c)
{
	t_stack	*tmp;

	if (*stack1)
	{
		tmp = *stack1;
		*stack1 = (*stack1)->next;
		tmp->next = *stack2;
		*stack2 = tmp;
	}
	print_ab(c, "pa", "pb");
}

void	rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		tmp2 = *stack;
		while (tmp2->next)
			tmp2 = tmp2->next;
		*stack = tmp->next;
		tmp2->next = tmp;
		tmp->next = NULL;
	}
	print_ab(c, "ra", "rb");
}

void	rev_rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		tmp2 = *stack;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp2->next->next = tmp;
		*stack = tmp2->next;
		tmp2->next = NULL;
	}
	print_ab(c, "rra", "rrb");
}
