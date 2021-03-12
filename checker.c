/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:31:31 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/12 15:14:00 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int			get_instruction(char *line)
{
	int			i;
	static char	*list2[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
								"rra", "rrb", "rrr"};

	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp(list2[i], line))
			return (i);
		i++;
	}
	return (-1);
}

void		execute_instructions(t_piles *piles, char **instructions)
{
	int	(*op[11])(t_piles *, int);
	int	ret;
	int x;
	char **str;
	
	op[0] = &swap_a;
	op[1] = &swap_b;
	op[2] = &swap_both;
	op[3] = &push_a;
	op[4] = &push_b;
	op[5] = &rotate_a;
	op[6] = &rotate_b;
	op[7] = &rotate_both;
	op[8] = &reverse_rotate_a;
	op[9] = &reverse_rotate_b;
	op[10] = &reverse_rotate_both;
	str = instructions;
	while (*str)
	{
		x = get_instruction(*str);
		if (x < 0)
			print_errors(piles);
		ret = (*op[x])(piles, 1);
		str++;
	}
}

char	**read_instructions(t_piles *piles)
{
	char	*content;
	char	*tmp;
	char	*line;
	int		ret;
	char	**list;

	ret = 1;
	content = 0;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (ret < 0)
			print_errors(piles);
		tmp = content;
		content = ft_strjoin(content, line);
		free(tmp);
		tmp = content;
		content = ft_strjoin(content, "\n");
		free(tmp);
		free(line);
	}
	list = ft_split(content, '\n');
	if (content)
		free(content);
	return (list);
}

int		main(int ac, char **av)
{
	t_piles	*piles;
	char	**instructions;

	if (ac == 1)
		return (1);
	piles = init_piles();
	parsing(ac, av, piles);
	instructions = read_instructions(piles);
	execute_instructions(piles, instructions);
	if (ascending_order(piles->a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);	
	free_piles(piles);
	return (0);
}
