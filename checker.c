/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:31:31 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/28 01:23:20 by ndemont          ###   ########.fr       */
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
	int	(*op[11])(t_piles *, int, int);
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
			print_errors(piles, "wrong instructions");
		ret = (*op[x])(piles, 0, piles->fd);
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
		ret = get_next_line(piles->fd, &line);
		if (ret < 0)
			print_errors(piles, 0);
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

int		print_result(t_piles *piles)
{

	if (ascending_order(piles->a))
	{
		if (check_empty(piles->b))
		{
			if (piles->c)
				printf("%sOK%s\n", GREEN, RESET);
			else
				printf("OK\n");
		}
		else
		{
			if (piles->c)
				printf("%sKO%s\n", RED, RESET);
			else
				printf("KO\n");
		}	
	}
	else
	{
		if (piles->c)
			printf("%sKO%s\n", RED, RESET);
		else
			printf("KO\n");
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_piles	*piles;
	char	**instructions;

	piles = NULL;
	if (ac == 1)
		return (1);
	piles = init_piles();
	piles->fd = 0;
	parsing(ac, av, piles);
	if (piles->dst)
		print_errors(piles, "--dst can not be used with push_swap");
	instructions = read_instructions(piles);
	execute_instructions(piles, instructions);
	print_result(piles);
	free_piles(piles);
	return (0);
}
