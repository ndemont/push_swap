/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:00:17 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/03 16:25:21 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_digit(char *str)
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

int     check_integer(long nb)
{
    if (nb < INT_MIN)
        return (0);
    if (nb > INT_MAX)
        return (0);
    return (1);
}

int     is_duplicate(t_list **begin, long nb)
{
    t_list *pile;
    
    if (!begin)
        return (0);
    pile = *begin;
    while (pile)
    {
        if (*(long *)pile->content == nb)
            return (1);
        pile = pile->next;
    }
    return (0);
}

t_list **parsing(int ac, char **av)
{
    long    i;
    long    nb;
    t_list  **pile;
    t_list  *new;
    
    i = 1;
    pile = 0;
    if (ac < 2)
        print_errors(pile);
    printf("parsing\n");
    while (i < ac)
    {
        printf("digit\n");
        if (!check_digit(av[i]))
            print_errors(pile);
        printf("atooi\n");
        nb = ft_atoi(av[i]);
        printf("integer\n");
        if (!check_integer(nb))
            print_errors(pile);
        printf("duplicate\n");
        if (is_duplicate(pile, nb))
            print_errors(pile);
        printf("new\n");
        new = ft_lstnew(&nb);
        if (i == 1)
            pile = &new;
        printf("add\n");
        ft_lstadd_back(pile, new);
        i++;
    }
    return (pile);
}