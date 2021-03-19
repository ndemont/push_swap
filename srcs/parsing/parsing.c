/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:00:17 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/19 17:04:59 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	long i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	set_min_max(t_piles *piles, long nb)
{
	if (!piles->len_total)
	{
		piles->min = nb;
		piles->max = nb;
	}
	else
	{
		if (nb > piles->max)
			piles->max = nb;
		if (nb < piles->min)
			piles->min = nb;
	}
}

static int	add_elem(t_piles *piles, long *nb)
{
	t_list	*new;

	new = ft_lstnew(nb);
	if (!new)
	{
		free(nb);
		return (0);
	}
	if (!piles->len_total)
		piles->a = new;
	else
		ft_lstadd_back(&piles->a, new);
	piles->len_total++;
	return (1);
}

static void	set_value(t_piles *piles, char *av)
{
	char	**split;
	long	*nb;
	int		i;

	split = ft_split(av, ' ');
	if (!split)
		return ;
	i = 0;
	while (split && split[i])
	{
		nb = check_errors(split[i], piles);
		set_min_max(piles, *nb);
		if (!add_elem(piles, nb))
		{
			free_split(split);
			print_errors(piles);
		}
		i++;
	}
	free_split(split);
}

void		parsing(int ac, char **av, t_piles *piles)
{
	long	i;

	i = 1;
	while (i < ac)
	{
		if (check_options(i, av[i], piles))
		{
			i++;
			continue ;
		}
		set_value(piles, av[i]);
		i++;
	}
	piles->prev_min = piles->max;
	piles->len_a = piles->len_total;
}
