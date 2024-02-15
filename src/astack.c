/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:55:44 by redrouic          #+#    #+#             */
/*   Updated: 2024/02/15 19:37:44 by redrouic         ###   ########.fr       */
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

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_putstr("data: ");
		ft_putnbr(stack->data);
		ft_putchar('\n');
		stack = stack->next;
	}
}	

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
}

void move2b(t_stack *astack, t_stack *bstack)
{
	int	mid;
	int	len;
	int i;

	mid = midpoint(astack);
	i = 0;
	while (1)
	{
		ft_putstr("\n======\n");
		len = stack_len(astack);
		if (len == 3)
			break ;
		if (astack->data < mid)
		{
			pb(&astack, &bstack);
			ft_putstr("\npb\n");
			i++;
		} 
		else if (astack->data >= mid){
			ra(&astack);
			ft_putstr("\nra\n");
		}
		if (i == len / 2)
		{
			i = 0;
			mid = midpoint(astack);
			ft_putstr("midpoint = ");
			ft_putnbr(mid);
			ft_putchar('\n');
		}
		sleep(1);
		ft_putstr("\nbstack=\n");
		print_stack(bstack);
		ft_putstr("\nastack=\n");
		print_stack(astack);
		ft_putstr("\n======\n");
	}
}
