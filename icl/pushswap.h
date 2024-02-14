/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:33:05 by redrouic          #+#    #+#             */
/*   Updated: 2024/02/14 18:17:15 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H

# define FT_PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# define MAX_INT 2147483647
# define MAX_NEG -2147483648

typedef struct	s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

int				ft_strlen(char *str);

long long int	ft_atoi(const char *nptr);

void			ft_putchar(char c);

void			ft_putnbr(int n);

void			print_stack(t_stack *stack);

t_stack			*init_stack(int ac, char **av);

#endif
