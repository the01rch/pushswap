/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:55:44 by redrouic          #+#    #+#             */
/*   Updated: 2024/02/14 18:59:23 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		i;

	i = 1;
	stack = NULL;
	while (i < ac)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->data = ft_atoi(av[i]);
		tmp->next = stack;
		stack = tmp;
		i++;
	}
	return (stack);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr(stack->data);
		ft_putchar('\n');
		stack = stack->next;
	}
}	

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}
