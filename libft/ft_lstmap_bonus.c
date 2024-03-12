/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:34:58 by tcoze             #+#    #+#             */
/*   Updated: 2023/11/15 20:58:45 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*templst;
	void	*temp;

	new = NULL;
	while (lst)
	{
		temp = f(lst->content);
		if (!temp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		templst = ft_lstnew(temp);
		if (!templst)
		{
			del(temp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new, templst);
	}
	return (new);
}
