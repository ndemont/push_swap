/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:02:30 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/23 21:22:11 by ndemont          ###   ########.fr       */
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

int		check_duplicate(t_piles *piles, long n2)
{
	t_list	*pile;
	long	n1;

	if (!piles)
		return (0);
	if (piles->len_total < 2)
		return (0);
	pile = piles->a;
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
		return (0);
	nb = (long *)malloc(sizeof(long));
	if (!nb)
		return (0);
	*nb = ft_atol(av);
	if (!check_integer(*nb))
	{
		free(nb);
		return (0);
	}
	if (check_duplicate(piles, *nb))
	{
		free(nb);
		return (0);
	}
	return (nb);
}

void	print_errors(t_piles *piles, char *error)
{
	write(2, "Error: ", 8);
	if (error)
		write(2, error, ft_strlen(error));
	else
		write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	free_piles(piles);
	exit(1);
}
