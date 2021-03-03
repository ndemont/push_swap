/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:02:30 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/03 16:47:41 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    set_zero(void *content)
{
    content = 0;
}

void    print_errors(t_list **pile)
{
    write(2, "Error\n", 6);
    ft_lstclear(pile, &set_zero);
    exit (1);
}