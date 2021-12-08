/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 18:05:55 by anonymous     #+#    #+#                 */
/*   Updated: 2021/10/12 17:52:55 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	current = *lst;
	if (current->next != NULL)
		ft_lstclear(&current->next, del);
	del(current->content);
	free(current);
	*lst = 0;
}
