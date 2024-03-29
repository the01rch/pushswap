/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:33:05 by redrouic          #+#    #+#             */
/*   Updated: 2024/03/29 21:57:40 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# define MAX_INT 2147483647
# define MAX_NEG -2147483648

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

int				ft_strlen(char *str);

long long int	ft_atoi(const char *nptr);

void			ft_putchar(char c);

void			ft_putnbr(int n);

void			print_stack(t_stack *stack);

int				midpoint(t_stack *stack);

void			ft_putstr(char *str);

void			move2b(t_stack *astack, t_stack *bstack);

int				stack_len(t_stack *stack);

void			sa(t_stack **stack);

void			pb(t_stack **astack, t_stack **bstack);

void			ra(t_stack **stack);

void			rra(t_stack **stack);

int				is_sorted(t_stack *stack);

char			**str2arr(char *str);

int				count_rows(char *str);

int				is_format(char c);

t_stack			*init_astack(int ac, char **av);

#endif
