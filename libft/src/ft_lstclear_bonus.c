/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:35:06 by tcoze             #+#    #+#             */
/*   Updated: 2023/11/15 20:54:33 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*delete;
	t_list	**tmp;

	tmp = lst;
	while (*tmp != NULL)
	{
		delete = *tmp;
		*tmp = (*tmp)->next;
		ft_lstdelone(delete, del);
	}
}
