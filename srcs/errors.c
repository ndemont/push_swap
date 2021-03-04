/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:02:30 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/04 11:48:38 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_digit(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		check_integer(long nb)
{
	if (nb < INT_MIN)
		return (0);
	if (nb > INT_MAX)
		return (0);
	return (1);
}

int		check_duplicate(t_list **begin, long n2)
{
	t_list	*pile;
	long	n1;

	if (!begin)
		return (0);
	pile = *begin;
	while (pile)
	{
		n1 = *(long *)pile->content;
		if (n1 == n2)
			return (1);
		pile = pile->next;
	}
	return (0);
}

long	*check_errors(char *av, t_piles *piles)
{
	long	*nb;

	if (!check_digit(av))
		print_errors(piles);
	nb = malloc(sizeof(long));
	if (!nb)
		print_errors(piles);
	*nb = ft_atoi(av);
	if (!check_integer(*nb))
		print_errors(piles);
	if (check_duplicate(piles->a, *nb))
		print_errors(piles);
	return (nb);
}

void	print_errors(t_piles *piles)
{
	write(2, "Error\n", 6);
	free_piles(piles);
	exit(1);
}
