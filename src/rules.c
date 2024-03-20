/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:32:44 by redrouic          #+#    #+#             */
/*   Updated: 2024/03/14 17:33:10 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"

void	sa(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
	ft_putstr("sa\n");
}

void	pb(t_stack **astack, t_stack **bstack)
{
	t_stack	*tmp;

	if (*astack)
	{
		tmp = *astack;
		*astack = (*astack)->next;
		tmp->next = *bstack;
		*bstack = tmp;
	}
	ft_putstr("pb\n");
}

void	ra(t_stack **stack)
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
	ft_putstr("ra\n");
}

void	rra(t_stack **stack)
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
	ft_putstr("rra\n");
}
