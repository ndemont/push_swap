/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:34:04 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/03 16:40:05 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct      s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;

/*libft*/
int	            ft_atoi(const char *str);
void	        ft_lstclear(t_list **lst, void (*del)(void *));
void	        ft_lstadd_back(t_list **alst, t_list *new);
void	        ft_lstadd_front(t_list **alst, t_list *new);
void	        ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	        *ft_lstnew(void *content);
void	        ft_lstiter(t_list *lst, void (*f)(void *));
t_list	        *ft_lstlast(t_list *lst);
int	            ft_lstsize(t_list *lst);
t_list	        *ft_lstdup(t_list *lst, void (*del)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*parsing*/
int     check_digit(char *str);
int     check_integer(long nb);
void    print_errors(t_list **pile);
void    set_zero(void *content);
t_list  **parsing(int ac, char **av);

#endif
