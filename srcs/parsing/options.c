/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:35:48 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/20 12:58:05 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_options(int i, char *av, t_piles *piles)
{
	if (i < 2)
	{
		if ((!ft_strcmp(av, "-v")) && (!piles->v))
			piles->v = 1;
		else if ((!ft_strcmp(av, "-c")) && (!piles->c))
			piles->c = 1;
		else if ((!ft_strcmp(av, "-vs")) && (!piles->c))
		{
			piles->v = 1;
			piles->s = 1;
		}
		else if ((!ft_strcmp(av, "-sv")) && (!piles->c))
		{
			piles->v = 1;
			piles->s = 1;
		}
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
		else if ((!ft_strcmp(av, "-svc")) && (!piles->c))
		{
			piles->v = 1;
			piles->c = 1;
			piles->s = 1;
		}
		else if ((!ft_strcmp(av, "-scv")) && (!piles->c))
		{
			piles->v = 1;
			piles->c = 1;
			piles->s = 1;
		}
		else if ((!ft_strcmp(av, "-vcs")) && (!piles->c))
		{
			piles->v = 1;
			piles->c = 1;
			piles->s = 1;
		}
		else if ((!ft_strcmp(av, "-vsc")) && (!piles->c))
		{
			piles->v = 1;
			piles->c = 1;
			piles->s = 1;
		}
		else if ((!ft_strcmp(av, "-cvs")) && (!piles->c))
		{
			piles->v = 1;
			piles->c = 1;
			piles->s = 1;
		}
		else if ((!ft_strcmp(av, "-csv")) && (!piles->c))
		{
			piles->v = 1;
			piles->c = 1;
			piles->s = 1;
		}
		else if ((!ft_strcmp(av, "-src")) && (!piles->src))
		{
			piles->src = 1;
		}
		else if ((!ft_strcmp(av, "-dst")) && (!piles->dst))
		{
			piles->src = 1;
		}		
		else
			return (0);
		return (1);
	}
	return (0);
}


int		check_options2(char **av, int ac, t_piles *piles)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] != '-')
			break ;
		if (!av[i][1])
			break ;
		if ((!ft_strcmp(av[i], "-dst")) && (!piles->dst) && (!piles->src))
		{
			piles->fd = open(av[i + 1], O_CREAT|O_WRONLY|O_TRUNC);
			if (piles->fd < 0)
				print_errors(piles);
			piles->dst = 1;
			i++;
		}
		else if ((!ft_strcmp(av[i], "-src")) && (!piles->src) && (!piles->dst))
		{
			piles->fd = open(av[i + 1], O_RDONLY);
			if (piles->fd < 0)
				print_errors(piles);
			piles->src = 1;
			i++;
		}
		else
		{
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
		}
		i++;
	}
	if (piles->s && !piles->v)
		return (0);
	return (i);
}