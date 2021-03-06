/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:00:17 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/06 19:22:22 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_options(int i, char *av, t_piles *piles)
{
	if (i < 3)
	{
		if ((!ft_strcmp(av, "-v")) && (!piles->v))
			piles->v = 1;
		else if ((!ft_strcmp(av, "-c")) && (!piles->c))
			piles->c = 1;
		else if ((!ft_strcmp(av, "-vc")) && (!piles->c) && (!piles->v))
		{
			piles->v = 1;
			piles->c = 1;
		}
		else if ((!ft_strcmp(av, "-cv")) && (!piles->c) && (!piles->v))
		{
			piles->v = 1;
			piles->c = 1;
		}
		else
			return (0);
		return (1);
	}
	else
		return (0);
}

void	parsing(int ac, char **av, t_piles *piles)
{
	long	i;
	long	*nb;
	t_list	*new;

	i = 1;
	while (i < ac)
	{
		if (check_options(i, av[i], piles))
		{
			i++;
			continue ;
		}
		nb = check_errors(av[i], piles);
		new = ft_lstnew(nb);
		if (!new)
		{
			free(nb);
			print_errors(piles);
		}
		ft_lstadd_back(&piles->a, new);
		piles->len++;
		i++;
	}
}
