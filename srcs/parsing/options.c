/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:35:48 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/21 20:47:37 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_dst(char **av, t_piles *piles, int i)
{
	if ((!ft_strcmp(av[i], "-dst")) && (!piles->dst) && (!piles->src))
	{
		piles->fd = open(av[i + 1], O_CREAT | O_WRONLY | O_TRUNC);
		if (piles->fd < 0)
			print_errors(piles, 0);
		piles->dst = 1;
		return (1);
	}
	return (0);
}

int		check_src(char **av, t_piles *piles, int i)
{
	if ((!ft_strcmp(av[i], "-src")) && (!piles->src) && (!piles->dst))
	{
		piles->fd = open(av[i + 1], O_RDONLY);
		if (piles->fd < 0)
			print_errors(piles, 0);
		piles->src = 1;
		return (1);
	}
	return (0);
}

int		check_vcs(char **av, t_piles *piles, int i)
{
	int j;

	j = 1;
	while (av[i][j])
	{
		if (av[i][j] == 'v' && (!piles->v))
			piles->v = 1;
		else if (av[i][j] == 'c' && (!piles->c))
			piles->c = 1;
		else if (av[i][j] == 's' && (!piles->s))
			piles->s = 1;
		else
			return (0);
		j++;
	}
	return (1);
}

int		check_options(char **av, int ac, t_piles *piles)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] != '-')
		{
			if (piles->s && !piles->v)
				return (0);
			return (i);
		}
		if (!av[i][1])
			return (0);
		if (check_dst(av, piles, i))
			i += 2;
		else if (check_src(av, piles, i))
			i += 2;
		else if (check_vcs(av, piles, i))
			i++;
		else
			return (0);
	}
	if (piles->s && !piles->v)
		return (0);
	return (i);
}
