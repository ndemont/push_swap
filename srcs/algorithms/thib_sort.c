/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thib_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:15:55 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/18 23:02:10 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int         find_min_lowest(t_list *list, int lowest, int highest)
{
    int new;
    int nb;

    new = highest;
    while (list)
    {
        nb = *(long *)list->content;
        if (nb > lowest && nb < new)
            new = nb;
        list = list->next;
    }
    return (new);
}

long       find_mediane(int values, int lowest, t_piles *piles)
{
    int count;

    count = 0;
    while (count < values - 1)
    {
        lowest = find_min_lowest(piles->a, lowest, piles->max);
        count++;
    }
    return (lowest);
}

void       set_steps(t_piles *piles)
{
    int     div;
    int     mod;
    int     values;
    int     lowest;
    int     i;

    div = piles->len_total / 50;
    mod = piles->len_total % 50;
    piles->steps = div;
    if (mod || !piles->steps)
        piles->steps++;
    piles->mediane = malloc(sizeof(long) * piles->steps);
    if (!piles->mediane)
        print_errors(piles);
    piles->mediane[piles->steps - 1] = piles->max;
    i = 0;
    lowest = piles->min;
    while (i < piles->steps - 1)
    {
        if (i == 0)
			values = piles->len_total / piles->steps + (piles->len_total % piles->steps); 
		else
			values = piles->len_total / piles->steps;
        piles->mediane[i] = find_mediane(values, lowest, piles);
        lowest =  piles->mediane[i] + 1;
        i++;
    }
}

void     find_position(t_list *pile, int *pos_min, int *pos_max)
{
    t_list  *list;
    long    nb;
    int     min;
    int     max;
    int     i;

    list = pile;
    i = 0;
    if (list)
    {
        nb = *(long *)list->content;
        min = nb;
        max = nb;
        *pos_min = i;
        *pos_max = i;
        list = list->next;
        i++;
    }
    while (list)
    {
        nb = *(long *)list->content;
        if (nb < min)
        {
            min = nb;
            *pos_min = i;
        }
        else if (nb > max)
        {
            max = nb;
            *pos_max = i;
        }
        i++;
        list = list->next;
    }
}

int     count_moves(int pos, int len, int *direction)
{
    int moves;

    if (pos < len / 2)
    {
        moves = pos;
        *direction = 0;
    }
    else
    {
        moves = len - pos;
        *direction = 1;
    }
    return (moves);
}

void    thib_sort(t_piles *piles)
{
    int count;
    int remaining;
    int moves_min;
    int moves_max;
    int check;
    int i;
    int j;
    int k;
    int pos_min;
    int pos_max;
    int dir_min;
    int dir_max;

    set_steps(piles);
    i = 0;
	count = piles->len_total;
    while (i < piles->steps)
    {   
		remaining = 0;
        j = count;
		while (j)
        {
            if (*(long *)piles->a->content <= piles->mediane[i])
                push_b(piles, 1);
            else 
                rotate_a(piles, 1);
            j--;
        }
		count = piles->len_total;
		if (i != 0 && i != piles->steps -1)
		{
			j = piles->mediane[i - 1];
			k = piles->len_total - piles->mediane[i];
			if (j < k)
			{
				while (j > 0)
				{
					rotate_a(piles, 1);
					j--;
				}
			}
			else
			{
				while (k > 0)
				{
					reverse_rotate_a(piles, 1);
					k--;
				}
			}
		}
        while (piles->b)
        {
            find_position(piles->b, &pos_min, &pos_max);
            check = 0;
            moves_min = count_moves(pos_min, piles->len_b, &dir_min);
            moves_max = count_moves(pos_max, piles->len_b, &dir_max);
            if (moves_min < moves_max)
            {
                while (moves_min > 0)
                {
                    if (!dir_min)
                        rotate_b(piles, 1);
                    else
                        reverse_rotate_b(piles, 1);
                    moves_min--;
                }
                check = 1;
            }
            else
            {
                while (moves_max > 0 )
                {
                    if (!dir_max)
                        rotate_b(piles, 1);
                    else
                        reverse_rotate_b(piles, 1);
                    moves_max--;
                }
                remaining++;
            }
            push_a(piles, 1);
            if (check && piles->len_a > 1)
                rotate_a(piles, 1);
        }
		count = piles->len_total - piles->mediane[i];
        while (i < (piles->steps - 1) && remaining)
        {
            rotate_a(piles, 1);
            remaining--;
        }
        i++;
	}
	put_min_first(piles);
}